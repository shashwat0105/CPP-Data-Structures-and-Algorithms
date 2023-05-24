https://leetcode.com/problems/copy-list-with-random-pointer/

// Famous Interview Question
https://youtu.be/83mPr0i56Gg (Love babbar)

// Every node has a next pointer(as usual) and a random pointer

// Method 1: Using hashmap (Intuitive)
// TC = O(N)
// SC = O(N)


// Code 2
Node* cloneLinkedList(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    // Step 1: Create a hashmap to store the mapping between original and clone nodes
    std::unordered_map<Node*, Node*> hashmap;

    // Step 2: Create clone nodes without next and random pointers, and store them in the hashmap
    Node* curr = head;
    while (curr != nullptr) {
        Node* clone_node = new Node(curr->val);
        hashmap[curr] = clone_node;
        curr = curr->next;
    }

    // Step 3: Traverse the original list and update next and random pointers of clone nodes
    curr = head;
    while (curr != nullptr) {
        Node* clone_node = hashmap[curr];
        clone_node->next = hashmap[curr->next];
        clone_node->random = hashmap[curr->random];
        curr = curr->next;
    }

    // Step 4: Return the head of the cloned list
    return hashmap[head];
}


// Method 2: 
https://leetcode.com/problems/copy-list-with-random-pointer/solutions/2212823/c-2-easy-approach-using-hashmap-without-map-love-babbar-approach/
https://www.youtube.com/watch?v=83mPr0i56Gg   (Yet to watch 2nd appraoch from here)
// TC = O(N)
// SC = O(1)
We can optimize the space complexity further by avoiding the use of a hashmap. 
Instead, we can follow an in-place approach to clone the linked list. The idea is to insert the cloned nodes between the original nodes in a single linked list. 

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

// code 2
Node* cloneLinkedList(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    // Step 1: Create clone nodes and insert them between original nodes
    Node* curr = head;
    while (curr != nullptr) {
        Node* clone_node = new Node(curr->val);
        clone_node->next = curr->next;
        curr->next = clone_node;
        curr = clone_node->next;
    }

    // Step 2: Update random pointers of clone nodes
    curr = head;
    while (curr != nullptr) {
        Node* clone_node = curr->next;
        if (curr->random != nullptr) {
            clone_node->random = curr->random->next;
        }
        curr = clone_node->next;
    }

    // Step 3: Separate the original and cloned linked lists 
    Node* cloned_head = head->next;
    curr = head;
    while (curr != nullptr) {
        Node* clone_node = curr->next;
        curr->next = clone_node->next;
        if (clone_node->next != nullptr) {
            clone_node->next = clone_node->next->next;
        }
        curr = curr->next;
    }

    return cloned_head;
}


// Future to visit
https://youtu.be/5Y2EiZST97Y (NEETCODE)
https://youtu.be/VNf6VynfpdM (STRIVER)

