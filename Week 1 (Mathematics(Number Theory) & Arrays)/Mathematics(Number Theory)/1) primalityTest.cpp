// To check an integer is prime or not and some other variations

// Naive Approach

bool isPrime(int n) { 
	// Corner case 
	if (n <= 1) return false; 

	// Check from 2 to n-1 
	for (int i=2; i<n; i++) // for n or n/2 time complexity is O(n)
		if (n%i == 0) 
			return false; 

	return true; 
}

// Better Approach - i<sqrt(n) -> O(sqrt(n))

bool isPrime(int n){
    if(n<=1) return false; 

    for(int i=2; i*i<=n; i++){
        if(n%i == 0) return false;
    }
    return true; 
}

// https://www.codechef.com/problems/PRB01

// Best approach
// Sieve of Eratosthenes

// Preprocessing time : O(N log(logN))
// Answers Query      : O(1)
// Extra space        : O(N)

// https://youtu.be/1K-NPoepIHc

// composite mark 0
// prime mark 1

int is_prime[1000001];

void sieve(){
    int maxN = 1000000;

    for(int i=1; i<=maxN; i++) is_prime=1;     // mark all the numbers as 1 ie prime
    is_prime[0]=is_prime[1]=0;                 // 0 and 1 are not prime so mark as 0

    for(int i=2; i*i<=maxN; i++){
        if(is_prime[i]){                       // if ith number is a prime number
            for(int j=i*i; j<=maxN; j+=i){     // we start from its square till maxN we mark every multiple of i
                is_prime[j]=0;                 // for each next multiple of prime we mark it as 0
            }
        }
    }
}


// https://www.spoj.com/problems/TDKPRIME/
// Because bool is just one bit and integer is 4 bits 
// As time limits are strict for this question
// Since, by default all elements are initialised by 0 (for int), false (for bool) array
// Prime = False (We will use)  (reverse of above)
// Not prime = True
// For max k(5000000) the prime number is 86 million something, so here I have taken 90 million

#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
bool ar[90000001];

void sieve(){
    int maxN = 90000000;

    ar[0] = ar[1] = true; 

    for(int i=2; i*i<=maxN; i++){
        if(!ar[i]){
            for(int j=i*i; j<=maxN; j+=i){
                ar[j]=true;  
            }
        }
    }

    for(int i=2; i<=maxN; i++){
        if(!ar[i]){
            primes.push_back(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q, n;
    cin>>q;
    sieve();

    while(q--){
        cin>>n;
        cout<<primes[n-1]<<endl;
    }
}
