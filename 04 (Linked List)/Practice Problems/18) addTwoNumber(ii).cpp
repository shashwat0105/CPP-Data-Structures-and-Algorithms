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


// Method 2: Using stack (To review after studying stack)

stack<int> s1, s2;
    while(l1){
        s1.push(l1->val);
        l1 = l1->next;
    }
    while(l2){
        s2.push(l2->val);
        l2 = l2->next;
    }
    int sum = 0;
    bool carry = false;
    ListNode *head, *post = nullptr;
    while(!s1.empty() || !s2.empty()) {
        sum = carry ? 1 : 0;
        if(!s1.empty()) {
            sum += s1.top();
            s1.pop();
        }
        if(!s2.empty()) {
            sum += s2.top();
            s2.pop();
        }
        carry = sum >= 10;
        head = new ListNode(sum % 10);
        head->next = post;
        post = head;
    }
    if(carry) {
        head = new ListNode(1);
        head->next = post;
    }
    return head;

// Recursion uses stack
// so refer this later too:
https://leetcode.com/problems/add-two-numbers-ii/discuss/798754/Easy-C%2B%2B-solution-without-using-stack-or-reversing-the-inputoutput-list.
