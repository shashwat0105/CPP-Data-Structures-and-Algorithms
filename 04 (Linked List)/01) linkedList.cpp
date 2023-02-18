Singly Linked list: Head -> A -> B -> C -> D -> NULL

// Better ki variable name k paas star lagaya karo
// ie Node *x, *y, *temp

Some Reference Link
https://practice.geeksforgeeks.org/tracks/dsa-workshop-1-linkedlist/?batchId=308
GFG Linked List is good too.

// To implement stack and queue we use either arrays or linked lists.
// Hence, Linked Lists are used to 
// 1) implement stacks and queues.
// 2) Image gallery (Doubly linked list)
// 3) Music player (Doubly linked list)
// 4) Web browser (Doubly linked list)
// 5) Hashmap and Hashsets (To avoid collisons in them we use chaining technique which uses linked list)

SINGLY LINKED LIST

NODE SYNTAX:
// C++
struct Node{       // creating a new data type whose name is "Node"
    int data;      // data is int type
    Node *next;    // next will store the address of the next node, next is Node type
};

// JAVA
class Node{
    int data;
    Node next;
}

// Every node takes 4 (for val) + 4 (for next) = 8 bytes of memory.

// Traversal in a linked list
// A program to create a linked list with three nodes and print it.
#include<bits/stdc++.h>
using namespace std;

// Linked list node
struct Node{
    int data;    // data
    Node *next;  // pointer
};

// Function to print contents of a linked list starting from a given node (Linked list traversal).
void printList(Node *node){
    while(node!=NULL){
        cout<<node->data<<" ";
        node = node->next;
    }
}

// Program to create a linked list with three nodes
int main(){
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // allocate 3 nodes in the heap  (THree blocks have been allocated dynamically using the "new" keyword)
    head = new Node;
    second = new Node;
    third = new Node;

    head->data = 1;       // assign data in the first node
    head->next = second;  // link first node with the second node

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // Print the linked list
    printList(head);

    return 0;
}



// Difference between Arrays and LinkedList (IMP)
https://youtu.be/KMc-B051ne8
1) In memory allocation LL are more efficient than arrays.
2) We dont have random access in LL.
3) Sorting and Searching requires random access hence we have to use arrays in this case.
4) Insert/Delete is O(1) in LL whereas we need to shift all elements in arrays hence it is O(1)


// STL for Singly LinkedList
https://www.cplusplus.com/reference/forward_list/forward_list/

forward_list<int>              // integer type singly linked list   

insert_after
erase_after                    // Jo aap doge uske baad wala hi delete hoga

// In forward list, jo delete krna hai uske phle wala node dena padega
// But in doubly linked list, jo delete krna hai wahi node dedo kaam ho jaega(thats an advantage of DLL)

// STL for doubly LinkedList
https://www.cplusplus.com/reference/list/list/

list<int>

insert
erase                         // Jo doge wahi delete ho jaega
  


// Summary of problems
https://leetcode.com/problems/add-two-numbers/discuss/1340/A-summary-about-how-to-solve-Linked-List-problem-C%2B%2B

