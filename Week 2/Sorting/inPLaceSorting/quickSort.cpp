// Time Complexity  O(n log n) in best and average case, in worst case it is o(n^2)
// Space Complexity O(log n) // more efficient than merge sort.
// Divide & Conquer algo
// In Place algo ie without using any temporary space instead by in place swaps. 
// Partitioning around a PIVOT (At which left side all elements smaller than pivot, right side all elements larger than pivot)
// Pivot can be chosen as first, last(our code), any random element of the array.

#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r)   // backbone, here the sorting happens
{
    // Step 1: Selecting the last element & set it as pivot 
    int pivot = arr[r];
    // Step 2: Another integer to keep a track of elements smaller than pivot element and is incremented everytime a smaller element is swapped to the left.
    int pIndex = l;

    // Step 3: For loop to shift all the smaller elements to the leftmost part of the array, Pivot is only compared neither touched nor moved here
    for(int i=l; i <= r-1; i++)
    {
        if(arr[i]<pivot)
        {
            swap(arr[i], arr[pIndex]); //i.e. shifting smaller values(pIndex) to leftmost(i = 0, 1 etc positions) Pivot element is not touched yet
            // int temp = arr[i];
            // arr[i] = arr[pIndex];
            // arr[pIndex] = temp;
        
            pIndex++;
        }
    }

    // Step 4: Taking the pivot element and bringing it to pIndex position 
    swap(arr[r], arr[pIndex]);
    // int temp = arr[r];
    // arr[r] = arr[pIndex];
    // arr[pIndex] = temp;

    // Step5: Returning the final position of Pivot i.e. pIndex value
    return pIndex;
}

void quickSort(int arr[], int l, int r)
{
    if(l < r)
    {
    // Step 1: Find partition index i.e. where we are supposed to partition everytime(till left index < right index)
    int p = partition(arr, l, r);  // p is the partition index(position of pivot finally) we got from partition function 

    // Step 2: Call quick sort for left partition
    quickSort(arr, l, p-1);
    // Step 3: Call quick sort for right partition
    quickSort(arr, p+1, r);
    }
}

int main()
{
    cout<<"Enter size of array";
    int size;
	cin>>size;
	int myarr[size];  // can use arr as well, to show they are different i have chosen a different name
	for(int i=0; i<size; i++)
	{
		cin>>myarr[i];
	}

    quickSort(myarr, 0, (size-1));  // we don't use square bracket when we pass an array into a function

    cout << "After Sorting" << endl;
    for (int i = 0; i < size; i++) 
    {
        cout << myarr[i] << " ";
    }
    return 0;
}