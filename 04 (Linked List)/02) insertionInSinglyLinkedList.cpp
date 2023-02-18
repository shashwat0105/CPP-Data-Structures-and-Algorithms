In accordance with this syntax
NODE SYNTAX:
// C++
struct Node{       
    int data;      
    Node *next;    // next will store the address of the next node, next is Node type
};


// INSERTION

// A node at the beginning 
// TC = O(1)
// 4 steps:
/* Given a reference (pointer to pointer) to the head of a list and an int, insert a new node on the front of the list. */
void push(struct Node** head, int new_data){
    // 1. Allocate the node
    Node *new_node = new Node;

    // 2. Put data into it
    new_node->data = new_data;

    // 3. Make next of this new node as head
    new_node->next = *head;

    // 4. Move head to point to this new node
    *head = new_node;
}

// After a given node
// TC = O(1)
// The insertAfter() function must receive a "pointer to the previous node" after which the new node is to be inserted.

// We dont need to traverse till this node because its pointer is already passed
void insertAfter(struct Node* prev_node, int new_data){
    // 1. to check if the given previous node is null
    if(prev_node==NULL){
        cout<<"The given previous node cannot be null";
        return;
    }

    // 2. Allocate new node
    Node *new_node = new Node;

    // 3. Put in the data
    new_node->data = new_data;

    // 4. Make next of new node as next of prev node
    new_node->next = prev_node->next;

    // 5. Move the next of prev_node as new_node
    prev_node->next = new_node;
}

// At the end
// 6 steps
// TC = O(n)
// Since a Linked List is typically represented by its head, we have to first traverse the list till the end in order to get the pointer pointing to the last node and then change the next of last node to the new node.
// ie head is passed instead of pointer to last


/* Given a reference (pointer to pointer) to  
   the head of a list and an int, appends a new 
   node at the end  */

void append(struct Node** head, int new_data){
    // 1. Allocate new node
    Node* new_node = new Node;

    // 2. Put in the data
    new_data->data = new_data;

    // 3. Making the next of this new_node as NULL
    new_node->next = NULL;

    // 4. If the linkedlist is empty, make the new node as head
    if(*head == NULL){
        *head = new_node;
        return;
    }

    // 5. Else traverse till the last node
    struct Node *last = *head;
    while(last!=NULL){
        last = last->next;
    }

    // 6. Change the next of last node to new_node
    last->next = new_node;

    return;
}

