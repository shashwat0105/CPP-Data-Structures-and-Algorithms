// https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/
// Problem Statement :- Given arr[] ={2, 3, 5, 6, 8, 10}, Sum = 10
// To return count of such subsets possible with Sum = 10, If true as here {10}, {2,3,5}, {2,8} -> return = 3(>0), if false(no such subset) then return 0
// return type of subset sum = boolean (coz true or false)
// return type of count of subset sum = int (if true then count, false then 0)
// t[n+1][Sum+1] Here t[6+1][10+1]
//       0  1     2    3    4    5    6    7    8    9    10   11  -> j(Sum)
// 0 | 1(T)  0(F) 0(F) 0(F) 0(F) 0(F) 0(F) 0(F) 0(F) 0(F) 0(F)   
// 1 | 1(T)
// 2 | 1(T)
// 3 | 1(T)
// 4 | 1(T)
// 5 | 1(T)
// 6 | 1(T)
// 7 | 1(T)
// i(n)
// Similarity from subset sum, the first column was true and only { } null set was solution hence count = 1 
// In choice diagram || is replaced by + (coz not true false), boolean by int (coz not true false)

// code
int countOfSubsetSum(int arr[], int Sum, int n){
    
    int t[n+1][Sum+1];

    // base condition
    for(int i=0; i<=n; i++){
        t[i][0]=1;                                       // This is 1 not 0.
    }
    for(int j=1; j<=Sum; j++){                           // Using 0 elements there is no sum possible 
        t[0][j]=0;
    } 
    // Choice Diagram
    for(int i=1; i<=n; i++){
        for(int j=1; j<=Sum; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j]; // Either we include or not include, just replaced || by + 
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][Sum];  // the right bottom most cell of the table
}


//  ********************** Striver

// // Also you need to see the subset contains zeros or not. Here in this problem YES.


// Memoised
int solve(int ind, int sum, vector<int> &num, vector<vector<int>> &dp){
    // if(sum==0) return 1;   // This cannot be the base case bcz even if the sum is 0, it can be due to {0} {0 0} etc 
    if(ind==0){                                // To handle 0's in memoised code.
        if(sum==0 && sum==num[0]) return 2;    // ie there are 2 solns take and not take and both are correct. Remaining sum is 0 and the only element to be used is also 0
        if(sum==0 || sum==num[0]) return 1;    // sum is say 5 and equal to only element 5 then just take it. Hence 1 case
        return 0; 
    }

    if(dp[ind][sum]!= -1) return dp[ind][sum];
    
    int notTake = solve(ind-1, sum, num, dp);
    int take = 0;
    if(num[ind]<=sum) take = solve(ind-1, sum-num[ind], num, dp);
    return dp[ind][sum] = notTake + take;
}

int findWays(vector<int> &num, int tar){
    // Write your code here
    int n = num.size();
    vector<vector<int>>dp(n, vector<int>(tar+1, -1));
    return solve(n-1, tar, num, dp);
}


// Tabulated 
int findWays(vector<int> &num, int tar){
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, 0));  // n moves from 0 to n-1, tar moves from 1 to tar
    
    if(num[0]==0) dp[0][0]=2;
    else dp[0][0] = 1;

    // num[0]=0
    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;

    for(int ind=1; ind<n; ++ind){
        for(int sum=0; sum<=tar; ++sum){    // why here sum is starting from 0 // It will start from 0 to handle the case in which subset contains 0's. For Eg. {2, 3, 0, 5, 0, 8, 10, 0}.
            int notPick = dp[ind-1][sum];
            int pick = 0;
            if(num[ind]<=sum) pick = dp[ind-1][sum-num[ind]];
            dp[ind][sum] = pick + notPick;
        }
    }
    return dp[n-1][tar];
}


// Space optimised

int findWays(vector<int> &num, int tar){
    // Write your code here.
    int n = num.size();
    vector<int> prev(tar+1, 0);  // n moves from 0 to n-1, tar moves from 1 to tar
    vector<int> cur(tar+1, 0);
    
    if(num[0]==0) prev = 2;
    else prev[0] = 1;
    if(num[0]!= 0 && num[0]<= tar) prev[num[0]] = 1;
    
    for(int ind=1; ind<n; ++ind){
        for(int sum=0; sum<=tar; ++sum){    // why here sum is starting from 0 // Ans: It will start from 0 to handle the case in which subset contains 0's. For Eg. {2, 3, 0, 5, 0, 8, 10, 0}.
            int notPick = prev[sum];
            int pick = 0;
            if(num[ind]<=sum) pick = prev[sum-num[ind]];
            cur[sum] = pick + notPick;
        }
        prev = cur;
    }
    return prev[tar];
}

// Handling 0's in the set
// {0, 0, 1}
// There are 4 solns {0 1} {0 1} {0 0 1} {1} 
// So, we can either multiply by number of ways we can represent zero ie {0} {0} {0 0} {} and multiply with normal ans ie 4*1 = 4
