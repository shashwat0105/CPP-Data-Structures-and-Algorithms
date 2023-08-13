// Takes an eleement and place it in its correct order.

// Time complexity O(n^2) :- we have n steps(comparison) and every step can take n (swap) time to execute
// Best case time complexity is O(n) coz O(n) comparisons & O(1) swaps (Already sorted in ascending order is best, sorted in descending is worst)
// Space complexity O(1)
// Insertion sort is also known as online algo(coz as soon as we get this algo starts sorting)
// Insertion sort in Python :- 0.2 n^2 micro seconds
// Insertion sort in C :- 0.01 n^2 micro seconds (20 times faster)

// Binary insertion sort
// Do a binary search on A[0: i-1] already sorted in O(logi) time, hence O(nlogn) for compares but O(n^2) for swaps

// One for, one while loops are used
void insertionSort(int arr[], int n)
{
    for(int i=0; i<n; i++)  // one loop incremented from left to right
    {
        int j = i;          // j will compare i with all the elements left of i

        while(j>0 && arr[j-1] > arr[j]){  // other loop decremented from right to left
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}
