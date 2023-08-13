// DP on strings

// https://www.geeksforgeeks.org/printing-longest-common-subsequence/
// Printing LCS for input Sequences x = “acbcf” (m = 5) and y = “abcdaf” (n = 6) O/P is “abcf” string instead of int = 4

// How exactly LCS works:- 
// t[5+1][6+1] = t[6][7]

//         phi a  b   c   d   a   f
//          0  1  2   3   4   5   6  -> n(Size of string y)
// phi  0   0  0  0   0   0   0   0
//  a   1   0  1  1   1   1   1   1
//  c   2   0  1  1   2   2   2   2
//  b   3   0  1  2   2   2   2   2
//  c   4   0  1  2   3   3   3   3
//  f   5   0  1  2   3   3   3   4
// m(Size of string x)

// table filling(zoom out sample) (looking the diagnals is easy)
//      a  b
//  c   5
//  b      6(5+1) will be filled here coz b = b 
//
//      a   f
//  c   2   4
//  b   3   4(maximum of 3 & 4) will be filled here coz b != f
//

// Now we move backward from bottom right corner until we hit first row or column 4 -> 3 -> 3... depending upon the two elements are equal or not. Hence we will get "fcba" as string then we reverse it
// See the Screenshot
// if equal i, j -> i--, j-- & store the LCS alphabet

// if not equal max(i-1, j  ,, i,j-1)

#include <bits/stdc++.h>
using namespace std;
int main() 
{
    string str1 = "havoc";
    string str2 = "bhvct";
    int m = str1.size();
    int n = str2.size();
    // fill the dp table
    int dp[m + 1][n + 1];
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string ans;
    int i = m, j = n;
    while(i > 0 && j > 0){
        // If current character in both the strings are same, then current character is part of LCS
        if(str1[i - 1] == str2[j - 1]){
            ans.push_back(str1[i-1]);
            i--;
            j--;
        }
        // If current character in X and Y are different & we are moving upwards ; // we compare the two values of subproblem(diagnal) and move in the direction of maximum
        else if(dp[i - 1][j] > dp[i][j - 1]){
            i--;
        }
        // If current character in X and Y are different & we are moving leftwards; 
        else{
            j--;                                   // move to the left
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans;
}

// This is a medium hard problem.
// This won't work if more than 1 lCS is present.

// other sugestions
// Just a minor suggestion which wont make much of a difference but the reverse part for getting the LCS isn't required. 
// If we know the length of the sequence, we can just create a char array of length = lcs and start from the rightmost end/index
// of the char array and copy the characters which match accordingly. 
// ie implementation then no need of reverse. 
// int len = dp[m][n];
// string ans = "";
// for(int i=0; i<len; ++i) ans+= '$';
// int index=len-1;
// int i=n; j=m;
// while(i>0 && j>0){
//     if(s1[i-1] ==s2[j-1]){
//         ans[index] = s[i-1];
//         index--;
//         i--;
//         j--;
//     }
// }


// we missed one case here
// Suppose a[ i-1 ] != b[ j - 1 ]
// and if ( t[ i ][ j-1 ] == t[ i-1 ][ j ] ) 
// what next operation shall we perform? This case can come if you have more than 1 LCS


************* STRIVER  **********

Watch the video for table visualisation

Upar wala hi code hai more or less
TUF ki website se bhi dekh skte ho jada ho toh.


// Finally try this similar question : https://practice.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1
// In this you need to print all.
