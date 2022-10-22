https://www.codingninjas.com/codestudio/problems/build-min-heap_1171167

#include <bits/stdc++.h> 
using namespace std;

void heapify(vector<int> &arr, int n, int i){
    int smallest = i;  // The element that needs to be taken to correct place.
    int left = 2*i+1;  // coz 0 based indexing.
    int right = 2*i+2;

    if(left<n && arr[smallest] > arr[left]){
        smallest = left;
    }
    if(right <n && arr[smallest] > arr[right]){
        smallest = right;
    }

    if(smallest!= i){  // ie largest has been updated
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);  // recur again for remaining
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n = arr.size();
    for(int i=n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }
    return arr;
    
}


// Building a heap is O(N)
// heapify is O(logn)
