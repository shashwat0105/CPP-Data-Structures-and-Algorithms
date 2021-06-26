// https://www.geeksforgeeks.org/minimum-number-deletions-make-string-palindrome/

// Given a string of size ‘n’. The task is to remove or delete minimum number of characters from the string so that the resultant string is palindrome.
// Input : aebcbda
// Output : 2
// Remove characters 'e' and 'd'
// Resultant string will be 'abcba' which is a palindromic string

// minimum is asked hence DP ques
// Length of palindromic subsequence is inversely proportional to no. of deletion

// Hence, Longest palindromic subsequence will give min no of deletion
// ie :- "abcba" was nothing but LPS
// Hence :- min no of deletion = Length of string - LPS
//                             = Length of string - LCS(x, reverse(x))

// Ques is nothing but, to calculate min no of deletion to get longest palindromic subsequence.
