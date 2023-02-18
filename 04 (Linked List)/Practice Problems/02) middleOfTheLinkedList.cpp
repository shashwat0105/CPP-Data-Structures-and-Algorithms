https://leetcode.com/problems/middle-of-the-linked-list/

// TC = O(n) 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * temp = head;
        int flag = 0;                       // to find the length of the linked list
        while(temp!=NULL){
            flag++;
            temp = temp->next;
        }
        
        int mid = flag/2;
        
        // Now from the start I have to move mid no of times to reach the mid element
        temp = head;                        // Initilising temp with head
        while(mid--){
            temp = temp->next;
        }
        
        return temp;                        // temp jaha pe rahega wahi mera middle element hoga
    }
};

// Method 2: Without finding the length of node (Interviewer will expect this approach)

// Two pointers:
// Slow pointer moves one step
// Fast pointer moves two steps
// When fast will reach at the end, slow will be in the middle.

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow=head, *fast=head;
        
        while(fast!=NULL && fast->next!=NULL){   // while loop terminates when fast reaches NULL(when length is even) or reaches last node(when length is odd) which points to null 
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;   // slow jaha pe rahega wahi mera middle element hoga
    }
};
