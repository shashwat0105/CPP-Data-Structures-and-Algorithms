https://leetcode.com/problems/copy-list-with-random-pointer/

// Famous Interview Question

// Every node has a next pointer(as usual) and a random pointer

// Method 1: 
// TC = O(N)
// SC = O(N)

class Solution {
public:
    void copyList(Node *head){
        Node *temp = head;
        while(temp){
            Node *copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;   
            temp = copy->next;   
        }
    }
    
    void handleRandom(Node *head){
        Node *temp = head;
        while(temp){
            if(temp->random) temp->next->random = temp->random->next;  // temp k copy ka random = temp k random ka copy
            temp = temp->next->next;                                   // traversing in original nodes
        }
    }
    
    // difficult part
    Node* detach(Node *head){                                         // to separate the two merged lists.
        Node *dummy = new Node(-1);                                   // to hold the list which we will extract
        Node *tail = dummy, *temp = head;
        while(temp){
            tail->next = temp->next;
            tail = tail->next;
            temp->next = tail->next;
            temp = temp->next;
        }
        return dummy->next;
    }
    
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        
        copyList(head);
        handleRandom(head);
        
        return detach(head);
    }
};

// Future to visit
https://youtu.be/5Y2EiZST97Y
https://youtu.be/VNf6VynfpdM

