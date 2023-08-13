LCS Template:

int LCS(string x, string y){
    int m = x.size();
    int n = y.size();
    int t[m+1][n+1];

    for(int i=0; i<=m; ++i) t[i][0] = 0;
    for(int j=0; j<=n; ++j) t[0][j] = 0;

    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    return t[m][n];
}
 
*********************************************************************************************************************************
Explanation:
// substring != subsequence 
https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

https://leetcode.com/problems/longest-common-subsequence/

// A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. But a substring needs to be continuos. 
// Subsequence mein right-bottom corner element return hota hai.
// Substring mein ek result(max) variable bana k chalte hai wo return hota hai.

// Problem Statement:- x = abcdgh (length = m), y = abedfghr (length = n) :- Longest common subsequence is abdgh -> length = 4 Ans, whereas longest common substring is ab -> length = 2
// While writing recursive solution 3 things to be taken care of :- (i) Base condition (ii) Choice Diagram (iii) Making Input -> Smaller

// Base condition :- Smallest valid input, here input are the two strings hence smallest valid length of string is 0 ie empty string.
// Hence LCS = 0, in base condition 

// Choice Diagram (See the screenshot too)
// (i) If the last string element matches shortening the string length -> n-1 & m-1  
// (ii) If the last element does not matches then we take 2 cases in which we shorten the string one at a time ie (n-1, m) & (n, m-1)  -> then we take thier max

// Method 1:- Memoisation or TopDown Method (Only required values are filled in tha table)
// Table will be made of those variables that are changing in recursive calls here m & n
// Hence  table t[m+1][n+1] is made of index 0 to m & 0 to n

// NOTE:
// When we pass it as (string a, string b) ie by value then, in every recursive call the string value will be copied again and again in the memory stack 
// but passing it as (string &a, string &b) ie by reference will just pass address which will point to the address of the particular value or string.

int t[1001][1001];
 
int LCS(string &x, string &y, int m, int n){    // IMPORTANT TO PASS BY REFERENCE (Even though its value is not Changing)
    // base condition
    if(m==0 || n==0){
        return 0;
    }
    if(t[m][n]!= -1){
        return t[m][n];
    }

    // choice diagram
    if(x[m-1] == y[n-1]){   // ie last element is common
        return t[m][n] = 1 + LCS(x, y, m-1, n-1);  // Instead of value when the elements matches we add 1 (qki yahi toh chahiye hai for count of LCS)
    }
    else
        return t[m][n] = max(LCS(x, y, m, n-1), LCS(x, y, m-1, n));
}

int main(){
    memset(t, -1, sizeof(t));

    string x;
    string y;
    cin>>x>>y;

    LCS(x, y, x.length(), y.length());
    return 0;
}

// Method 3:- Tabulation Method or Bottom Up Method 
// (To avoid stack-overflow error we need this method coz recursive calls n -> n-1 -> n-2 are stored in stack data structure)
// x = abcf -> m = 4
// y = abcdaf -> n = 6
// t[4+1][6+1] = t[5][7]
//   0  1 2 3 4 5 6 7   -> y or n -> j
// 0 0  0 0 0 0 0 0 0  
// 1 0
// 2 0        sp
// 3 0
// 4 0
// x or m -> i
// Ex subproblem(sp) :- m = 2 & n = 4 ie x = ab, y = abcd -> LCS = 2 will be stored there
// Ans = t[m][n]

int LCS(string x, string y, int m, int n){          // Approach works for LC too.

    int t[m+1][n+1];

    // base condition(Initialisation)
    for(int i=0; i<=m; ++i) t[i][0] = 0;
    for(int j=0; j<=n; ++j) t[0][j] = 0;

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            // choice diagram
            if(x[i-1] == y[j-1]){                     // ie last element is common
                t[i][j] = 1 + t[i-1][j-1];            // (qki yahi toh chahiye hai for count of LCS) & size of both strings are reduced by 1
            }
            else
                t[i][j] = max(t[i][j-1], t[i-1][j]);  // reducing size of strings one at a time
            }
    }
    return t[m][n];
}

***********************************************************************

// Here, we traversed the string from the back:
// Start from the begining and base case here is reaching the end of any of the strings in the recursion
// If you start from the end then base case would be reaching the start of any of the strings.
// For most of the Dp-string questions, we can solve by taking the pointers from start or end but the only difference is the base cases.

