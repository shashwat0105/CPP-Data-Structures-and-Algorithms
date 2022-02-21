https://leetcode.com/problems/reverse-linked-list/

https://youtu.be/MsIRa740mQY

// We dont want to reverse the values but

1 -> 2 -> 3 -> 4 -> NULL

4 -> 3 -> 2 -> 1 -> NULL  (This we DO NOT want to do) coz this will change the memory address of the values as well

NULL <- 1 <- 2 <- 3 <- 4  (YES, we have to do this, meaning of reversal)


We need THREE temp pointers to reverse a linked list
1) current, whose connection is to be reversed
2) previous, which will be joint to the current
3) next, which will help us to move forward


// ITERATIVE SOLUTION
// TC = O(N)
// SC = O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode *p = NULL, *c = head, *n = head->next;
        
        while(c!=NULL){
            c->next = p;
            p = c;
            c = n;
            if(n!=NULL) n = n->next;
        }
        return p;
    }
};

// RECURSIVE SOLUTION (is solution ko recursion topic padhne k baad ar ache se samjhna hai)
// TC = O(N)
// SC = O(N) // Internal stack memory is used

class Solution {
public:
    ListNode *reverse(ListNode *head){
        if(head->next == NULL) return head;
        ListNode *reverseHead = reverse(head->next);   // recursive call that will reverse the list except head and first element
        head->next->next = head;                       // ie next of first element should point to head, our work of reversing first two nodes
        head->next = NULL;
        return reverseHead;
    }

    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        return reverse(head);
    }
};

