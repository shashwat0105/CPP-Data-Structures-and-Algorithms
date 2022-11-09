// https://www.geeksforgeeks.org/shortest-common-supersequence/
// Given Input:   str1 = "geek",  str2 = "eke" -> merge & we should get a string that has both st1 & str2 as a substring.
// Output: length of "geeke" ie 5

// We merge 2 strings and make a supersequence.
// For example:- "geekeke" is a supersequence containing both geek and eke but it's not the shortest
// "geeke" contains both geek & eke as well as is shortest too. 

// In superstring sequence of alphabets = order maintain + not necessary continuos
// for ex:- "AGGTAB" m = 6, "GXTXAYB" n = 7 -> "AGGTGXABTXAYB"  is a valid supersequence but not the shortest

// The common alphabets can be written once to get the shortest supersequence
// Shortest is :- AGGXTXAYB :- 9 Ans
// Common alphabets are :- G T A B :- which is nothing but longest common substring(LCS) = 4
// Worst case of supersequence is adding both strings "AGGTABGXTXAYB" = 13 (GTAB is repetited twice so we will remove it once to get ans)


// 1) Length of SCS is to be found:

// Hence, Worst case length = m + n
// Best case(length of shortest supersequence) = (m+n) - LCS   // Ans

return m+n - LCS(x, y, m, n);

// Hence, the code will look like:
int LCS(string x, string y, int m, int n){
    int t[101][101];
    
    for(int i=0; i<=m; ++i) t[i][0] = 0;
    for(int j=0; j<=n; ++j) t[0][j] = 0;
    
    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(x[i-1] == y[j-1]){
                t[i][j] = 1+ t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    return t[m][n];
}
    
int shortestCommonSupersequence(string x, string y, int m, int n){
    //code here
    return m+n-LCS(x, y, m, n);
}


// Method 2:
// Yet to understand (Refer Yt or GFG explanation)
int shortestCommonSupersequence(string x, string y, int n, int m){
    // dp[i][j] -> length of common shortest subsequnce from x till i 
    // and from y till j
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=m;i++){
        dp[0][i]=i;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else{
                dp[i][j] = 1+min(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}


// 2) Print the SCS

https://leetcode.com/problems/shortest-common-supersequence/


class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // creating LCS dp table
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int i=0; i<=n; ++i) dp[i][0] = 0;
        for(int j=0; j<=m; ++j) dp[0][j] = 0;

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        // now using this table to backtrack and print SCS
        string ans = "";
        int i=n, j=m;     // to go from right bottom last corner
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans.push_back(str1[i-1]);           // You need to add the element that matches once
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){       // Jinka max leke banaya tha unka comparison hoga
                ans.push_back(str1[i-1]);           // Also need to add those elements which dont match as we need to make a supersequence.
                i--;
            }
            else{
                ans.push_back(str2[j-1]);
                j--;
            }
        }

        // If any of the string doesn't gets exhausted
        while(i>0){
            ans.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(str2[j-1]);
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
