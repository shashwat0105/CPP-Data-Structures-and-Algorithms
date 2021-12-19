// Binary Search :- The idea of binary search is to use the information that the array is sorted and reduce the time complexity to O(Log n). 
// We use while loop in binary search. while(l<=r)

// Ternary Search same as binary search, we divide into 3
// Time complexity = O(log base 3 n)

// i & j are made mid + 1 & mid -1 not just mid because then i<j will never fail & it will get into an infinite loop for searching max element or value greater than max element

// In this code I have used s and e instead of i and j.

int binary_search(int arr[], int n, int key){
    int s=0;
    int e=n-1;

    int mid;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;                                // key not found 
}

// Finding TC
// Loop runs k times
// After k iterations size of the array becomes N/(2^k) which is also equal to 1 element left.
// Hence, N/(2^k) = 1 
// k = log2(n)

// Using equation:
T(N) = k + T(N/2)
 
