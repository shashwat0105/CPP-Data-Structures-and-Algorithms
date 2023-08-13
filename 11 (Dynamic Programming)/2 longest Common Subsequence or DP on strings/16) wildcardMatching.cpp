https://leetcode.com/problems/wildcard-matching

https://www.youtube.com/results?search_query=44.+Wildcard+Matching

? is straightforward to match
* is where the problem arises

For * all possibilities are to match with
0, 1, 2, 3,,.... number of characters

if(p[i]=='*') f(i-1, j)   // currently let star be "" ie empty 
                    or f(i, j-1)  // start equal to additianal one element ie one matched of j, and it will move forward.

* = empty or 1 match
* = empty or 2 match (match 1 then match 1 recursively)
* = empty or 3 match ...
ie delete one char then again delete one char then again.... recursively

abc to match with aec: cannot be matched b and e return false

// Base case
// Has to return true or false
// True when comparisons has been done
// Both strings need to be exhausted at the same time for the comparison to be true

// Memoised

class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){ // i = pattern, j = text
        // base case
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;  // pattern khatam but string bachi hui hai, no way to match
        if(j<0 && i>=0){               // some portion of pattern is left to be matched with empty string ie all should be ***
            for(int x = 0; x<=i; ++x){
                if(p[x]!='*') return false;
            }
            return true;
        }

        if(dp[i][j]!= -1) return dp[i][j];
        // try all stuffs
        if(p[i] == s[j] || p[i]=='?'){
            return dp[i][j] = solve(i-1, j-1, s, p, dp);
        } 
        if(p[i] == '*'){
            return dp[i][j] = solve(i-1, j, s, p, dp) | solve(i, j-1, s, p, dp);
        }
        return dp[i][j] = false;     // else case neither *, nor ? nor they matched ie they didn't matched so we return false.
    }

    bool isMatch(string s, string p) {
        int n = p.size();  // pattern
        int m = s.size();  // text
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(n-1, m-1, s, p, dp);
    }
};

// Tabulation

// 1) Base case
// 2) i =
//      j =
// 3) Copy the recurences

// First need to right shift (do analyse the changes made)

// Right shifted memoised
class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){ // i = pattern, j = text
        // base case
        if(i==0 && j==0) return true;
        if(i==0 && j>0) return false; // pattern khatam but string bachi hui hai, no way to match
        if(j==0 && i>0){              // some portion of pattern is left to be matched with empty string ie all should be ***
            for(int x = 1; x<=i; ++x){  // u have to traverse in one based indexing (changes here too)
                if(p[x-1]!='*') return false;
            }
            return true;
        }

        if(dp[i][j]!= -1) return dp[i][j];
        // try all stuffs
        if(p[i-1] == s[j-1] || p[i-1]=='?'){
            return dp[i][j] = solve(i-1, j-1, s, p, dp);
        } 
        if(p[i-1] == '*'){
            return dp[i][j] = solve(i-1, j, s, p, dp) | solve(i, j-1, s, p, dp);
        }
        return dp[i][j] = false;       
    }

    bool isMatch(string s, string p) {
        int n = p.size();  // pattern
        int m = s.size();  // text
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solve(n, m, s, p, dp);
    }
};

// Tabulated

class Solution {
public:

    bool isMatch(string s, string p) {
        int n = p.size();  // pattern
        int m = s.size();  // text
        vector<vector<bool>> dp(n+1, vector<bool> (m+1, 0));
        // base case
        dp[0][0] = true;          // first case
        for(int j=1; j<=m; ++j){  // for every i==0 and j>0
            dp[0][j] = false;
        }
        for(int i=1; i<=n; ++i){
            bool flag = true;
            for(int x=1; x<=i; ++x){
                if(p[x-1]!= '*'){
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag; // coz j = 0
        }

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(p[i-1] == s[j-1] || p[i-1]=='?'){
                    dp[i][j] = dp[i-1][j-1];
                } 
                else if(p[i-1] == '*'){
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};


// OR in base case
// In tabulation to check the base case instead of iterating from the beginning every time you can simply check if the previous state is true and the current value = '*".
// for(int i = 1 ; i <= n ; i++)
//     dp[i][0] = dp[i-1][0] && (pattern[i-1] == '*') 


// Space optimised

class Solution {
public:

    bool isMatch(string s, string p) {
        int n = p.size();  // pattern
        int m = s.size();  // text
        vector<bool> prev(m+1, false), cur(m+1, false);
        // base case
        prev[0] = true;          // first case
        for(int j=1; j<=m; ++j){  // for every i==0 and j>0
            prev[j] = false;
        }
        for(int i=1; i<=n; ++i){
            bool flag = true;
            for(int x=1; x<=i; ++x){
                if(p[x-1]!= '*'){
                    flag = false;
                    break;
                }
            }
            // for every row u are assigning 0'th columns value
            cur[0] = flag; // coz j = 0
            // cur is current row/s column and that cur's 0th row has to be assigned everytime
            for(int j=1; j<=m; ++j){
                if(p[i-1] == s[j-1] || p[i-1]=='?'){
                    cur[j] = prev[j-1];
                } 
                else if(p[i-1] == '*'){
                    cur[j] = prev[j] | cur[j-1];
                }
                else cur[j] = false;
            }
            prev = cur;
        }
        return prev[m];
    }
};
