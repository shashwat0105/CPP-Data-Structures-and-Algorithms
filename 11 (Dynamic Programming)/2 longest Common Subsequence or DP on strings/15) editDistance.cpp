https://leetcode.com/problems/edit-distance/

https://www.youtube.com/results?search_query=edit+distance+dynamic+programming

FAMOUS PROBLEM

Delete everything and inserting: max steps = m+n

Replace operation makes it tougher

// Take one char from s1 and one from s2
// In string matching there is two things when they match and when they do not match.
// If they match then well and good no need of doing anything
// If they don't I have a lot of options that are:
// 1) Insert the same element and match
// 2) Delete and try finding somewhere else.
// 3) Replace and match

// I have to try all ways and find the best ie recursion.

// How to write recurrence?
// 1) Express in terms of (i, j)
// 2) Explore all paths of matching
// 3) Return min of all paths
// 4) Write the base case when its over

f(i-1, j-1) means: min operations to convert s1[0...i] into s2[0...j]

Base case
1) s1 gets exhausted: ie s2 has some elements left, that many elements I need to insert now to convert. ie j+1 // j is index so number of elements will be j+1
2) s2 gets exhausted: s1 has some elements, then I need to delete all the elements.  ie i+1


// If I insert an element to match then i will stay there j will move
// If I delete an element in hope that it will get matched in future, i will move and j will stay there as it is yet to be matched
// If I replace an element then both can move

// Memoised

class Solution {
public:
    int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(dp[i][j]!= -1) return dp[i][j];

        if(word1[i]==word2[j]) return dp[i][j] = 0 + solve(i-1, j-1, word1, word2, dp);
        
        else{
            int insert = 1 + solve(i, j-1, word1, word2, dp);    
            int deletee = 1 + solve(i-1, j, word1, word2, dp);
            int replace = 1 + solve(i-1, j-1, word1, word2, dp);
            return dp[i][j] = min({insert, deletee, replace});
        }
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(n-1, m-1, word1, word2, dp);
    }
};

// Tabulated
// +1 right shift to avoid -ve

// Memoised right shift

class Solution {
public:
    int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        if(i == 0) return j;  // change here
        if(j == 0) return i;  // change here

        if(dp[i][j]!= -1) return dp[i][j];

        if(word1[i-1]==word2[j-1]) return dp[i][j] = 0 + solve(i-1, j-1, word1, word2, dp);  // change here
        
        else{
            int insert = 1 + solve(i, j-1, word1, word2, dp);
            int deletee = 1 + solve(i-1, j, word1, word2, dp);
            int replace = 1 + solve(i-1, j-1, word1, word2, dp);
            return dp[i][j] = min({insert, deletee, replace});
        }
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));  // change here
        return solve(n, m, word1, word2, dp);
    }
};

// Base case
f(0, j): i==0 return j
ie for i==0 on every j return j
and for any j==0 return i

// Table will look like
// 0 1 2 3 4 5
// 1
// 2
// 3
// 4
// 5

class Solution {
public:

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int i=0; i<=n; ++i) dp[i][0] = i;
        for(int j=0; j<=m; ++j) dp[0][j] = j;

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(word1[i-1]==word2[j-1]) dp[i][j] = 0 + dp[i-1][j-1];
        
                else{
                    int insert = 1 + dp[i][j-1];
                    int deletee = 1 + dp[i-1][j];
                    int replace = 1 + dp[i-1][j-1];
                    dp[i][j] = min({insert, deletee, replace});
                }
            }
        }
        return dp[n][m];
    }
};

// Space optimised

class Solution {
public:

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> prev(m+1, 0), cur(m+1, 0);

        for(int j=0; j<=m; ++j) prev[j] = j;

        for(int i=1; i<=n; ++i){
            cur[0] = i;                //(additional change else erro) every time you are moving to a row, this is another base case u need to take care of.
            for(int j=1; j<=m; ++j){
                if(word1[i-1]==word2[j-1]) cur[j] = 0 + prev[j-1];
        
                else{
                    int insert = 1 + cur[j-1];
                    int deletee = 1 + prev[j];
                    int replace = 1 + prev[j-1];
                    cur[j] = min({insert, deletee, replace});
                }
            }
            prev = cur;  // prev k andar cur ki shaktiya aa jati hai
        }
        return prev[m];
    }
};


// You cannot further optimise to 1 array because prev states of cur and prev both are required.
// Haha yeh raha 1 array code:
class Solution {
public:
    int minDistance(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<int> prev(m + 1, 0);

        for (int j = 1; j <= m; j++) {
            prev[j] = j;
        }
        int first = 0;
        for (int i = 1; i <= n; i++) {
            first = prev[0];
            prev[0] = i;
            for (int j = 1; j <= m; j++) {
                int temp = prev[j];
                if (str1[i - 1] == str2[j - 1]) {
                    prev[j] = first;
                }
                else {
                    prev[j] = 1 + min({first, prev[j - 1], prev[j]});
                }
                first = temp;
            }
        }
        return prev[m];
    }
};
