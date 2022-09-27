https://leetcode.com/problems/2-keys-keyboard/

(i, j) means i is on screen and j is on the clipboard.
(i, j) press copy => (i, i)      
(i, j) press paste => (i+j, j)

// At any state we will have two options that are:
Paste copy value with current value => 1 step
Copy current value and then paste it with itself => 2 step // Note copy alone cannot be performed coz infinite loop will be there/

dp(i, j) : minimum number of steps to reach exactly N A's on screen.
Given that i A's on screen and j A's on clipboard.

********************************************************

#define INF (1<<30)
class Solution {
public:
    int count(int i, int j, int n, vector<vector<int>> &dp){
        if(i>n) return INF;
        if(i==n) return 0;
        
        if(dp[i][j]) return dp[i][j];
        
        int op1 = 2 + count(i+i, i, n, dp);  // copy and paste
        int op2 = 1 + count(i+j, j, n, dp);  // paste
        
        return dp[i][j] = min({op1, op2});
    }
    
    int minSteps(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));  // dp[n+1][n+1]
        return n > 1 ? 1 + count(1, 1, n, dp) : 0;
    }
};

// Method 2

