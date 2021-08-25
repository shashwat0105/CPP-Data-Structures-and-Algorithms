// Simple Method 1 using a temporary array
// Time complexity = O(n), Space Complexity = O(d),, d is how many elements you want to shift
void rotateArray(int arr[], int n, int d)
{
    int temp[d]; // 1, 2
    for(int i=0; i<d; i++)
    { 
        temp[i] = arr[i];  //copying the elements of the array in temporary array
    }
    for(int i=0; i<n-d; i++)
    {
        arr[i]=arr[i+d];      // 1,2,3,4,5,6,7  -> 3,4,5,6,7,6,7 shifting of array elements
    }
    for(int i=0; i<d; i++)
    {
        arr[i+n-d]=temp[i]; //copying elements back from temporary array to old array 3,4,5,6,7,6,7 → 3,4,5,6,7,1,2
    }
}   

// Method 2 using temporary variable
// The idea is to rotate the array one by one d times.
// Time complexity = O(n * d), Space complexity = O(1) Which is not better than previous one, 
// but for say constraint of not using any extra space like in previous case we used an extra array of space d is given in the ques/interviewer.
void rotate(int arr[], int n)
{
    int temp = arr[0];   //storing the first element in a temporary variable
    for(int i=0; i<n-1; i++)
    {
        arr[i]=arr[i+1]; //shifting the array
    }
    arr[n-1]=temp;
}
 
void rotateArray(int arr[], int n, int d)
{
    for(int i=0; i<d; i++)
        rotate(arr, n);  //calling the rotate function d times
}

// Method 3 Most effective , Juggling algo
// Time complexity = O(n), Space Complexity = O(1) 
//  ∵ No extra space we have used.
// function to reverse an array from index start to end
void reverseArray(int arr[], int start, int end)
{
    while(start<end)
    {
        int temp = arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end++;
    }
}
//function to left rotate arr[] of size n by d
void leftRotate(int arr[], int d, int n)
{
    if(d == 0)
        return;
    reverseArray(arr, 0, d-1);
    reverseArray(arr, d, n-1);    
}

// C++ program to rotate an array by 
// d elements 
#include <bits/stdc++.h> 
using namespace std; 

/*Fuction to get gcd of a and b*/
int gcd(int a, int b) 
{ 
	if (b == 0) 
		return a; 

	else
		return gcd(b, a % b); 
} 
/*Instead of moving one by one, divide the array in different sets
where number of sets is equal to GCD of n and d and move the elements within sets.
If GCD is 1 as is for the above example array (n = 7 and d =2), then elements will be moved within one set only, 
we just start with temp = arr[0] and keep moving arr[I+d] to arr[I] and finally store temp at the right place. */
// Best YT Video https://youtu.be/utE_1ppU5DY 
/*Function to left rotate arr[] of size n by d*/
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
 if(b==0)
  return a;
 else
  return gcd(b, a%b);
}

void ArrayRotate (int A[], int n, int k)
{
 int d=-1,i,temp,j;
 for(i=0;i<gcd(n,k);i++)
 {
  j=i;
  temp=A[i];
  while(1)
  {
   d=(j+k)%n;
   if(d==i)
    break;
   A[j]=A[d];
   j=d;
  }
  A[j]=temp;
 }
}

void displayArray(int A[],int n)
{
 int i;
 for(i=0;i<n;i++)
  cout<<A[i]<<" ";
 cout<<"\n";
}

int main()
{
  int n,i,k;
  cout<<"Enter size of the Array\n";
  cin>>n;
  int A[n];
  cout<<"Enter Array elements\n";
  for(i=0;i<n;i++)
   cin>>A[i];
  cout<<"Enter the value of k\n";
  cin>>k;
  displayArray(A,n);
  ArrayRotate(A,n,k);
  displayArray(A,n);
  return 0;
}


