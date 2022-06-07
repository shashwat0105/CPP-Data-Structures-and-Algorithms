https://leetcode.com/problems/swap-nodes-in-pairs/

// Method 1:
// Iterative: O(1) space

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *curr = head;
        
        while(curr && curr->next){
            // save ptrs
            ListNode *nxtPair = curr->next->next;
            ListNode *second = curr->next;
            
            // reverse this pair
            second->next = curr;
            curr->next = nxtPair;
            prev->next = second;
            
            // update pairs
            prev = curr;
            curr = nxtPair;
        }
        return dummy->next;
    }
};


// Method 2: Recursive
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // base case
        if(head==NULL || head->next==NULL) return head;
        
        ListNode *new_head = head->next;
        ListNode *third = head->next->next;         // save ptrs
        new_head->next = head;
        
        head->next = swapPairs(third);
        
        return new_head;
    }
};
