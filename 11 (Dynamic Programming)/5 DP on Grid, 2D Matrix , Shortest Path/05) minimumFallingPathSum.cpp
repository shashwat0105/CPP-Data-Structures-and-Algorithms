https://leetcode.com/problems/minimum-falling-path-sum/


// Starting is also not fixed
// Ending is also not fixed

f(i, j): max path sum to reach (i, j) from any cell in the first row.

// Base case: Destination or/and out of bound cases

// In this you have to call "recursion for every cell" fixing elements from either the last row or the first row.


// Memoised

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp){  // i==row, j==col
        int n = matrix.size();

        // base case
        if(j<0 || j>=n) return 1e9;     // j will go out of bound // Base case for j
        if(i==0) return matrix[i][j];   // reached destination    // Base case for i
        
        if(dp[i][j]!= -1) return dp[i][j];
        
        int up = solve(i-1, j, matrix, dp);
        int upLeftDiagonal = solve(i-1, j-1, matrix, dp);
        int upRightDiagonal = solve(i-1, j+1, matrix, dp);
        
        return dp[i][j] = matrix[i][j] + min({up, upLeftDiagonal, upRightDiagonal});
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        int ans=1e9;   // A large value coz min is asked and values can be -ve as well
        for(int j=0; j<n; ++j){   // calling from all the columns of the last row // coz this destination is variable 
            ans = min(mini, solve(n-1, j, matrix, dp));
        }
        return ans;
    }
};

// Recursion is going from n-1 to 0, so bottom up will go from 0 to n-1


// Tabulated
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        for(int j=0; j<n; ++j) dp[0][j] = matrix[0][j];  // base case
        
        for(int i=1; i<n; ++i){            // i=0 is filled in base case
            for(int j=0; j<n; ++j){
                int up = matrix[i][j] + dp[i-1][j];
                int ld = matrix[i][j];
                if(j-1>=0) ld += dp[i-1][j-1];
                else ld += 1e9;
                int rd = matrix[i][j];
                if(j+1<n) rd+= dp[i-1][j+1];
                else rd+= 1e9;
                dp[i][j] = min({up, ld, rd});
            }
        }
        
        int maxi= 1e9;   // A large value coz min is asked and values can be -ve as well
        for(int j=0; j<n; ++j){
            maxi = min(maxi, dp[n-1][j]);
             
        }
        return maxi;
    }
};


// Space optimised

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        vector<int> prev(n, 0), cur(n, 0);    // size of the column
        
        for(int j=0; j<n; ++j) prev[j] = matrix[0][j];  // base case
        
        for(int i=1; i<n; ++i){
            for(int j=0; j<n; ++j){
                int up = matrix[i][j] + prev[j];
                int ld = matrix[i][j];
                if(j-1>=0) ld +=  prev[j-1];
                else ld += 1e9;
                int rd = matrix[i][j];
                if(j+1<n) rd+= prev[j+1];
                else rd+= 1e9;
                cur[j] = min({up, ld, rd});
            }
            prev = cur;
        }
        
        int maxi= 1e9;   // A large value coz min is asked and values can be -ve as well
        for(int j=0; j<n; ++j){
            maxi = min(maxi, prev[j]);
             
        }
        return maxi;
    }
};
