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
    int solve(int i, int j){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;   // crossed the boundary
        
        int up = solve(i-1, j);
        int left = solve(i, j-1);
        return up+left;
    }
    
    int uniquePaths(int m, int n) {  // grid would be of size say (3, 3) but f(2, 2) will be called.
        return solve(m-1, n-1);      // 0 based indexing
    }
};

// Memoised
class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;

        if(dp[i][j]!= -1) return dp[i][j];
        int left = solve(i, j-1, dp);
        int up = solve(i-1, j, dp);
        return dp[i][j] = left+up;
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

// Improvising
// Think logically for the base cases.
// The first row and column has to be 1 in DP table. So, declare [][] with all values marked 1.

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m,vector<int> (n,1));

        for(int i = 1;i<m; i++){
            for(int j = 1;j<n;j++){  
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
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
        vector<int> preComp(n,1);
        for(int i = 1; i<m; i++) {
            vector<int> newComp(n,1);       // current row
            for(int j=1;j<n;j++) {
                newComp[j] = newComp[j-1] + preComp[j];
            }
            preComp = newComp;             // the current row will become previous for next iteration
        }
        return preComp[n-1];
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