https://leetcode.com/problems/minimum-path-sum/

Express in i,j
Do all stuffs
Return the min

INT_MAX is either 2147483647 or 2147483648 which (which both exceed 1e9).

// Memoised
class Solution {
public:
    int solve(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(m==0 && n==0) return grid[0][0];
        if(m<0 || n<0) return INT_MAX;               // 1e9 can be used too (better tho)
        
        if(dp[m][n]!= -1) return dp[m][n];
        
        int up = solve(m-1, n, grid, dp);
        int left = solve(m, n-1, grid, dp);
        return dp[m][n] = grid[m][n] + min(up, left);  // If using INT_MAX, first take min then add the grid value. If using 1e9 (a large value but smaller than INT_MAX) Then u can add grid value to up and left as well, then take min to avoid integer overflow
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();    // rows
        int n = grid[0].size(); // columns
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, grid, dp);
    }
};

// Tabulated

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();    // rows
        int n = grid[0].size(); // columns
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0; i<m; ++i){
            
            for(int j=0; j<n; ++j){
                if(i==0 && j==0) dp[i][j] = grid[0][0];
                else{
                    int up = 0, left = 0;
                    // requiring previous row's j column
                    if(i>0) up = grid[i][j] + dp[i-1][j];
                    else up += 1e9;
                    // requiring row's j-1 column
                    if(j>0) left = grid[i][j] + dp[i][j-1];
                    else left += 1e9;
                    dp[i][j] = min(up, left);
                }    
            }
        }
        return dp[m-1][n-1];
    }
};

// SPACE OPTIMISED

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();    // rows
        int n = grid[0].size(); // columns
        
        vector<int> prev(n, 0);
        for(int i=0; i<m; ++i){
            vector<int> cur (n, 0);
            for(int j=0; j<n; ++j){
                if(i==0 && j==0) cur[j] = grid[0][0];
                else{
                    int up = 0, left = 0;
                    // requiring previous row's j column
                    if(i>0) up = grid[i][j] + prev[j];
                    else up += 1e9;
                    // requiring row's j-1 column
                    if(j>0) left = grid[i][j] + cur[j-1];
                    else left += 1e9;
                    cur[j] = min(up, left);
                }    
            }
            prev = cur;    // cur value will be transfered to prev.
        }
        return prev[n-1];
    }
};

