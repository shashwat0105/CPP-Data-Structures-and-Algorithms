What is heap?

It is a "Complete binary tree" that comes with heap order properties.
// In a CBT all the levels are filled from the left side.

Max heap:
Every node has a value greater than its descendants.

Min heap:
Every node has a value smaller than its descendants.

/*
Array implementation with 1 based indexing.
If a node is at ith index, (i>=1) 
Then left child will be at 2*i th index.  
And the right child will be at 2*i + 1 th index.
Parent will be at i/2 index.

In a complete binary tree.
Leaf nodes = [n/2+1 to n] th index of the array.

Array implementation with 0 based indexing.
If a node is at ith index 
Then left child will be at 2*i+1 th index.  
And the right child will be at 2*i + 2 th index.
Parent will be at |(i-1)/2| index.

*/

// Property that the index of any node in a CBT will always be less than the total nodes in the tree


Eg: Array: 1 3 6 9 5 8
       1
    3     6
  9   5  8 
 
// Insertion:
Say: 55
Step 1: Insert at end index.
Step 2: Compare with parent element using i/2. and swap it ie placing it at its correct postition. (To repeat till it is at its correct postition)

// Code for insertion:

#include<bits/stdc++.h>
using namespace std;

class heap(){
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;

        while(index>1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    void deleteFromHeap(){  // deletes the root node 
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }
        arr[1] = arr[size];  
        size--;

        // taking root to its correct position
        int i = 1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex<size && arr[i]<arr[leftIndex]){
                swap(arr[leftIndex], arr[i]);
                i = leftIndex;
            }
            else if(rightIndex<size && arr[i]<arr[rightIndex]){
                swap(arr[rightIndex], arr[i]);
                i = rightIndex;
            }
            else return;
        }
    }
};

int main(){
    heap h;
    // Jo jo insert hoga wo left side se fill hoga in the BST

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteFromHeap();
    h.print(); 
    return 0;
}

TC = O(logn)


// DELETION
Case-01: Deletion of the leaf nodes
This case is straightforward to handle. We delete/disconnect the leaf node from the max heap in this case. 
After deleting the leaf node, we don’t need to change any value in the max heap.

Case-02: Deletion of some other node
This case is strenuous as deleting a node other than the leaf node disturbs the heap properties. This case takes two steps for deletion:
Delete the selected element from the given heap tree and replace the value of the last node with deleted node.
Check the max heap properties for the entire heap and keep calling the heapify() function until we get the max heap.
TC = O(logn)

// Extract min element from min heap
Swap last and root node.  // root node is minimum
Decrease the size
Call minHeapify at the root node
Return the last node.

//
For more practice
Refer
https://leetcode.com/discuss/general-discussion/1127238/master-heap-by-solving-23-questions-in-4-patterns-category
