// DP on subsequence

// Problem statement arr[] : {1, 1, 2, 3}, Sum = 1, We need to put + or - sign before element of array and get the sum = 1
// For ex:- +1-1-2+3 = 1 , -1+1-2+3 = 1, +1+1+2-3 = 1, & then count the number of such combos, Here O/P = 3
// Now:- +1-1-2+3 = (+1+3)-(+1+2) -> Same as difference of sum of 2 subsets.
// Hence our problem reduced to Count Of Subset With Given Difference problem (WOW). Diff of that prob is named as sum here, thats it!
// Just the way of asking is different ans is exact same!


// But But But
// CORNER CASE:
// Here the numbers can be zero as well. Hence +0, -0 will also be counted. (Corner Case)
// [0,0,0,0,0,0,0,0,1]
// 1
// Output: 1
// Expected: 256

Soln:
// Method 1: Bottom Up
class Solution {
public:
    int countOfSubsetSum(vector<int>& nums, int targetSum){
        int n = nums.size();
        int t[n+1][targetSum+1];
        
        for(int i=0; i<=n; ++i){
            t[i][0] = 1;            // sum of 0 is possible
        }
        
        for(int j=1; j<=targetSum; ++j){
            t[0][j] = 0;                    // sum with n = 0 is not possible
        }
        
        for(int i=1; i<=n; ++i){
            for(int j=0;j<=targetSum; ++j){                     //NOTE: (We used to start from j=1) // Starting j from 0 because 0's are considered as valid for this problem. // To deal with that failed case. (Because range of the sum includes 0 ie .  Ex - If all the elements are 0 and we want a sum 0, for that we need j from 0. So that 0 can also be considered as sum of previous subset of i elements.)
                if(nums[i-1] <= j){
                    t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][targetSum];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        target = abs(target);  // as target can be negative (see constraints)
        int n = nums.size();
        int arraySum = 0;
        for(int i =0; i<n; ++i){
            arraySum+= nums[i];            
        }
                
        if(arraySum < target || (arraySum+target)%2!=0) return 0;   // total sum of the array is less than target sum
        
        int targetSum = (arraySum + target)/2;
        
        return countOfSubsetSum(nums, targetSum);
    }
};


// Method 2: Bottom Up, slight change to handle the corner case.
// Other way to deal the edge case of 0 ie by counting the number of zeroes.

class Solution {
public:
    int findS(vector<int>& nums, int sumF, vector<vector<int>> dp, int n){
        for(int i=0; i<=n; i++)
            dp[i][0] = 1;
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=sumF; j++)
            {
                if(nums[i-1] <= j && nums[i-1]!=0)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sumF];
    }
    int findTargetSumWays(vector<int>& nums, int target) {   
        target = abs(target);
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(), 0);
        if(target > sum || (sum+target)%2 !=0 )return 0;
        
        int sumF = (target+sum)/2;
        vector<vector<int>> dp(n+1, vector<int>(sumF+1, 0));
        
        int c = count(nums.begin(),nums.end(),0);                   //edge case for 0;
        return pow(2,c)*findS(nums, sumF, dp, n);
    }
};

// Method 3: Recursion
// Doesn't gives TLE because of the constraints but is a slowest soln.

class Solution {
public:
    int targetSum(vector<int> &nums, int i, int target){
        if(target==0 && i == nums.size()) return 1;
        
        if(i>=nums.size()) return 0;
        
        return targetSum(nums, i+1, target-nums[i]) + targetSum(nums, i+1, target+nums[i]);  // A particular index will either be added or subtracted.
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return targetSum(nums, 0, target);
    }
};

// Method 4: Memoisation

class Solution {
public:
    int dp[21][2002];
    int targetSum(vector<int> &nums, int i, int target){
        if(target==0 && i == nums.size()) return 1;
        
        else if(i>=nums.size()) return 0;
        
        else if(dp[i][abs(target)] != -1) return dp[i][abs(target)];    // abs yaha karne se hi chal raha hai. Nahi toh runtime error aa raha.
        
        return dp[i][abs(target)] = targetSum(nums, i+1, target-nums[i]) + targetSum(nums, i+1, target+nums[i]);  // target-nums[i] can become negative which will point to a -ve index in matrix agar sirf neeche abs kia hota // ya toh neeche ar abs(target-nums[i]) karo toh bhi chal jaega.
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        // target = abs(target);      // karne se nahi chalega coz se above
        memset(dp, -1, sizeof(dp));
        return targetSum(nums, 0, target);
    }
};

// Method 5: Space optimised
https://leetcode.com/problems/target-sum/discuss/1174595/99-faster-oror-Using-DP-oror-Formula-explain

// Striver count partition same code works

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

int countPartition(int n, int d, vector<int> &arr){
    int totSum = 0;
    for(auto &it: arr) totSum += it;
    if(totSum - d < 0 || (totSum - d)%2) return false;
    return solve(arr, (totSum-d)/2);
}

int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    return countPartition(n, target, nums);
}

