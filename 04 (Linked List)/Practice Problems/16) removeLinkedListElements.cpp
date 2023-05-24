https://leetcode.com/problems/remove-linked-list-elements/

// Method 1: Iterative Approach
// TC = O(N)
// SC = O(1)

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        ListNode *dummy = new ListNode(-1);   // because to delete we have to stand one node before, to deal with deleting the first node itself ie to avoid confusion, we create a dummy node
        dummy->next = head;
        
        ListNode *tail = dummy;
        while(tail!=NULL && tail->next!=NULL){
            if(tail->next->val == val){
                // delete operation
                ListNode *temp = tail->next;   // to free memory in the future 
                tail->next = tail->next->next; // or tail->next = temp->next;
                delete temp;
            }
            else tail = tail->next;
        }
        return dummy->next;
    }
};


// Method 2: Recursive approach (cleaner code but takes extra internal stack space)
https://youtu.be/JrRoR7ycM8U  (in the later part)

// We just check for the head equal to val or not rest will be done by recursion.

// If you want to free the memory (good practice)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        
        head->next = removeElements(head->next, val);  // recursive call // jo bhi head ka next laake dega use laake head k next m chipka denge

        if(head->val == val){   // Mujhe bas head ka kaam krna hai, agar head ki value val hai toh mai uska next return karaunga.
            ListNode *ans = head->next;
            delete head;  // free that nodes from memory which is equal to val
            return ans;
        }
        else return head;
    }
};

// If you dont want to free the memory
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        
        head->next = removeElements(head->next, val);  // recursive call
        
        if(head->val == val) return head->next;       // return head->val==val? head->next : head;  // ternary statement
        else return head;
    }
};

