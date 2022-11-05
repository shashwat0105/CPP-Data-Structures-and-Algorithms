https://leetcode.com/problems/triangle/

Fixed start index
Variable end index

Can move below ie i, or i+1 position.

// Instead of starting from f(m-1, n-1) which is not fixed it is better to start from f(0, 0): min path sum from (0, 0) to the last row.

// memoised

class Solution {
public:
    int solve(int n, int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        
        // base case // cannot go out of bound, there will always be an diagonal right // only 1 base case
        if(i==n-1) return triangle[i][j];
        
        if(dp[i][j]!= -1) return dp[i][j];
        
        int down = triangle[i][j] + solve(n, i+1, j, triangle, dp);
        int diagonalRight = triangle[i][j] + solve(n, i+1, j+1, triangle, dp);
        
        return dp[i][j] = min(down, diagonalRight);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(); // number of rows
        vector<vector<int>> dp(n, vector<int>(n, -1));   
        return solve(n, 0, 0, triangle, dp);
    }
};

// Tabulated

class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(); // number of rows
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // last row has to be filled  // bottom up
        for(int j=0; j<n; ++j) dp[n-1][j] = triangle[n-1][j];
        
        for(int i=n-2; i>=0; --i){
            for(int j=i; j>=0; --j){
                 int down = triangle[i][j] + dp[i+1][j];
                 int diagonalRight = triangle[i][j] + dp[i+1][j+1];
                 dp[i][j] = min(down, diagonalRight);
            }
        }
        return dp[0][0];
    }
};

// Space optimised
// O(2N)

class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(); // number of rows
        
        vector<int> next(n, 0), cur(n, 0);  
        
        // last row has to be filled  // bottom up  // base case
        for(int j=0; j<n; ++j) next[j] = triangle[n-1][j];
        
        for(int i=n-2; i>=0; --i){
            for(int j=i; j>=0; --j){
                 int down = triangle[i][j] + next[j];
                 int diagonalRight = triangle[i][j] + next[j+1];
                 cur[j] = min(down, diagonalRight);
            }
            next = cur;
        }
        return next[0];
    }
};

// O(N)

int minimumTotal(vector<vector<int>>& arr) {
    int n = arr.size();
    vector<int> front = arr[n-1];

    for(int i = n-2 ; i>=0 ; i--){
        for(int j = 0 ; j<=i ; j++){
            front[j] = arr[i][j] +  min(front[j] , front[j+1]);
        }
    }
    return front[0];
}

