https://leetcode.com/problems/unique-paths-ii/

// Memoised
class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){
        if(m>=0 && n>=0 && obstacleGrid[m][n]==1) return 0;  // only this line is added
        if(m==0 && n==0) return 1;
        if(m<0 || n<0) return 0;                             
        
        if(dp[m][n]!= -1) return dp[m][n];
        
        int up = solve(m-1, n, obstacleGrid, dp);
        int left = solve(m, n-1, obstacleGrid, dp);
        return dp[m][n] = up+left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m-1, n-1, obstacleGrid, dp);
    }
};

// Tabulated

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;  // only extra addition
                else if(i==0 && j==0) dp[0][0] = 1;
                else {
                    int up = 0, left = 0;          // imp to declare else error
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};


// Space optimised

class Solution {
public: 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();  // columns
        vector<int> prev(n,0);
        for(int i=0; i<m; ++i){
            vector<int> cur(n, 0);
            for(int j=0; j<n; ++j){
                if(obstacleGrid[i][j] == 1) cur[j] = 0;
                else if(i==0 && j==0) cur[0] = 1;
                else {
                    int up = 0, left = 0;          // imp to declare else error
                    if(i>0) up = prev[j];          // i-1 means prev row
                    if(j>0) left = cur[j-1];
                    cur[j] = up+left;
                }
            }
            prev = cur;
        }
        return prev[n-1];
    }
};

