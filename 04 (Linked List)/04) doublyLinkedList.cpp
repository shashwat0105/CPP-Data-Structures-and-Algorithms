Good video:
https://youtu.be/cTm0AR5_O54

In Doubly linked lists 

Each node contains two pointers, one pointing to the next node and the other pointing to the previous node.
The prev of Head node is NULL, as there is no previous node of Head.
The next of last node is NULL, as there is no node after the last node.

// C++ Implementation

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};


// Advantage:
// In a singly linked list, to delete a node, a pointer to the previous node is needed. To get this previous node, sometimes the list is traversed. 
// In DLL, we can get the previous node using the previous pointer.


// Disadvantage:
// Every node of DLL requires extra space for a previous pointer.
// All operations require an extra pointer previous to be maintained. For example, an insertion, we need to modify previous pointers together with next pointers.


// CREATING AND TRAVERSING A DLL

#include<bits/stdc++.h>
using namespace std;

// A linked list node
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to print a DLL starting from a given node
void printList(struct Node *node){
    struct Node *temp;

    // Traversing in forward direction
    while(node!=NULL){
        cout<<node->data<<" ";
        temp = node;
        node = node->next;
    }

    // Traversing in backward direction
    while(temp!=NULL){     // here coz temp is pointing to last node
        cout<<temp->data<<" ";
        temp =  temp->prev;
    }
}

/* Given a reference (pointer to pointer) to the head of a DLL and an int, this function inserts a new node at the end */
void append(struct Node **head, int new_data){
    // Allocate node
    Node *new_node = new Node;

    // Put in data
    new_node->data = new_data;

    // his new node is going to be the last node, so make next of it as NULL 
    new_node->next = NULL;

    // If linkedlist is empty then make new node as head
    if(*head == NULL){
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    // Else traverse till the last node
    while(temp->next != NULL){
        temp =  temp->next;
    }
    // Change next of temp node
    temp->next = new_node;
    
    // Make temp node as previous of new node
    new_node->prev = temp;

    return; 
}


int main(){
    // start with empty list
    struct Node *head=NULL;

    // Insert 6, Out list becomes 6->NULL
    append(&head, 6);

    // Insert 7 at the end, list becomes 6->7->NULL
    append(&head, 7);

    append(&head, 1);

    append(&head, 4);   // list looks like 6->7->1->4->NULL

    cout<<"Created DLL is "<<printList(head);

    return 0;
}
