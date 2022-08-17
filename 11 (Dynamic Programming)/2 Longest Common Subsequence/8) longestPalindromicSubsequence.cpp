// https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/

// Given a sequence, find the length of the longest palindromic subsequence in it.
// Example :
// Input:"bbbab"
// Output: 4  (bbbb is the required string)

// Input:"agbcba"
// Output: 5  (abcba is the required string)

// LCS is applicable or not?
// I/P = 1 string, LCS has 2 strings, Ques is both longest and subsequence, O/P  is int -> 2/3 nearly matches
// Is another string is hidden ie redundent or can be derived from given string? To match the I/P of LCS

// Concept thinking:- Let's reverse the given string(coz palindrome)
// x: "agbcba"  // x
// y: "abcbga"  // reverse of x
// Now we get 2 strings as required for LCS
// LCS of x & y is "abcba" Length = 5,  WOW which is nothing but our answer!!

// Hence
LPS(x) = LCS(x, reverse(x));

// string y = reverse(x.begin(), x.end());  // This is wrong coz reverse does not returns a value and instead operates in place
// reverse(x.begin(), x.end());

https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    int LCS(string x, string y){
        int m = x.size();
        int n = y.size();
        int t[1001][1001];
        
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
    
    int longestPalindromeSubseq(string s) {
        string x = s;
        reverse(s.begin(), s.end());
        return LCS(x, s);
    }
};


