In accordance with this syntax
NODE SYNTAX:
// C++
struct Node{       
    int data;      
    Node *next;    // next will store the address of the next node, next is Node type
};

 
// DELETION

// A) Deleting the "first occurrence" of a given data value
// For example: 3->5->9->1->6  ,, In this you want to delete 9
// TC = O(N)
// Steps involved:
// 1) Find previous node of the node to be deleted.
// 2) Change the next of previous node.
// 3) Free memory for the node to be deleted.

/* Given a key, deletes the first occurrence of key in linked list */
void deleteNode(struct Node **head, int key){
    // store head node(so that it doesn't get lost)
    struct Node *temp = *head;
    struct Node *prev;

    // If the head node itself holds the key to be deleted
    if(temp!= NULL && temp->data == key){
        *head = temp->next; // Change head
        free(temp);         // free old head
        return;
    }

    // Search for key to be deleted, keep track of the previous node as we need to change temp->next
    while(temp!=NULL && temp->data!=key){
        prev = temp;
        temp = temp->next;
    }

    // If the key was not present in the linked list
    if(temp==NULL) return;

    // Unlink the node from link list
    prev->next == temp->next;

    free(temp); // Free memory 
}


// B) Deleting a node at a "given position"
// For example: 3->5->9->1->6  ,, In this you want to delete node at position 4
// TC = O(N)
/* Given a reference (pointer to pointer) to the head of a list 
   and a position, delete the node at the given position */

void deleteNode(struct Node** head, int position){
    // if linkedlist is empty
    if(*head==NULL) return;

    // store head node
    struct Node *temp = *head;

    // If head needs to be removed
    if(position == 0){
        *head = temp->next;   // change head
        free(temp);           // free old head
        return;
    }

    // find previous of the node to be deleted
    for(int i=0; temp!=NULL && i<position-1; i++){
        temp =  temp->next;
    }

    // if position is more than number of nodes
    if(temp==NULL || temp->next == NULL) return;

    // Node temp->next is to be deleted 
    // Store pointer to the next of node to be deleted
    struct Node *next = temp->next->next;

    // Unlink the node from the linkedlist
    free(temp->next);

    temp->next = next; // unlink the deleted node from the list
}


// C) Deleting a node whose "pointer is given"

// This can be done by following a similar approach as in the above two cases, by first finding the node just previous to it and updating its next pointer. 
// The time complexity of this would be again O(N).

// However, this particular case can be solved with O(1) time complexity if the pointer to the node to be deleted is given.
// Effective solution is to copy the data from the next node to the node to be deleted and delete the next node.
// Suppose the node to be deleted is node_ptr, it can be deleted as:

// find next node using next pointer
struct Node *temp = node_ptr->next;

// Copy data of next node to this node
node_ptr->data = temp->data;

// Unlink next node
node_ptr->next = temp->next;

// Delete next node
free(temp);


//  Note: This solution fails if the node to be deleted is the last node of the List. 
