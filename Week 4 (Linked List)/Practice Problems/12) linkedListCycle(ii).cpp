https://leetcode.com/problems/linked-list-cycle-ii/

// Same as Find the duplicate number in arrays problem
// Hare and tortoise algorithm.

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
     
        //if(head==NULL || head->next==NULL) return NULL;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;    
            if(fast==slow) break;
        }
        
        if(fast==NULL || fast->next==NULL) return NULL;  // ie cycle not found, ie upar wala while break hua not because fast==slow
        
        fast = head;
        while(fast!=slow){                               // the point they meet again is the start of the cycle.
            slow = slow->next;
            fast = fast->next;    
        }
        return slow;
        
        // OR
        // ListNode *ptr1=head, *ptr2 = slow;
        // while(ptr1!=ptr2){
        //     ptr1 = ptr1->next;
        //     ptr2 = ptr2->next;
        // }
        // return ptr1;
    }
};

// can refer for maths proof
https://youtu.be/tsQT0MT73Og
