// Time Complexity O(nlogn)
// Space Complexity O(n)
// Merge sort in Python :- 2.2nlog(n) micro seconds
// The recursion consists of O(logn) levels, and processing each level takes O(n) time. 
// Merging the subarrays array[a...k] and array[k+1...b] is possible in linear time, because they are already sorted.

// Divide & Conquer Algo
// We keep on dividing the list/array(using recursion) until we get the sublist/subarray of 1 element.
// Then we keep on merging the sublist until we get complete sorted list
// A separate merge function of 6 steps(has 4 arguments for fixed & 5 for dynamic size of array coz the size input from user is to be used in merge function) is used to merge the sorted sub-arrays

// https://simplesnippets.tech/merge-sort-algorithm-with-example-with-c-code-sorting-algorithms-data-structures/
// contains code for both fixed and dynamic size of array
    
#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r, int size) // backbone of the code used to merge after the splitting
{
    // Step 1. 3 variables 
    int i = l;     // keeps track of index of left sub array
    int j = mid+1;   // keeps track of index of right sub array
    int k = l;     // keeps track of index of temporary array

    // Step 2. Create temporary array
    int temp[size];

    // Step 3. Checking which value is smaller in either of the array(While loop when both sub arrays have some elements)
    while (i <= mid && j <= r)  // for left sub array valid indices are from i to mid, for right valid indices j to r
    {
        // Step 3.1
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        // Step 3.2
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    // Step 4. When right sub array is exhausted, hence transferring remaining elements of left subarray to temp array
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Step 5. When left sub array is exhausted, hence transferring remaining elements of right subarray to temp array
    while (j <= r)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    
    // Step 6. Copying elements from temp to our original array
    for(int p = l; p <= r; p++){
        arr[p]=temp[p];
    }

}

void mergeSort(int arr[], int l, int r, int size)  // l points to the leftmost index, r points to the righmost index
{
    if(l<r){

        // Step 1
        int mid = l + ((r-l)/2); // finding mid to divide array in 2 halfs

        // Recursion
        // Step 2
        mergeSort(arr, l, mid, size);  // Calling for first half (Every first half will be called recursively(can watch video))
        // Step 3
        mergeSort(arr, mid+1, r, size); // Calling for second half 

        // Step 4
        merge(arr, l, mid, r, size);  

    }
}

int main()
{
    cout<<"Enter size of array";
    int size;
	cin>>size;
	int arr[size];
	for(int i=0; i<size; i++)
	{
		cin>>arr[i];
	}
	
	// int result = mergeSort(arr, arr[0], arr[n-1]); this is wrong because then mid = arr[0] + arr[n-1]/2 i.e. the calculations will be on arr values instead of array index
    mergeSort(arr, 0, (size-1), size);  // this size is to be used to create temp array

    cout << "After Sorting" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}