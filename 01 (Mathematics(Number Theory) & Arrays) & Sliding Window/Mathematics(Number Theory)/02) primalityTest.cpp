// To check an integer is prime or not and some other variations

// Naive Approach
Naive Method to Check if a number is Prime: Since a number is prime only if it is divisible by 1 and the number itself, 
the naive method to check for primality of a number would be to iterate from 1 to N and check if there arent any factors of N 
except and 1 and N itself.

TC = O(N).

All prime numbers are of the form 6k+-1, except 2 & 3.

bool isPrime(int n) { 
	// Corner case 
	if (n <= 1) return false; 

	// Check from 2 to n-1 
	for (int i=2; i<n; i++) // for n or n/2 time complexity is O(n)
		if (n%i == 0) 
			return false; 

	return true; 
}

// Better Approach - i<sqrt(n) -> O(sqrt(n)) // To check 'a' number is prime or not this is best.

bool isPrime(int n){
    if(n<=1) return false; 

    for(int i=2; i*i<=n; i++){
        if(n%i == 0) return false;
    }
    return true; 
}

OR By finding the number of factors/divisors. (Striver)

bool isPrime(int n){
    int cnt = 0;  // Will store the number of factors of n
    for(int i=1; i*i<=n; i++){
        if(n%i == 0){                  // If a number completely divides then I will also count its counterpart.
            cnt++;
            if(i!=(n/i)) cnt++;
        }
    }
    return (cnt==2); 
}

// You can also use the above code to print all the divisors.

// https://www.codechef.com/problems/PRB01

// Sieve of Eratosthenes is the most efficient way of generating prime numbers upto a given number N.

Steps:
We store the numbers 1-N in a DS say vector.
We now move on a number say 2, (it is unmarked we add it to our ans) ans mark all the multiples of 2 as notprimes.
Similary we do it for 3 and so on. 

https://youtu.be/ATyAnOCI1Ms (GFG)

// Preprocessing time : O(N log(logN))
// Answers Query      : O(1)
// Extra space        : O(N)

// composite mark 0
// prime mark 1

Optimisation: We start at num^2 because every multiple up to the num th multiple will have been guaranteed to have been seen before, 
since they are also a multiple of a smaller number. 

#include <bits/stdc++.h>
using namespace std;

vector<int> sieveOfEratosthenes(int n) {
    vector<bool> sieve(n + 1, true); // Initialize a boolean array to mark numbers as prime
    vector<int> primes; // Vector to store the prime numbers
    sieve[0] = sieve[1] = 0;
    for (int p = 2; p * p <= n; ++p) {
        if (sieve[p]) {
            for (int i = p * p; i <= n; i += p) {
                sieve[i] = false; // Mark multiples of p as not prime
            }
        }
    }
    
    // Push prime numbers into the vector including n
    for (int i = 2; i <= n; ++i) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}


int main() {
	int n;
	cin>>n;
	vector<int> ans = sieveOfEratosthenes(n);
	for(auto ele: ans){
	    cout<<ele<<" ";  // Print all the prime numbers <=n
	}
	return 0;
}

Practice Problems:
https://leetcode.com/problems/count-primes
https://leetcode.com/problems/prime-pairs-with-target-sum/

https://www.spoj.com/problems/TDKPRIME/
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
