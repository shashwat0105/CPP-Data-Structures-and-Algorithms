// To calculate a^n in O(logn) time

// Naive approach

int power(int base, int n){
    int res=1;
    for(int i-1; i<=n; i++){
        res=res*base;
    }
    return res;
}

// Binary Exponentiation
// If power is odd, res = base*res and reduce power by 1
// If power is even, base*=2, and power/=2

// Example 2^13
res     base    power
1         2       13
2         2       12
2         4       6
2         16      3
32        256     2
32        256     1
8192      256     0
// (final result when power becomes 0)
// TC = O(log n)

int power(int a, int n){
    int res=1;

    while(n){
        if(n%2){               // power is odd
            res*=a;
            n--;
        }
        else                   // power is even
            a*=a;
            n/=2;
    }
    return res;
}
 
// Modular Exponentiation
// To calculate a^n mod p
// p is some prime number

int power(int a, int n, int p){
    int res=1;

    while(n){
        if(n%2){
            res=(res*a)%p;
            n--;
        }
        else
            a=(a*a)%p;
            n/=2;
    }
    return res;
}
