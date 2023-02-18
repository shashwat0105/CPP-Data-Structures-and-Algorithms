https://leetcode.com/problems/linked-list-cycle-ii/

// Brute force:
// Using a hashmap to store the exact node ie ListNode *
// If a node is encountered again that means it is a cycle.
// TC = O(N)
// SC = O(N) // interviewer not happy with this extra space

// Optimal
// Same as Find the duplicate number in arrays problem
// Hare and tortoise algorithm.

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
     
        // if(head==NULL || head->next==NULL) return NULL;
        
        while(fast!=NULL && fast->next!=NULL){           // always write fast!=Null before fast.next else Run time error
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

// Watch this in future
https://youtu.be/QfbOhn0WZ88

// Or
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        entry = slow = fast = head

        while( fast!=None and fast.next!=None):
            slow = slow.next
            fast = fast.next.next
            if(slow==fast):           # Instead of breaking I did what needs to be done directly.
                while(entry!=slow):
                    slow = slow.next
                    entry = entry.next
                return entry

        return None