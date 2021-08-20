// Given an array of integers. Find a peak element in it. 
// An array element is a peak if it is NOT smaller than its neighbours. 
// For corner elements, we need to consider only one neighbour. // In this case Peak always exists
// Consider the following modified definition of peak element. 
// An array element is a peak if it is greater than its neighbours. 
// Note that an array may not contain a peak element with this modified definition.

int findPeak(arr[], low, high, n) 
{
    int mid = low + (high - low)/2 /* (low + high)/2 */
  
    if ((mid == 0 || arr[mid-1] <= arr[mid]) && 
            (mid == n-1 || arr[mid+1] <= arr[mid])) :
        return arr[mid]
  
    // If middle element is not peak and its left neighbour is greater  
    // than it, then left half must have a peak element 
    else if (mid > 0 && arr[mid-1] > arr[mid]) :
        return findPeak(arr, low, (mid -1), n)
  
    // If middle element is not peak and its right neighbour is greater 
    // than it, then right half must have a peak element 
    else :
        return findPeak(arr, (mid + 1), high, n)
} 


// In 2D array finding peak element
// By brute force time complexity is O(n*m)
// By optimisation it is O(mlogn)
