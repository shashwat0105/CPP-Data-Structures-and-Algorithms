// https://leetcode.com/problems/single-number-ii/

// A = {5, 8, 2, 2, 8, 5, 8, 3, 5, 2}
// Ans = 3 // all numbers appears thrice except one, we need to return that

// write binary of all for observation
// 5 : 0101 ...and so on

// Let our soln be X (here X = 3)
// Let F[i] : number of elements with ith bit set
// Claim: if ith bit is set in X then F[i] would be of the form 3n+1, coz others having ith bit as set as well will be a multiple of 3
// Now, F[i]%3 = 1 for 3n+1 will indicate ith bit is set in our result, then we would increment the result by 2^i (initialise by 0)





// Python users, add this to handle negative numbers

// negThresh = 0x80000000

// mask = 0xFFFFFFFF
// if ans >= negThresh:
//     return ~(ans ^ mask)

// else:
//     return ans