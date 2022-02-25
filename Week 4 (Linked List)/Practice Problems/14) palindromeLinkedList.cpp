https://leetcode.com/problems/palindrome-linked-list/

// TRICKY QUESTION FROM INTERVIEW PERSPECTIVE

// Method 1:
// TC = O(N)
// SC = O(N)
// To convert it into a vector/array (extra space) or stack or recursion (extra space) then use normal palindrome check method.

// But this is not allowed


// Method 2:
// TC = O(N): 
// n/2(to find mid), n/2 to reverse the later half, n/2 to iterate and compare, n/2 to reverse it back: O(2N) -> O(N) TC
// SC = O(1)
https://youtu.be/XYY2tc_8KDM
// Approach:
// We will reverse the LL after its mid then compare and then reverse that part again to bring it back to its original form.
// Finding mid by similar to ques of mid of the linked list.
// To make it possible to reverse it back again we have to find mid-1 position.

class Solution {
public:
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
    
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head, *fast=head;  
        while(fast->next!=NULL && fast->next->next!=NULL){ // to reach position just before mid
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);              // the reversed list will be attached to slow ka next pe
        
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
        
        return true;    // is it is palindrome coz all were equal
    }
};

