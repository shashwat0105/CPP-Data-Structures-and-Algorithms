https://leetcode.com/problems/shortest-common-supersequence/   // Here I have to print the supersequence as well!!
https://www.geeksforgeeks.org/shortest-possible-combination-two-strings/    (Contains two methods)
https://www.geeksforgeeks.org/print-shortest-common-supersequence/          (Contains one method)

// Given two strings X and Y, print the shortest string that has both X and Y as subsequences. 
// If multiple shortest supersequence exists, print any one of them.
// I/P -> x : 'acbcf' & y : 'abcdaf' 
// O/P -> 'acbcdaf'

// Input: X = "HELLO",  Y = "GEEK"
// Output: "GEHEKLLO" OR "GHEEKLLO" OR Any string that represents shortest supersequence of X and Y

// length of SCS is = m+n - LCS  (reasoned in SCS ques)

// Similar to print LCS ques

    
// LCS table for x & y
//         phi a  b   c   d   a   f
//          0  1  2   3   4   5   6  -> n(Size of string y)
// phi  0   0  0  0   0   0   0   0
//  a   1   0  1  1   1   1   1   1
//  c   2   0  1  1   2   2   2   2
//  b   3   0  1  2   2   2   2   2
//  c   4   0  1  2   3   3   3   3
//  f   5   0  1  2   3   3   4   4
// m(Size of string x)

// Printing SCS:- write common part once + write rest of the string
// While in LCS we used to write only the common part (ie which was equal)
// & If LCS touches any boundary :- "ac" & phi -> LCS = empty string nothing to print more
// But when u hit boundary in SCS :- "ac" & phi -> SCS = "ac" ie extra ac we have to print more
       
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // creating LCS dp table
        int m = str1.size(), n = str2.size();
        int dp[m+1][n+1];
        for(int i=0; i<=m; i++){
            dp[i][0]=0;
        }
        for(int i=0; i<=n; i++){
            dp[0][i]=0;
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // now using this table to backtrack and print SCS
        string ans = "";
        int i=m, j=n;   // to go from right bottom last corner
        while(i>0&&j>0){
            if(str1[i-1]==str2[j-1]){    // if the string elements are equal
                ans+=str1[i-1];          // we push the element in string which matches here x[i-1] & y[j-1] are same so can push any      
                i--;
                j--;
            }
            else{                          // Jinka max leke banaya tha unka comparison hoga   // if the string elements are not equal toh bhi mereko include krna hai ab 
                if(dp[i-1][j]<dp[i][j-1]){ // then we compare the two values of subproblem(diagnal) and move in the direction of maximum // Also need to add those elements which dont match as we need to make a supersequence.
                    ans+=str2[j-1];
                    j--;
                }
                else{
                    ans+=str1[i-1];
                    i--;
                }
            }
        }
        while (i > 0) {
            ans += str1[i-1];
            i--;
        }
        while (j > 0) {
            ans += str2[j-1];
            j--;
        };
        reverse(ans.begin(), ans.end());
        return ans;

    }
};