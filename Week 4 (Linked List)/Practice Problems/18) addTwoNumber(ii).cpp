https://leetcode.com/problems/add-two-numbers-ii/

// Method 1:
// Reversing or modifying the list.

// Reverse both the list then it will become same as previous question.
// Reverse the ans back to get the desired ans.

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *p = NULL, *c = head, *n;
        
        while(c!=NULL){
            n = c->next;
            c->next = p;    
            p = c;
            c = n;
        }
        return p;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        int carry = 0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum = 0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode *node = new ListNode(sum%10);
            temp->next=node;
            temp = temp->next;
        }
        return reverseList(dummy->next);
    }
};

