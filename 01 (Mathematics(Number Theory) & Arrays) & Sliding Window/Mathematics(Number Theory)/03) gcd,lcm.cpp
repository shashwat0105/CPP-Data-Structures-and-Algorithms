GCD:-

Method 1:
int func(int n1, int n2){
    int ansGCD = 1; // 1 toh gcd hoga hi
    for(int i=1; i<=min(n1, n2); i++){
        if(n1%i==0 && n2%i==0) ansGCD = i;
    }
    return i;
}

Method 2: Traverse from the back // Improved but worst case still the same
int func(int n1, int n2){
    int ansGCD = 1; // 1 toh gcd hoga hi
    for(int i=min(n1, n2); i>=0; i--){
        if(n1%i==0 && n2%i==0) ansGCD = i, break;  // breaks from the for loop
    }
    return i;
}

Method 3
Eucledian Algorithm:
gcd(a, b) = gcd(a-b, b)  // a>b
We can keep on performing the above stuff and will look like a divide operation. Ultimately one will become 0.

Iterative code:
int gcd(int a, int b){
    while(a>0 && b>0){
        if(a>b) a = a%b;
        else b = b%a;
    }
    if(a==0) return b;
    return a; 
}

Recursive code:
gcd(a, b){
   if (a == 0)
       return b;

   return gcd(b % a, a);
}

TC: O(log(min(a, b)))
Important properties of LCM and HCF:
1. For two numbers say, 'a' and 'b', LCM x HCF = a x b.
2. HCF of co-primes = 1.
3. For two fractions,
    HCF = HCF (Numerators) / LCM (Denominators)
    LCM = LCM (Numerators) / HCF (Denominators)

FACTORIAL :-
Trailing 0s in N! = Count of 5s in prime factors of n!
                 = floor(n/5) + floor(n/25) + floor(n/125) + ....

Inbuilt GCD function in C++ :- __gcd(a,b)

cout<<__gcd(10,40); //output: 10

In C++17, a new STL function for calculating LCM of two numbers, std::lcm(), has been introduced, 
which can be used on any compiler supporting C++17 features.
