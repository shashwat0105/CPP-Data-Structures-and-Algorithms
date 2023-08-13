https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
https://www.geeksforgeeks.org/minimum-insertions-to-form-a-palindrome-dp-28/

// Idea is to keep the "longest" palindrome portion of the string intact.

// Similar to min no of deletion ques (give 2 min to think if u have any similar ques before)

// I/P : x  = "aebcbda" 

// In aebcbda , "ed" is disturbing!
// So, to make a palindrome we can either delete e, d or insert e, d and make it's pair

Hence, No of insertions = No. of deletions.(LOL) = Length of string - LPS 

****   

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
    
    int minInsertions(string str) {
        int n = str.size();
        string x = str;
        reverse(str.begin(), str.end());
        return n - LCS(x, str);
    }
};
