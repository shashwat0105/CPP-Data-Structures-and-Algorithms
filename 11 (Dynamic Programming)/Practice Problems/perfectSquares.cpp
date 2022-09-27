https://leetcode.com/problems/perfect-squares/

dp[i] = minimum number of numbers to subtract from i to reach 0.

dp[n]     // our final answer
dp[0] = 0;

// code

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        
        dp[0] = 0;
        
        for(int i=1; i<=n; ++i){
            int ans = (1<<30);   // infinity
            for(int j = 1; j*j <= i; ++j){
                ans = min(ans, 1+dp[i - j*j]);
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};

