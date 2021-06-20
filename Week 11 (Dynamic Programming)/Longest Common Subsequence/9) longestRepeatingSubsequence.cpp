// https://www.geeksforgeeks.org/longest-repeated-subsequence/

// I/P = str = "AABEBCDD" 
// We have to take out a subsequence that is repeated in the string at different positions.
// Here ABD is occuring twice hence it is a repeating subsequence. (Longest as well)
// O/P = 3 ans(length of "ABD")

// str1 = "AABEBCDD"
// str2 = "AABEBCDD" 
// We find LCS of str1 & str2 with restriction of i == j 

// code variation in code of LCS
// base condition(Initialisation)
if(i==0 || j==0){
    t[i][j] = 0;
}

// choice diagram
if(x[i-1] == y[j-1] && i!=j){    // code variation of i!=j ONLY. 
    t[i][j] = 1 + t[i-1][j-1];  
}
else
    t[i][j] = max(t[i][j-1], t[i-1][j]);  
}


// VERIFY THE BELOW
// Whoever has confusion in the following inputs :
// AABABCD
// AXXXY.  etc.
// Here is the explanation:
// Read this: Given a string, print the longest repeating subsequence such that the two subsequences don’t have same string character at same position
// The same Position is the twist here: A X X X Y ==> You can take X X [index0 and index1] and XX [index 1 and index2], one X is overlapping
// X of index1 is used in both but its position in both substrings is different. In the first subsequence, it comes at 1st index whereas in 
// the second subsequence comes at the 0th index.

// Case :- AABCABB 
// ANS :- 5 or 4 not sure 
// for string AABCABB
// for A- there are remaining two A's so ans=2
// for B- there are remaining two B's so ans=2+2
// for C- there are no remaining C so ans=2+2+0
// so final answer will be 2+2+0=4


