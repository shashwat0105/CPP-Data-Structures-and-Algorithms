https://leetcode.com/problems/palindrome-linked-list/

// TRICKY QUESTION FROM INTERVIEW PERSPECTIVE

// Method 1:
// TC = O(N)
// SC = O(N)
// To convert it into a vector/array (extra space) or stack or recursion (extra space) then use normal palindrome check method.

// But interviewer wont be happy with this extra space, he want O(1) space method


// Method 2:
https://youtu.be/-DtNInqFUXs (striver)
https://youtu.be/XYY2tc_8KDM (fraz)

// Approach:
// Step 1: Find the mid of the LL (using slow, fast ptr approach)
// Step 2: Reverse the second half ie LL after the middle node.
// Step 3: Now keep one pointer at the start of LL and other at next of mid node and start to compare them.
// Now ask the interviewer(it is a good practice tho) if if wants the list to retain original form, then dont loose the mid node, so that
// reverse that part again .
// To make it possible to reverse it back again we have to find mid-1 position. (slow ko wahi rehne do)

// TC = O(N): 
// n/2(to find mid), n/2 to reverse the later half, n/2 to iterate and compare, n/2 to reverse it back: O(2N) -> O(N) TC
// SC = O(1)

class Solution {
public:

    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true; // no node or 1 node

        ListNode *slow=head, *fast=head;  

        // 1) Find middle of the LL
        while(fast->next!=NULL && fast->next->next!=NULL){ // to reach position just before mid
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 2) Reverse the right half
        slow->next = reverseList(slow->next);              // the reversed list will be attached to slow ka next pe
        
        // 3) Keep a ptr at the start of LL and other at next position of slow(slow ko bhi move krke use kar skte agar wapas se reverse na karna ho)
        // to start the iteration. Our LL is now looking like 1->2->3->1->2->3->NULL
        ListNode *start=head, *mid=slow->next;
        while(mid!=NULL){                                  // in both cases of even and odd length of LL
            if(mid->val != start->val) return false;       // ie they are not palindrome
            start = start->next;
            mid = mid->next;
        }
        // print(head); // will print 1 2 3 1 2 3 now ie after reversal the later half
        
        // reversing it back again to its original state
        slow->next = reverseList(slow->next);
        // print(head); // will print 1 2 3 3 2 1 ie original state
        
        return true;    // it is palindrome coz all were equal
    }

    ListNode *reverseList(ListNode *head){            // function to reverse a list, done before.
        if(head==NULL) return NULL;
        ListNode *p=NULL, *c=head, *n=head->next;
        
        while(c!=NULL){
            c->next=p;
            p=c;
            c=n;
            if(n!=NULL) n=n->next;
        }
        return p;
    }
    
    // to print our LL, to see in between how it looks
    // void print(ListNode *head){
    //     while(head){
    //         cout<<head->val<<" ";
    //         head = head->next;
    //     }
    //     cout<<endl;
    // }
};

// Further notes:
// As a best practice, whenever we manipulate the given input we should also restore it. As we did above
// The downside of in-place algorithms is that in a concurrent environment we must use locks. Otherwise the state of the data is inconsistent.

////// In python:
// See how to call n declare functions:
https://www.geeksforgeeks.org/python-call-function-from-another-function/

// Isme neeche restore nahi kia hai
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if(head==None or head.next==None):
            return True
        
        fast = slow = head

        # find middle
        while(fast.next!=None and fast.next.next!=None):
            slow = slow.next
            fast = fast.next.next
        
        # reverse the second half
        slow.next = self.reverse(slow.next)    # ese self. karke function call krni padti hai

        slow = slow.next

        while(slow!=None):
            if(head.val!=slow.val):
                return False
            head = head.next
            slow = slow.next

        return True

    def reverse(self, node: Optional[ListNode]):   # ese function declare krna padta hai
        p = None
        c = node
        while(c!=None):
            n = c.next
            c.next = p
            p = c
            c = n
        
        return p
