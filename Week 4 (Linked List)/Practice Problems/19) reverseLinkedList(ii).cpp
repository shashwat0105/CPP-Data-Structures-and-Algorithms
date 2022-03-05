https://leetcode.com/problems/reverse-linked-list-ii/

// Left and right are positions in the linked list.

// Normal reverse ques
1->2->3->4->5
1<-2<-3<-4<-5

// This ques
1->2->3->4->5
1->4->3->2->5

// Intermediate dry run
1->2->3->4->5
p  c  n

after i=0
1->3->2->4->5    // we took out 3 and put it at the front of the list part to be reversed
p  n  c  

after i = 1 
1->4->3->2->5    // again we took out 4 and put it at the front of the list part to be reversed and so on, ie we get the required list.
p     n  c

// p = node before sublist to be reversed
// c = working node that will iterate through the list
// n = node to be extracted and put in front.


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL || left==right) return head;
        
        ListNode *dummy = new ListNode(-1);        // to avoid any edge cases, making a dummy node is recommended.
        dummy->next = head;
        
        ListNode *p = dummy;                       // instead of taking p as NULL, taking p as dummy
        // or while(--left) p=p->next;        
        for(int i=0; i<left-1; i++) p=p->next;     // p will point one node before the position of left.
        // cout<<p->val;
        
        ListNode *c=p->next,*n;
        
        // or n-=m;
        //    while(n--) 
        for(int i=0; i<right-left; i++){           // code piece inside the loop is totally different from reverse linked list.
            n=c->next;
            c->next=n->next;                       // to cut out the node to be extracted.
            n->next=p->next;
            p->next=n;
        }
        return dummy->next;
    }
};

// Video explanation of this method:
// https://youtu.be/BE0hruM5O5U


