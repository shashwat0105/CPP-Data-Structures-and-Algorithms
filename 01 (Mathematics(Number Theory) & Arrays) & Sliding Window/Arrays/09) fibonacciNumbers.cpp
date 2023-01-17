https://leetcode.com/problems/fibonacci-number

https://leetcode.com/problems/fibonacci-number/solutions/1159786/fibonacci-number-easy-solution-w-multiple-approaches-explained/

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

// We can space optimise this as well.
int fib(int n) {
	if(n <= 1)
		return n;
	int prev2 = 0, prev1 = 1, cur;
	for(int i = 2; i <= n; i++)
		cur = prev2 + prev1, prev2 = prev1, prev1 = cur;
	return cur;
}

// Golden Ration 
https://en.wikipedia.org/wiki/Fibonacci_number#Relation_to_the_golden_ratio
TC = O(1) or O(logn)
Works for small values of n only.

int fib(int n) {
	double goldenRatio = (1 + sqrt(5)) / 2;
	return round(pow(goldenRatio, n) / sqrt(5));
}


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
