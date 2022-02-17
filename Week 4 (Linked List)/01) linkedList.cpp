Singly Linked list: Head -> A -> B -> C -> D -> NULL

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
    int val;       // val is int type
    Node *next;    // next will store the address of the next node, next is Node type
};

// JAVA
class Node{
    int data;
    Node next;
}

// Every node takes 4 (for val)+ 4 (for next) = 8 bytes of memory.

// Traversal in a linked list
// A program to create a linked list with three nodes and print it.
#include<bits/stdc++.h>
using namespace std;

// Linked list node
struct Node{
    int data;    // data
    Node *next;  // pointer
};

// Function to print contents of a linked list starting from a given node
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




// DELETION

// Delete the head(first) node

// Delete the tail(last) node

// Delete any particular node



