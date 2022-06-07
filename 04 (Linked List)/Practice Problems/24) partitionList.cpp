https://leetcode.com/problems/partition-list/

// head = [1,4,3,2,5,2], x = 3
// leftDummy -> 1 -> 2 -> 2 -> rightDummy ka next
// rightDummy -> 4 -> 3 -> 5 -> NULL

TC = O(n), SC = O(1)


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummyLeft = new ListNode(-1);
        ListNode *dummyRight = new ListNode(-1);
        ListNode *ltail = dummyLeft;  // temp1
        ListNode *rtail = dummyRight; // temp2
        
        while(head){
            if(head->val < x){
                ltail->next = head;   // ltail = ltail->next = head  // single liner
                ltail = ltail->next;  
            }
            else{
                rtail->next = head;
                rtail = rtail->next;
            }
            head = head->next;
        }
        
        ltail->next = dummyRight->next;
        rtail->next = NULL;
        
        return dummyLeft->next;
    }
};


// For future if you still want to refer
https://youtu.be/KT1iUciJr4g
