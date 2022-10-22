Step 1: Build K size max heap for first k elements.
Step 2: If element < heap.top() 
        heap.pop()
        heap.push(element)
        The heap will have k smallest numbers and,
        heap.top will be the kth smallest number. Ans.


https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int> pq; // it is a max heap
        // step 1
        for(int i=0; i<k; i++){
            pq.push(arr[i]);
        }
        
        // step 2
        for(int i=k; i<=r; i++){   // because r is the index. We want for all remaining elements
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        return pq.top();
    }
};

// OR
// Bina compare kiye
 int kthSmallest(int arr[], int l, int r, int k) {
    //code here
    priority_queue<int>max_heap;
    for(int i = 0; i <= r; i++){
        max_heap.push(arr[i]);    // when there will be say 4 elments and k was 3. Then the largest will automatically come at top, we simply need to pop it. Instead of comparing seedha daal do andar.
        if(max_heap.size() > k){
            max_heap.pop();
        }
    }
    return max_heap.top();
    
}


//
Time complexity: O(K log K +  (N – K) log K) = O(nlogk)
Auxiliary Space: O(K)

Quick select O(N)
// https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-2-expected-linear-time/
