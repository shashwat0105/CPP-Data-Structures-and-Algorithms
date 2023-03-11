// Using inbuilt priority queue class as a heap data structure.

// PRIORITY QUEUE
// First element of queue is greater than all other elements.
// Elements are in non-increasing order
// C++ creates a "max-heap" for priority queue.

#include <bits/stdc++.h>
using namespace std;

void showPriorityQueue(priority_queue<int> pq){
    priority_queue<int>q = pq;
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){
    priority_queue<int> q;
    q.push(10);
    q.push(-7);
    q.push(5);
    q.push(-3);

    showPriorityQueue(q);
}

// Syntax to create a min heap for priority queue 
priority_queue <int, vector<int>, greater<int>> g = gq;  

// If interview asks why such?
// used vector as an underlying container to store data values.
// we use greater<int> whenever we want to reverse the values.

// In case of numeric values, we can also multiply the values with -1 and use max heap to get the effect of min heap.
// While printing we can again *-1 and get back original.

// Create Priority Queue from exisiting:
1) Array
int arr[] = {15, 10, 20};
priority_queue <int> pq (arr, arr+3);  // Behind the scene TC of build a heap = O(N)

2) Vector
vector<int> v = {15, 10, 20};
priority_queue <int> pq(v.begin(), v.end());

// Push, Pop operations are done in O(logn) time
// empty(), size(), top() are checked in O(1) time 


// Custom Comparator:
// Priority queue to work with user defined classes/structures.
// https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/
// 1) Using custom comparator
// 2) Overloading the < operator
// Explained in the end of the video and gfg article, will add code when I find a ques on this.
 
// code:
class Compare{
public:
    bool operator()(int a, int b){
        return a>b;                  // max heap, a<b min heap
    }
}

// Identification of heap ques:
// K hoga ques mein
// Smallest largest etc 