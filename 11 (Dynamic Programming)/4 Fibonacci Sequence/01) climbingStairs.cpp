https://leetcode.com/problems/climbing-stairs/

// Recursive(TLE):
int climbStairs(int n) {
    if(n<=1) return 1;
    return climbStairs(n-1) + climbStairs(n-2); 
}

// Memoised
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

// If I think using this approach 
1. Try to represent the problem in terms of index.
2. Do all possible stuffs on that index according to the problem statement.
3. Sum of all the stuffs. -> Count all ways
My code will look like:
class Solution {
public:
    int solve(int idx, int n, vector<int> &dp){
        if(idx >= n-1) return 1;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx] = solve(idx+1, n, dp) + solve(idx+2, n, dp);
    }
    int climbStairs(int n) {
       vector<int> dp(n+2, -1);
       return solve(0, n, dp); 
    }
};

// Python
// Just a word @cache is a decorator from functool module can use to memoise. 
// We write it above the function definition

class Solution:
    @cache
    def climbStairs(self, n: int) -> int:
        if(n<=1):
            return 1
        return self.climbStairs(n-1) + self.climbStairs(n-2)

// Most optimised:
// Using matrix exponentiation
O(logn)

https://leetcode.com/problems/climbing-stairs/discuss/25477/O(logn)-C%2B%2BPython-Solutions-using-Matrix-Power

https://leetcode.com/problems/climbing-stairs/discuss/764806/C%2B%2B-Matrix-Exponentation(O(logn))
