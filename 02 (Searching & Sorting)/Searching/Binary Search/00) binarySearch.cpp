https://leetcode.com/tag/binary-search/discuss/691825/Binary-Search-for-Beginners-Problems-or-Patterns-or-Sample-solutions
https://leetcode.com/wh0ami/ -> go to discuss for his other posts.

https://www.youtube.com/playlist?list=PLauivoElc3gjE_s-7owHO0RVb_jj7Rx85
Watch last three videos during revision.
https://youtu.be/W9QJ8HaRvJQ  Iske bhi kuch ques like search in duplicate array revise kar skte ar apne code ko compare kar skte

// Binary Search :- The idea of binary search is to use the information that the array is sorted and reduce the time complexity to O(Log n). 
// We use while loop in binary search. while(l<=r)

// Ternary Search same as binary search, we divide into 3
// Time complexity = O(log base 3 n)

// i & j are made mid + 1 & mid -1 not just mid because then i<j will never fail & it will get into an infinite loop for searching max element 
// or value greater than max element

// In this code I have used s and e instead of i and j.

// Binary search returns the index of the element we are searching

int binary_search(int arr[], int n, int key){
    int s=0;
    int e=n-1;

    int mid;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(key==arr[mid]){
            return mid;                      // mid is the index of the found element
        }
        else if(key < arr[mid]){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;                               // key not found 
}

// If the array was sorted in 

// Finding TC
// Loop runs k times
// After k iterations size of the array becomes N/(2^k) which is also equal to 1 element left.
// Hence, N/(2^k) = 1 
// k = log2(n)

// Using equation:
T(N) = k + T(N/2)
 
// Binary search questions:
1) Binary search
2) Order agnostic BS  // Asc or Desc not known but it is sorted, so we compare any two elements.
3) 1st and Last occurence of an element
4) count of elment in an sorted array  // last occurence - first occurence + 1
5) No. of times sorted array is rotated
6) Find an element in rotated sorted array
7) Searching in nearly sorted array
8) Floor and ceil of an element
9) Next letter
10) Index of last 1 in sorted array
11) Find the position of an element in an infinite sorted array
12) Min difference element in a sorted array
13) Bitonic array max element
14) Search in bitonic array
15) Search in rowise and columnwise sorted array
16) Find element in sorted array that appears once
17) Allocate minimum number of pages (Important, variation asked by flipkart)

"sorted" word -> implies isme Binary search lagegi
Binary search on answer - Array is not sorted still we apply binary search.
