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


