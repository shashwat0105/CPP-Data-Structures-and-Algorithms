https://leetcode.com/problems/remove-duplicates-from-sorted-list/

// Method 1: Using two pointers as done in arrays

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode *left =  head;
        ListNode *right = head->next;
        
        while(right!=NULL){
            if(right->val != left->val){
                right = right->next;
                left = left->next;
            }
            else{
                left->next = right->next;
                right = right->next;
            } 
        }
        return head;
    }
};

// We should free the memory to avoid leakage using delete() // good practice (In this code, right is initised outside the loop so not easily can be freed, but see method 3)

// Method 2: Using recursion

https://youtu.be/_Dc1IqY2WpQ

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;  // ie linked list doesnt exist or there is only one node
        
        ListNode *newHead = deleteDuplicates(head->next);
        if(head->val == newHead->val) return newHead;     // this is also handling the duplicates
        else{                                             // when two values are unequal.
            head->next = newHead;                         // head k next mein newHead ko jod do
            return head;
        }
    }
};

// Iterative approach (similar to method 1)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode *left = head;
        while(left->next!=NULL){
            if(left->val==left->next->val){
                ListNode *right = left->next;
                left->next = right->next;
                delete right;                         // free the memory
            }
            else{
                left = left->next;
            }
        }
        return head;
    }
};


