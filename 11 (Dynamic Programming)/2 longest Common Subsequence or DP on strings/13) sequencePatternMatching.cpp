// https://leetcode.com/problems/is-subsequence/
// Another method is with two pointers TC = O(n) optimized, this ques is not worth LCS approach 

// Wildcard pattern matching problem is a more suitable candidate for DP than this

// I/P -> x = "AXY" ; y = "ADXCPY" 
// O/P -> T/F  ie boolean, Is "x" a subsequence of "y" ?

// Let's try applying LCS in this?
// LCS of x & y is "AXY" is also nothing but string x itself!
// Now, can we compare only the length of LCS & string x or we need to completely compare AXY with AXY
// Yes, Comparing length is sufficient. How?
// Range of LCS = 0 to min(m, n)

LCS(x, y, m, n)

if(LCS == x.length())
    return true;
else
    return false;


// CODE:
class Solution {
public:
    int LCS(string x, string y){
        int m = x.size();
        int n = y.size();
        int t[101][10001];                          // VVIP to do it with the given constraints, then only it will work.

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
    
    bool isSubsequence(string s, string t) {
        int p = LCS(s, t);
        int q = s.size();
        if(p==q) return true;
        else return false;
    }
};


// Method 2:
// Using Binary search:
