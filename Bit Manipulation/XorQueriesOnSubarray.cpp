// https://leetcode.com/problems/xor-queries-of-a-subarray/

// Given an array of integers and Q queries
// To find XOR of elements from index L to R  in every query

// TC = O(1)

// Approach
// Creating a prefix array 
// Sample array : [1, 3, 4, 8]
// prefix[i] = A0^A1^A2^A3...^Ai
// prefix = [1, 2, 6, 14]

// After this preprocessing
// Ans of each query L, R -> prefix[R] ^ prefix[L-1] ; if L > 0
//                           prefix[R]               ; if L = 0

// Proof:- prefix[R] ^ prefix[L-1] = (A0^A1^A2...^AL...^AR)^(A0^A1^...AL-1) // the same terms will become 0, using 2 properties
//                                 = AL^AL+1^...^AR = XOR from index L to R


