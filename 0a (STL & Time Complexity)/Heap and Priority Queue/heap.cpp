What is heap?

It is a Complete binary tree that comes with heap order properties.
// In a CBT all the levels are filled from the left side.

Max heap:
root node element is greater than both the child nodes.

Min heap:
root node is less than both the child nodes.

//
If a node is at ith index in an array implementation. (i>=1)
Then left child will be at 2*i th index.  
And the right child will be at 2*i + 1 th index.
Parent will be at i/2 index.

// In a complete binary tree.
// Leaf nodes = [n/2+1 to n] th index of the array.

// Property that the index of any node in a CBT will always be less than the total nodes in the tree


Eg: Array: X 60 50 40 30 20 

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

    void deleteFromHeap(){
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
                swap(arr[leftIndex],arr[i]);
                i = leftIndex;
            }
            else if(rightIndex<size && arr[i]<arr[rightIndex]){
                swap(arr[rightIndex],arr[i]);
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

// TC = O(logn)


// DELETION
Means deleting the last node.

Step1: Swap the root node with the last node(in the array).
Step2: Delete the last
Step3: Propagate the root node to put it to its correct position.

TC = O(logn)
