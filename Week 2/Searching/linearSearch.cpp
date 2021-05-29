// Or sequential search

#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int k)
{
	for(int i=0; i<n; i++)
	{
		if(k==arr[i])
			return (i);
	}
	return -1;
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	int k;
	cin>>k;
	
	int result = linearSearch(arr, n, k);
	cout<<result;
    return 0;
}

