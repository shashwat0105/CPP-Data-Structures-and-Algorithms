

// some good LC discuss
Binary exponentiation
https://leetcode.com/problems/powx-n/solutions/1337794/java-c-simple-o-log-n-easy-faster-than-100-explained/
https://leetcode.com/problems/powx-n/solutions/739646/c-iterative-vs-recursive-bitwise-solutions-explained-100-time-80-space/

// recursion solution/ binary exponentiation

class Solution {
public:
    double solvePow(double x, int n){
        if(n==0) return 1;
        if(n==1) return x;

        double ans = solvePow(x, n/2);
        if(n&1) return x*ans*ans; // odd case // x multiplied with itself and power divided by two
        else return ans*ans;      // even case
    }

    double myPow(double x, int n) {
        if(n<0){
            return 1/solvePow(x, n);
        } 
        return solvePow(x, n);
    }
};

//
say 2^10 = (2*2)^5
5 is odd 
4^5 = 4*(4^4) = 4*256 = 1024
4^4 = (16)^2
16^2 = (16*16)^1 = 256^1
256^1 = (256)*(256)^0

// other way could be

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long nn = n; // make a copy
        if(nn<0) nn = -1*nn;
        while(nn){
            if(nn&1){ // same as nn%2  // odd power
                ans = ans * x;  // multiply once explicitly and make power even
                nn = nn-1;      // reduce power by 1
            }
            else{
                nn = nn/2;
                x = x*x;
            }
        }
        if(n<0) ans = (double)(1.0)/(double)(ans);
        return ans;
    }
};



