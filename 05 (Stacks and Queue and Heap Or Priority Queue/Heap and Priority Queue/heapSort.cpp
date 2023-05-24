O(nlogn) = TC
ie heapify of n elements will take nlogn time.

// Steps:
// 1) Given array -> Form a max heap using build heap function // TC = O(N) 
// 1) swap last element with root(max element)
// 3) Reduce size of heap.
// 4) Take root to its correct position, ie Call heapify at 0 index.

Heap sort is inspired from selection sort O(n^2).

https://practice.geeksforgeeks.org/problems/heap-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// CODE
class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  {
      // Your Code Here
      int largest = i;
      int l = 2*i+1;
      int r = 2*i+2;
      if(l<n && arr[l] > arr[largest]) largest = l;
      if(r<n && arr[r] > arr[largest]) largest = r;
      
      if(largest!=i){
          swap(arr[i], arr[largest]);
          heapify(arr, n, largest);           // jisse swap hua hai uske liye heapify call karenge
      }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  { 
    // Your Code Here
        for(int i=(n-2)/2; i>=0; --i){  // parent= |i-1|/2 and here i=n-1 ie last wale ka parent se call karenge
              heapify(arr, n, i); 
        }
    }

    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr, n);   // first we make max heap of n elements
        for(int i=n-1; i>=0; --i){
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);  // we are disturbing the root(0) element 
        }
    }
};
