LCS Template:

int LCS(string x, string y){
    int m = x.size();
    int n = y.size();
    int t[1001][1001];

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
 

Explanation:
// substring != subsequence 
// https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
// A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. But a substring needs to be continuos. 
// Subsequence mein right-bottom corner element return hota hai.
// Substring mein ek result(max) variable bana k chalte hai wo return hota hai.

// Problem Statement:- x = abcdgh (length = m), y = abedfghr (length = n) :- Longest common subsequence is abdgh -> length = 4 Ans, whereas longest common substring is ab -> length = 2
// While writing recursive solution 3 things to be taken care of :- (i) Base condition (ii) Choice Diagram (iii) Making Input -> Smaller

// Base condition :- Smallest valid input, here input are the two strings hence smallest valid length of string is 0 ie empty string.
// Hence LCS = 0, in base condition 

// Choice Diagram (See the screenshot too)
// (i) If the last string element matches shortening the string length -> n-1 & m-1  (ii) If the last element does not matches then we take 2 cases in which we shorten the string one at a time ie n-1, m & n, m-1  -> then we take thier max

int LCS(string x, string y, int m, int n){
    // base condition
    if(m==0 || n==0){
        return 0;
    }

    // choice diagram
    if(x[m-1] == y[n-1]){   // ie last element is common
        return 1 + LCS(x, y, m-1, n-1);  // Instead of value when the elements matches we add 1 (qki yahi toh chahiye hai for count of LCS)
    }
    else
        return max(LCS(x, y, m, n-1), LCS(x, y, m-1, n));
}


// Method 2:- Memoisation or TopDown Method (Only required values are filled in tha table)
// Table will be made of those variables that are changing in recursive calls here m & n
// Hence  table t[m+1][n+1] is made of index 0 to m & 0 to n

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

**************************************************
LEETCODE
https://leetcode.com/problems/longest-common-subsequence/

// Memoised
// NOTE:
// When we pass it as (string a, string b) ie by value then, in every recursive call the string value will be copied again and again in the memory stack 
// but passing it as (string &a, string &b) ie by reference will just pass address which will point to the address of the particular value or string.

class Solution {
public:
    int LCS(string &x, string &y, int n, int m, int t[][1001]){
        if(n==0 || m ==0){
            return 0;
        }
        if(t[n][m]!= -1){
            return t[n][m];
        }
        
        if(x[n-1] == y[m-1]){
            return t[n][m] = 1 + LCS(x, y, n-1, m-1, t);
        }
        else{
            return t[n][m] = max(LCS(x, y, n-1, m, t), LCS(x, y, n, m-1, t));
        }
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        int t[1001][1001];
        for(int i=0; i<1001; ++i){
            for(int j=0; j<1001; ++j){
                t[i][j] = -1;
            }
        }
        return LCS(text1, text2, n, m, t);
    }
};

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
            return dp[i][j]= 1+backtrack(str1,str2,i+1,j+1);
        else
            return dp[i][j]= max(backtrack(str1,str2,i+1,j),backtrack(str1,str2,i,j+1));
    }
};

// SPACE OPTIMISED SOLUTION
