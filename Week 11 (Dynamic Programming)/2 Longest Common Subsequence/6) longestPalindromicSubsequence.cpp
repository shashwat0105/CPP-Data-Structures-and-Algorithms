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

string y = reverse(x.begin, x.end);

// Longest common substring
// VERIFY the below sentences
// Like Longest Common Subsequence is to Longest Palindromic Subsequence, It is Longest Common Substring to Longest Palindromic Substring
// Sorry, above approach will fail for "abcdba" 
// Longest palindromic substring is something you cant solve by the stuff I taught you. (aditya verma)
// I think the 27th video was "Longest Palindromic Substring". It looks like an LCS variation. But there is one case where LCS fails in that problem and gives wrong answer.
// We could see that the lcs method fails when there exists a reversed copy of a non-palindromic substring in some other part of String
