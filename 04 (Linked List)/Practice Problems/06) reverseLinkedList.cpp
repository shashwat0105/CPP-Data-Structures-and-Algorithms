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
        if(head==NULL || head->next==NULL) return head;
        ListNode *p = NULL, *c = head, *n;
        
        while(c!=NULL){
            n = c->next;    //save the next ke aage waali chain
            c->next = p;    // we are assigning p to c ka next,, ie c ka next should point to p(previous) ie //point it backwards
            p = c;          /* move fwd */
            c = n;          /* move fwd */
        }
        return p;           // when loop will end c will be pointing to NULL
    }
};

// Animation and chaining of the steps(helps to remember) can be found here:
https://leetcode.com/problems/reverse-linked-list/discuss/1449712/Easy-C%2B%2BJavaPythonJavaScript-Explained%2BAnimated


// RECURSIVE SOLUTION 
// TC = O(N)
// SC = O(N) // Internal stack memory is used

class Solution {
public:
    ListNode *reverse(ListNode *head){
        if(head->next == NULL) return head;
        ListNode *reverseHead = reverse(head->next);       // recursive call that will reverse the list except head and first element
        head->next->next = head;                           // ie next of first element should point to head, our work of reversing first two nodes (actually this same work will be done by recursion later)
        head->next = NULL;
        return reverseHead;
    }

    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        return reverse(head);
    }
};  

// OR simply:

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next ==NULL) return head;   // base condition
        ListNode *reverseHead = reverseList(head->next);   // recursive call
        head->next->next = head;                           // ie next of first element should point to head
        head->next = NULL;              
        return reverseHead;
    }0
};


// Recursive way to reverse first N elements
ListNode* successor = NULL;
ListNode* reverseN(ListNode* head, int n){
    if(n==1){
        successor = head->next;
        return head;
    }
    ListNode *reverseHead = reverseN(head->next, n-1);
    head->next->next = head;
    head->next = successor;
    return reverseHead;
}


// Recursive way to reverse between given left and right positions (reverse list (ii) problem)
ListNode* successor = NULL;
ListNode *reverseBetween(ListNode* head, int left, int right){
    if(left<=1){
        return reverseN(head, right-left+1);
    }
    head->next = reverseBetween(head->next, left-1, right-1);
    return head;
}

// (reverse list (ii) problem) Iterative
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL || left==right) return head;
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *p = dummy;   // instead of taking p as NULL, taking as dummy
        for(int i=0; i<left-1; i++) p=p->next;
        // cout<<p->val;
        
        ListNode *c=p->next,*n;
        
        for(int i=0; i<right-left; i++){
            n = c->next;
            c->next=n->next;
            n->next=p->next;
            p->next=n;
        }
        return dummy->next;
    }
};

// other way: 

class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)     # set up a dummy node to avoid edge cases (left = 0)
        leftPrev = dummy
        cur = head
        #1. iterative until reaching the left
        for i in range(left - 1):
            leftPrev, cur = cur, cur.next
            
        #2 reverse part: from left -> right  similarly like problem 206
        prev = None  # set up a prev node
        for i in range(right - left + 1):
            tmp_next = cur.next
            cur.next = prev
            prev, cur = cur, tmp_next
            
        #3 connect linked list
        # e.g. original linked list 1->2->3->4->5, after part 1 and part 2, 
		# leftPrev = 1, cur = 5, prev = 4, so leftPrev.next(2).next should be 5, that is cur
		# lefrPrev(1).next should be 4, that is prev
		leftPrev.next.next = cur   
        leftPrev.next = prev
        
        return dummy.next