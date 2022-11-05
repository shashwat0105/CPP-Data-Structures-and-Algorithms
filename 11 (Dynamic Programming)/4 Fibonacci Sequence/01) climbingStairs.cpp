https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int rec(int n, vector<int> &dp){
        if(n<=1) return 1;                // For n = 0 there is 1 way (Edge case) coz ways to reach at 0 if u are already at 0 is 1
        if(dp[n]!= -1) return dp[n]; 
        return dp[n] = rec(n-1, dp) + rec(n-2, dp);
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+2, -1);
        return rec(n, dp);
    }
};

// Using matrix exponentiation
O(logn)

https://leetcode.com/problems/climbing-stairs/discuss/25477/O(logn)-C%2B%2BPython-Solutions-using-Matrix-Power

https://leetcode.com/problems/climbing-stairs/discuss/764806/C%2B%2B-Matrix-Exponentation(O(logn))
