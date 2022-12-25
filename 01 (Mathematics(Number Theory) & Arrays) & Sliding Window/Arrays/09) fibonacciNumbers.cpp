https://leetcode.com/problems/fibonacci-number

// Method 1:
// Recursion:
// TC = O(2^n), SC = O(n)

class Solution {
public:
    int fib(int n) {
        
        if(n<2){
            return n;
        }
        return fib(n-1)+fib(n-2);
    }
};


// Method 2: Dynamic Programming
// TC = O(n)
class Solution {
public:
    int fib(int n) {
        
        int f[n+2];
        f[0] = 0;
        f[1] = 1;
        
        for(int i=2; i<=n; i++){
            f[i] = f[i-1] + f[i-2];
        }
        return f[n];
    }
};

// Tiling problem (Similar to fibonnaci)
https://www.geeksforgeeks.org/tiling-problem/
// using recursion 2^n TC
// For 4*N, 1*4 data
class Solution {
  public:
    long long numberOfWays(long long N) {
        //code here
        if(N<4) return 1;
        
        return numberOfWays(N-1) + numberOfWays(N-4);
    }
};

// Optimised using DP
https://www.geeksforgeeks.org/count-number-ways-tile-floor-size-n-x-m-using-1-x-m-size-tiles/


// Count strings (similar to fibonnaci)
https://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/

Using this method O(2^N)
Using DP can be done in O(N)
Using matrix exponentiation can be done in O(k^3 logn) time (isko bhi seekhna hai for competetive programming)

// FRIENDS PAIRING PROBLEM (SIMILAR TO FIBONACCI)
https://www.geeksforgeeks.org/friends-pairing-problem/

f(n) = f(n – 1) + (n – 1) * f(n – 2)
