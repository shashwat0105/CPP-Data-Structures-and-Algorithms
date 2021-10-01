// C++ program to print all possible substrings of a given string
#include<bits/stdc++.h>
using namespace std;

// Function to print all sub strings
void subString(char str[], int n) 
{
	// Pick starting point
	for (int len = 1; len <= n; len++) 
	{ 
		// Pick ending point
		for (int i = 0; i <= n - len; i++) 
		{
			// Print characters from current
			// starting point to current ending
			// point. 
			int j = i + len - 1;		 
			for (int k = i; k <= j; k++) 
				cout << str[k];
			
			cout << endl;
		}
	}
}

// Driver program to test above function
int main() 
{
	char str[] = "abc";   // ac is not a substring
	subString(str, strlen(str));
	return 0;
}
