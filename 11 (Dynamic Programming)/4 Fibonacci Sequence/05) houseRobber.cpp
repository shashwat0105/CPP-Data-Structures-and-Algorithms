https://leetcode.com/problems/house-robber/

To find max sum of non adjacent elements.

// In pick case: pick = a[ind] + f(ind-2)  // cannot pick adjacent, I can go from i-2 to...0
// In not pick case: not pic: 0 + f(ind-1)

// Memoised
class Solution {
public:
    int solve(int ind, vector<int> &nums, vector<int> &dp){
        if(ind==0) return nums[0]; // because If u are standing at i=0 then better u pick it as all values are +ve
        if(ind<0) return 0;        // ind-2 can become negative
        
        if(dp[ind]!=-1) return dp[ind];
        
        int pick = nums[ind] + solve(ind-2, nums, dp);
        int notPick = 0 + solve(ind-1, nums, dp);
        return dp[ind] = max(pick, notPick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solve(n-1, nums, dp);
    }
};

// Tabulated
class Solution {
public:
    int solve(int n, vector<int> &nums, vector<int> &dp){
        dp[0] = nums[0]; // because If u are standing at i=0 then better u pick it as all values are +ve
        
        for(int i=1; i<n; ++i){
            int pick = nums[i]; if(i>1) pick += dp[i-2];
            int notPick = 0 + dp[i-1];
            dp[i] = max(pick, notPick);
        }        
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        return solve(n, nums, dp);
    }
};

// Space optimised:
// We only want i-2 and i-1 variables

class Solution {
public:
    int solve(int n, vector<int> &nums){
        int prev = nums[0]; // because If u are standing at i=0 then better u pick it as all values are +ve
        int prev2 = 0;      // index < 0
        for(int i=1; i<n; ++i){
            int pick = nums[i]; if(i>1) pick += prev2;
            int notPick = 0 + prev;
            int curi = max(pick, notPick);
            prev2 = prev;
            prev = curi;
        }        
        return prev;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(n, nums);
    }
};

