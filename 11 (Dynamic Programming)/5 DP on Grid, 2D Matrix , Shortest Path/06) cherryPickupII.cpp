https://leetcode.com/problems/cherry-pickup-ii/

HARD

Fixed starting point
Variable ending point

All path by robo 1 + All the path robo 2

Instead of individually doing cause then we need to trace back the common cells.
We will move them together.

Wrting recursion together

1) Express everything in terms of (i1, j1) and (i2, j2)
2) Explore all the paths
3) Take max

// Since fixed starting point we will write recursion from here.

f(0, 0, 0, m-1) will be start position
// Both will be in same row at a particular time. ie i1 = i2 = i  // Reducing variables.

// Always think when they can reach the same column (j1 = j2) it will get added once.

// For every movement of robo1, robo2 has 3 movement ie total 9 combos.

// There are 3 changing parameters i, j1, j2 = N * M * M

// Memoised
class Solution {
public:
    int solve(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp){
        int n = grid.size();
        int m = grid[0].size();
        if(j1<0 || j2<0 || j1>=m || j2>=m) return -1e8;    // I forgot this step.
        
        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2]!= -1) return dp[i][j1][j2];
        
        // explore all paths simulataneously
        int maxi = -1e8;
        for(int dj1=-1; dj1<=1; ++dj1){
            for(int dj2 = -1; dj2<=1; ++dj2){
                int value = 0;
                if(j1==j2) value = grid[i][j1];          // if same cell include once
                else value = grid[i][j1] + grid[i][j2];  // else normally
                value += solve(i+1, j1+dj1, j2+dj2, grid, dp);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // int dp[n][m][m];
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return solve(0, 0, m-1, grid, dp);
    }
};


// Tabulated

class Solution {
public:
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // int dp[n][m][m];
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
        // base case when in last row.
        for(int j1 = 0; j1<m; ++j1){
            for(int j2=0; j2<m; ++j2){   //
                if(j1==j2) dp[n-1][j1][j2] = grid[n-1][j1];
                else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        
        // express every state in for loops. States are i, j1, j2
        for(int i=n-2; i>=0; --i){
            for(int j1=0; j1<m; ++j1){
                for(int j2=0; j2<m; ++j2){
                    
                    int maxi = 0;
                    for(int dj1=-1; dj1<=1; ++dj1){
                        for(int dj2 = -1; dj2<=1; ++dj2){
                            int value = 0;                     
                            if(j1==j2) value = grid[i][j1];
                            else value = grid[i][j1] + grid[i][j2];
                            if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m) 
                                value += dp[i+1][j1+dj1][j2+dj2];
                            else value += -1e8;
                            maxi = max(maxi, value);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
};


// Space optimised
1D Dp -> Two variables
2D Dp -> 1D
3D Dp -> 2D

Just the front row i+1 will be required

TC = O(n^3)
SC = O(m^2)

class Solution {
public:
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> front(m, vector<int>(m, 0));
        vector<vector<int>> cur(m, vector<int>(m, 0));

        // base case when in last row.
        for(int j1 = 0; j1<m; ++j1){
            for(int j2=0; j2<m; ++j2){   //
                if(j1==j2) front[j1][j2] = grid[n-1][j1];
                else front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        
        // express every state in for loops. States are i, j1, j2
        for(int i=n-2; i>=0; --i){
            for(int j1=0; j1<m; ++j1){
                for(int j2=0; j2<m; ++j2){
                    
                    int maxi = 0;
                    for(int dj1=-1; dj1<=1; ++dj1){
                        for(int dj2 = -1; dj2<=1; ++dj2){
                            int value = 0;
                            if(j1==j2) value = grid[i][j1];
                            else value = grid[i][j1] + grid[i][j2];
                            if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m) value += front[j1+dj1][j2+dj2];
                            else value += -1e8;
                            maxi = max(maxi, value);
                        }
                    }
                    cur[j1][j2] = maxi;
                }
            }
            front = cur;   // Have to use vectors instead of array so that it doesnot gives invalid assignement
        }
        return front[0][m-1];
    }
};

