// Prime Factorization
// 100 = (2^2)*(5^2)

// Brute force approach
// Worst case TC = O(n) when n is a prime number

void primeFactorisation(int n){
    for(int i=2; i<n; i++){
        if(n%i==0){
            int cnt = 0;
            while(n%i==0){
                cnt++;
                n/=i;                  // N=100 -> 50 -> 25, exit from for loop, check for numbers dividing 25, we get 5: 25->5->1
            }
            cout<<i<<"^"<<cnt<<endl;
        }
    }
}

// Optimised Approach
// Claim: If n is a composite number then there is atleast 1 prime divisor of n below sqrt n
// TC = O(sqrt n)
// Say n = (7^3)*(23^1)

void primeFactorisation(int n){
    for(int i=2; i*i<n; i++){
        if(n%i == 0){
            int cnt = 0;
            while(n%i == 0){
                cnt++;
                n/=i;
            }
            cout<<i<<"^"<<cnt<<endl;
        }
        if(n>1){                      // case when n is smaller than i*i, ie n*1 is left
            cout<<n<<"^"<<"1"<<endl;
        }
    }
}
 
// Using Sieve to calculate prime factorisation
// TC = O(logn)



