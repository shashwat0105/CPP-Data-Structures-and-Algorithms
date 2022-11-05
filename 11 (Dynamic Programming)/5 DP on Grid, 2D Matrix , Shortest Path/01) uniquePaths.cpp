https://leetcode.com/problems/unique-paths/

Why recursion?
Ans: We are trying all possible ways.

// Steps:
1) Express in terms of index here (i, j)
2) Explore all paths/ Do all stuffs
3) Sum up/ Max or Min

// Start = (0, 0), End = (m-1, n-1)

// We will move up or left from (m-1, n-1) to (0, 0)

// Base case reaches(0, 0) return 1;
//           crosses the boundary return 0;

// Recursion (TLE)
class Solution {
public:
    int solve(int m, int n){
        if(m==0 && n==0) return 1;
        if(m<0 || n<0) return 0;   // crossed the boundary
        
        int up = solve(m-1, n);
        int left = solve(m, n-1);
        return up+left;
    }
    
    int uniquePaths(int m, int n) {  // grid would be of size say (3, 3) but f(2, 2) will be called.
        return solve(m-1, n-1);      // 0 based indexing
    }
};

// Memoised
class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& dp){
        if(m==0 && n==0) return 1;
        if(m<0 || n<0) return 0;
        
        if(dp[m][n]!= -1) return dp[m][n];
        
        int up = solve(m-1, n, dp);
        int left = solve(m, n-1, dp);
        return dp[m][n] = up+left;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, dp);
    }
};

// Tabulated
1) Declare base case
2) Express all states in for loops
3) Copy the recurrences and write.

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(i==0 && j==0) dp[0][0] = 1;
                else {
                    int up = 0, left = 0;          // imp to declare else error (dealing with else base case)
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};


// Space optimisation
// We are just using the previous row and previous column!

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        for(int i=0; i<m; ++i){
            vector<int> cur(n, 0);
            for(int j=0; j<n; ++j){
                if(i==0 && j==0) cur[j] = 1;       // the current row is not temp
                else {
                    int up = 0, left = 0;          // imp to declare else error
                    if(i>0) up = prev[j];          // dp[i-1] ie previous
                    if(j>0) left = cur[j-1];
                    cur[j] = up+left;
                }
            }
            prev = cur;  // once one row is calculated I swap or shift
        }
        return prev[n-1];
    }
};


Even better/ shorter space optimised code
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                dp[j] += dp[j-1];   
        return dp[n-1];
    }
};

// All above TC = O(m*n)
// Asked in GOOGLE
// Further optimised to O(min(n, m)) using maths

Calculating the number of different ways to choose m-1 down-moves and n-1 right-moves from a total of m+n-2 moves.

(n+m-2)!/(m-1)!(n-1)!

class Solution {
public:
    int uniquePaths(int m, int n) {
        long ans = 1;
        for(int i = m+n-2, j = 1; i >= max(m, n); i--, j++) 
            ans = (ans * i) / j;
        return ans;
    }
};

OR

int uniquePaths(int m, int n){
    int N = n+m-2;
    int r = m-1;
    double res = 1;
    for(int i=1; i<=r; ++i){
        res = res*(N-r+i)/i;
    }
    return (int)res;
}