// Code if started from beginning of the string:
class Solution {
public:
    vector<vector<int>>dp;
    
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(),m=text2.length();
        dp.resize(n+1,vector<int>(m+1,-1));
        return backtrack(text1,text2,0,0);
    }
    
    int backtrack(string &str1,string &str2,int i,int j){
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(i==str1.length() || j==str2.length()) return 0;
        
        if(str1[i]==str2[j])
            return dp[i][j]= 1 + backtrack(str1,str2,i+1,j+1);
        else
            return dp[i][j]= max(backtrack(str1,str2,i+1,j), backtrack(str1,str2,i,j+1));
    }
};


*********************************************** STRIVER  *******************************************************

1) Express in terms of (index1, index2)  // A single index won't be able to express both the strings
2) Explore possibilities on that index   : Match, notMatch
3) Take the best among them.

f(2, 5) means LCS of string 1 [0...2] and string 2 [0...5]

// previous array problems: pick and notPick
// Here in string matches or not matches

// If match reduce/shrink both index and return
// If not match reduce/shrink one by one and take max and return

// Memoised

class Solution {
public:
    int solve(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp){
        if(ind1<0 || ind2<0) return 0;

        if(dp[ind1][ind2]!= -1) return dp[ind1][ind2];

        if(text1[ind1]==text2[ind2]) return dp[ind1][ind2] = 1 + solve(ind1-1, ind2-1, text1, text2, dp);

        return dp[ind1][ind2] = 0 + max(solve(ind1-1, ind2, text1, text2, dp), solve(ind1, ind2-1, text1, text2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(n-1, m-1, text1, text2, dp);
    }
};

// We can also write the code in match, notMatch terms, and also tabulate it
class Solution {
public:
    int solve(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp){
        if(ind1<0 || ind2<0) return 0;

        if(dp[ind1][ind2]!= -1) return dp[ind1][ind2];
        
        int match = 0;
        int notMatch = 0;
        if(text1[ind1]==text2[ind2]) match = 1 + solve(ind1-1, ind2-1, text1, text2, dp);
        else notMatch = 0 + max(solve(ind1-1, ind2, text1, text2, dp), solve(ind1, ind2-1, text1, text2, dp));
        return dp[ind1][ind2] = max(match, notMatch);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(n-1, m-1, text1, text2, dp);
    }
};

// Tabulation to optimise the auxiliary stack space

Steps
1) Copy the base case (bit tricky thing)
2) Write the changing parameters in opposite fashion Here ind1 and ind2
3) Copy the recurence

// We cannot access negative index, so we will do shifting of index. 
Instead of f(n-1, m-1) call f(n, m)

// Hence you can also modify the memoised code too 
class Solution {
public:
    int solve(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp){
        if(ind1==0 || ind2==0) return 0;

        if(dp[ind1][ind2]!= -1) return dp[ind1][ind2];

        if(text1[ind1-1]==text2[ind2-1]) return dp[ind1][ind2] = 1 + solve(ind1-1, ind2-1, text1, text2, dp);

        return dp[ind1][ind2] = 0 + max(solve(ind1-1, ind2, text1, text2, dp), solve(ind1, ind2-1, text1, text2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solve(n, m, text1, text2, dp);
    }
};

// Base case for tabulation
i==0 means dp[0][j] i from 0 to n (shifted)
j==0 means dp[i][0] i from 0 to m (shifted)

//
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        // base case
        for(int ind1=0; ind1<=n; ++ind1) dp[ind1][0] = 0;  // ind1, ind2 can be taken as i, j
        for(int ind2=0; ind2<=m; ++ind2) dp[0][ind2] = 0;

        for(int ind1=1; ind1<=n; ++ind1){
            for(int ind2=1; ind2<=m; ++ind2){
                if(text1[ind1-1]==text2[ind2-1]) dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                else dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2], dp[ind1][ind2-1]);  // need to write else, coz all the values need to be filled, in recursion it returned
            }
        }
        return dp[n][m];
    }
};

// Space optimised
// Using two rows.

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m+1, 0), cur(m+1, 0);
        
        // base case
        for(int ind2=0; ind2<=m; ++ind2) prev[ind2] = 0;                       // only a row is required, no column // for first row everyone is zero

        for(int ind1=1; ind1<=n; ++ind1){
            for(int ind2=1; ind2<=m; ++ind2){
                if(text1[ind1-1]==text2[ind2-1]) cur[ind2] = 1 + prev[ind2-1];
                else cur[ind2] = 0 + max(prev[ind2], cur[ind2-1]);             // need to write else, coz all the values need to be filled, in recursion it returned
            }
            prev = cur;
        }
        return prev[m];
    }
};
