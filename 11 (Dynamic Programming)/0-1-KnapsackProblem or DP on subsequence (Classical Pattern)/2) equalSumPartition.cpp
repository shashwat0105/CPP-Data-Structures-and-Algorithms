// https://www.geeksforgeeks.org/partition-problem-dp-18/
// https://leetcode.com/problems/partition-equal-subset-sum/


// problem statement
// arr[] : {1, 5, 11, 5} :- Is it possible to split the array in two (equal or unequal) parts such that the sum of the two subsets is equal. 
// O/P = T/F :- True if such partition is possible else false

// Sum of P1 = S1 = S, Sum of P2 = S2 = S -> Sum of array = 2S which is even,then only it is possible to do equal partition
// In above case sum = 22, hence our ques reduces to if there exists any subset whose sum is 11 (Sum/2) {Subset Sum Problem}

// Code
// Finding array sum (in above example it is 22)
int sum = 0;
for(int i = 0; i < size; i++){
    sum = sum + arr[i];
}
if(sum%2 !=0){  // i.e. when sum of array is odd 
    return false;  
}
if(sum%n ==0){  // i.e. when sum of array is even
    return subsetSum(arr, Sum/2, n);
}


// **********************************************************

// *****************************************************************************************
// COMPLETE WORKING CODE
class Solution {
public:
    bool solve(int ind, int target, vector<int> &nums, vector<vector<int>>&dp){
        if(target==0) return true;
        if(ind==0) return target == nums[0];
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool notTake = solve(ind-1, target, nums, dp);
        bool take = false;
        if(nums[ind]<=target) take = solve(ind-1, target-nums[ind], nums, dp);
        return dp[ind][target] = take||notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;  // if sum is odd
        sum = sum/2;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return solve(n-1, sum, nums, dp);
    }
};
