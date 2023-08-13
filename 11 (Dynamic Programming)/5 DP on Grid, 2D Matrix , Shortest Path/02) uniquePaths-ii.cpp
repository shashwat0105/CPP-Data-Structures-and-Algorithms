https://leetcode.com/problems/unique-paths-ii/

// Memoised
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0;  // only this line is added
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;                             
        
        if(dp[i][j]!= -1) return dp[i][j];
        
        int up = solve(i-1, j, obstacleGrid, dp);
        int left = solve(i, j-1, obstacleGrid, dp);
        return dp[i][j] = up+left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m-1, n-1, obstacleGrid, dp);
    }
};

// Tabulated
// You can also do by separately initilising the first row and column, see my submission. ie separate loop for 0 then 1 to n, m
// Here the loop runs 0 to others

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
                    int up = 0, left = 0;                 // imp to declare else error
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
        int n = obstacleGrid[0].size();    // columns
        vector<int> prev(n,0), cur(n, 0);  // I just want two rows of size column
        for(int i=0; i<m; ++i){
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
