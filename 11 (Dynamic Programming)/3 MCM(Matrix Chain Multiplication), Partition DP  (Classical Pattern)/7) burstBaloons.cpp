https://leetcode.com/problems/burst-balloons/

[3, 1, 5, 8]
Any one can be burst first.

// Instead of thinking that partition wala baloon will be burst first.
// Think that it will be burst last!!
// Then only the other separted parts will become independent.
//  That idea of 'last balloon to burst' is the key!

// Refer: https://leetcode.com/problems/burst-balloons/solutions/892552/for-those-who-are-not-able-to-understand-any-solution-with-diagram/?orderBy=most_votes


Cost we get on bursting the partition wala baloon in last is
1 3 5 6 7 9   10 1
  i     ind    j
a[i-1]*a[ind]*a[j+1]   // writing this is the critical and the major(only) changing parameter in MCM problems.

// ind or k will run from i to j

// Memoised

class Solution {
public:
    int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(i>j) return 0;
        
        if(dp[i][j]!= -1) return dp[i][j];

        int maxi = -1e9;
        for(int ind=i; ind<=j; ++ind){
            int cost = nums[i-1]*nums[ind]*nums[j+1] + solve(i, ind-1, nums, dp) + solve(ind+1, j, nums, dp);
            maxi = max(maxi, cost);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(1, n, nums, dp);
    }
};

// Tabulation

1) Write the base case
2) Changing variable in nested loops
3) Copy the recurence

i>j = 0; // there can be multiple values of i and j. // we will handle this later

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0)); // to handle ind+1

        for(int i=n; i>=1; --i){
            for(int j=1; j<=n; ++j){
                if(i>j) continue;
                int maxi = -1e9;
                for(int ind=i; ind<=j; ++ind){
                    int cost = nums[i-1]*nums[ind]*nums[j+1] + dp[i][ind-1] + dp[ind+1][j];
                    maxi = max(maxi, cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};

