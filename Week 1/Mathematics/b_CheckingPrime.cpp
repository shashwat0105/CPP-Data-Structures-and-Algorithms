// number is prime 
#include <bits/stdc++.h> 
using namespace std; 

bool isPrime(int n) 
{ 
	// Corner case 
	if (n <= 1) return false; 

	// Check from 2 to n-1 
	for (int i=2; i<n; i++) // for n or n/2 time complexity is O(n), i<sqrt(n) -> O(sqrtn)
		if (n%i == 0) 
			return false; 

	return true; 
} 

// Driver Program to test above function 
int main() 
{ 
	int n;
	cin>>n;
	if(isPrime(n))
	{
		cout<<"True";
	}
	else
	{
		cout<<"False";
	}
	
	// isPrime(11)? cout << " true\n": cout << " false\n"; 
	// isPrime(15)? cout << " true\n": cout << " false\n"; 
	return 0; 
} 
