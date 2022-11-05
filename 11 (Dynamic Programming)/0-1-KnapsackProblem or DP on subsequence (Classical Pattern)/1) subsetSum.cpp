// DP on subsequence

// NOTE: Tabulation only works for +ve array numbers as if sum is -ve in matrix -ve index is not possible.
// Hash map could be used for -ve numbers


// https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
// Example arr[] = {2, 3, 7, 8, 10} & Sum = 11 // We want to find if there is any subset whose sum is given Sum (True or False)
// We have choice whether a number will be included or not & here W = Sum 
// Hence on slight variation in knapsack we can achieve code of this.

// Base condition(Initiliasation)
// Table of t[5+1][11+1] is made 
// The first column says Sum required is 0 and Array elements proceed as { }, {2}, {2,3},.. True it is possible to have sum of 0 using such arrays when everytime we take empty set as the required subset { }
// The first row says the array is empty ie { } and sum required is 0, 1, 2, ...,11, which is possible to satisfy only in sum 0, hence rest is false.
//   0  1 2 3 4 5 6 7 8 9 10 11 12  -> j(Sum) (Columns)
// 0 T  F F F F F F F F F  F  F  F    (zero elements ka use karke sum banana hai) ie why I will return t[n]
// 1 T
// 2 T
// 3 T
// 4 T
// 5 T
// i(n) ie no of elements (Row)

// Choice diagram
// Analogy with 0/1 knapsack wt[] -> arr[] -> i, val[] is ignored & W -> Sum -> j, max is changed to || or (coz no sense of max(true, false))

// code
boolean subsetSum(int arr[], int Sum, int n){
    
    bool t[n+1][Sum+1];                                    // bool or int(while counting) depending on value to be stored

    // base condition
    for(int i=0; i<=n; i++){
        t[i][0]=true;                                      // initilising the leftmost column
    }
    for(int j=1; j<=Sum; j++){                             // start from 1: // Initialize top row, except dp[0][0], as false. With  0 elements, no other sum except 0 is possible
        t[0][j]=false;                                     // initilising the topmost row
    } 
    // Choice Diagram     // Fill the subset table in bottom up manner
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= Sum; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j]; // Either we include or not include // true || false // In knapsack in place of weight we were subtracting the weight which was included, here we are subtracting the number which is included from Sum.
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][Sum];                                      // the right bottom most cell of the table
}

// *** Dont use two for loops for base condition sometimes works sometimes dont, above works well

// NOTE: This code works only for positive numbers in the array.


// This is a subarray not a subset.
// https://www.geeksforgeeks.org/find-subarray-with-given-sum-in-array-of-integers/   (Deals Negative Numbers too) use of hasmap.


// ***********************************************************

// 1) Express (index, target) and write the base case
// 2) Explore all possibilities.
// 3) Return T/F

// Memoised

bool solve(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target==0) return true;
    if(ind == 0) return (target== arr[0]);
    
    if(dp[ind][target]!= -1) return dp[ind][target];
    
    if(arr[ind]<=target){   // I can choose to pick or not pick
        return dp[ind][target] = solve(ind-1, target, arr, dp) || solve(ind-1, target-arr[ind], arr, dp);
    }
    else{                  // I cannot pick
        return dp[ind][target] = solve(ind-1, target, arr, dp);
    }
}

// Alternate piece of code
// bool notTake = solve(ind-1, target);
// bool take = false;
// if(arr[ind]<=target) take = solve(ind-1, target-arr[i]);
// return take||notTake

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return solve(n-1, k, arr, dp);
}


// Tabulated the above code
// Here 0 elements case is not considered.

bool isSubsetSum(vector<int>arr, int sum){
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(sum+1, 0));
    for(int i=0; i<n; ++i) dp[i][0] = true; // first base case // target of 0 is possible with any number of elements.
    if(arr[0]<=sum) dp[0][arr[0]] = true;   // second base case // ie only one array element is to be used to make the sum and hence that cell will be true which is equal to target
                                            // Simply saying that, jo array ka first index ki value hai wo sum hona toh possible hoga hi.
                                            // if condition because dp size is sum+1, otherwise it will go out of bound
    for(int ind = 1; ind<n; ++ind){
        for(int target=1; target<=sum; ++target){    // We start from 1 when arr[i]>=1 is given, if there are 0's then we start from 0.
            bool notTake = dp[ind-1][target];
            bool take = false;
            if(arr[ind]<=target) take = dp[ind-1][target-arr[ind]];
            dp[ind][target] = take | notTake;
        }
    }
    return dp[n-1][sum];   
}

//  Space optimised

bool isSubsetSum(vector<int>arr, int sum){
    int n = arr.size();
    vector<bool> prev (sum+1,0);
    vector<bool> cur (sum+1, 0);
    prev[0] = true; // first base case     // for anyone target sum of 0 has to be true
    if(arr[0]<=sum) prev[arr[0]] = true;                   // second base case  // some array element will be marked as true.
    
    for(int ind = 1; ind<n; ++ind){
        for(int target=1; target<=sum; ++target){
            bool notTake = prev[target];
            bool take = false;
            if(arr[ind]<=target) take = prev[target-arr[ind]];
            cur[target] = take | notTake;
        }
        prev = cur;
    }
    return prev[sum];
}

// Space optimised is failinng on (TO DISCUSS)
37 34 4 12 5 2
17
