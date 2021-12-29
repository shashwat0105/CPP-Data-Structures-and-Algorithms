https://leetcode.com/problems/fibonacci-number

// Method 1:
// Recursion:
// TC = O(n)

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

