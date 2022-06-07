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

// Hence, Worst case length = m + n
// Best case(length of shortest supersequence) = (m+n) - LCS   // Ans

return m+n -LCS(x, y, m, n);
