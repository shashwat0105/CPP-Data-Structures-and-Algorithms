https://leetcode.com/problems/fibonacci-number/

Tabulation , TC and SC = O(N)

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

Space optimised using two variables
TC = O(N), SC = O(1)

class Solution {
public:
    int fib(int n) {
        
        if(n<=1) return n;
        
        int prev2 = 0;
        int prev = 1;
        
        for(int i=2; i<=n; i++){
            int curi = prev + prev2;
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};

// Matrix Exponentiation
TC = O(logn)

Used to find large fibonacci numbers.

https://www.youtube.com/results?search_query=matrix+exponentiation+fibonacci
