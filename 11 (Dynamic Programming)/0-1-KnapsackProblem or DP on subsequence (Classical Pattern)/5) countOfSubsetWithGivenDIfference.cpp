// DP on subsequence

// And the sum of subsets must add to sum of the array, else the below approach wont work.

// Problem statement arr[] : {1, 1, 2, 3}, difference = 1  // these are different 1's
// O/P :- 3 -> {{1,2},{1,3}}, {{1,2},{1,3}}, {{1,1,2},{3}} = No. of pair of subsets whose difference of sum is 1 ie (S2 - S1 = 1) 
// S2 - S1 = diff -> (i)
// S2 + S1 = Sum of array -> (ii)
// Adding (i) & (ii)
// S2 = (diff + Sum of array)/2
// diff is given in ques, sum of array could be found
// Hence our problem is reduced to find no of subsets whose sum is (1+7)/2 = 4, which is nothing but count of subset sum problem(Wow)

int sum = diff + (Sum of array - diff)/2;   // = (s+d)/2

return countOfSubsetSum(arr, sum);



// https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628

// Handling the case when  subset has 0's as well.

// Memoised

int mod = (int)(1e9+7);
int solve(int ind, int sum, vector<int> &num, vector<vector<int>> &dp){
    
    if(ind==0){                                // To handle 0's in memoised code.
        if(sum==0 && num[0]==sum) return 2;    
        if(sum==0 || sum==num[0]) return 1;
        return 0;
    }

    if(dp[ind][sum]!= -1) return dp[ind][sum];
    
    int notTake = solve(ind-1, sum, num, dp);
    int take = 0;
    if(num[ind]<=sum) take = solve(ind-1, sum-num[ind], num, dp);
    return dp[ind][sum] = (notTake + take)%mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totSum = 0;
    for(auto it: arr){
        totSum+=it;
    }

    //Checking for edge cases
    if(totSum-d<0 || (totSum-d) % 2) return false;
    int target = (totSum-d)/2;
    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    return solve(n-1, target, arr, dp);
}

// Tabulated

// Space optimised

int solve(vector<int> &num, int tar){
    int n = num.size();
    vector<int> prev(tar+1, 0), cur(tar+1, 0);
    if(num[0]==0) prev[0] = 2;
    else prev[0] = 1;

    if(num[0]!= 0 && num[0]<=tar) prev[num[0]] = 1;
    for(int ind = 1; ind<n; ++ind){
        for(int sum = 0; sum<=tar; ++sum){
            int notTake = prev[sum];
            int take = 0;
            if(num[ind]<=sum) take = prev[sum-num[ind]];

            cur[sum] = take + notTake;
        }
        prev = cur;
    } 
    return prev[tar];
}

int countPartition(int n, ind d, vector<int> &arr){
    int totSum = 0;
    for(auto &it: arr) totSum += it;
    if(totSum - d < 0 || (totSum - d)%2) return false;
    return solve(arr, (totSum-d)/2);
}

