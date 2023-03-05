https://leetcode.com/problems/partition-list/

// Given: 1->4->(3)->2->5->2

// In the first glance we tend to get confused that the output should be: 1->2->2->(3)->4->5
// But this is not correct, the ques doesnt states about position of nodes greater than x ki usko bhi utha k x k baad hi krna hai.
// It is wrong also because order of 4 and 3 should be preserved as there is nothing said about values >x

// Hence: 1->2->2->4->(3)->5

// We have to create two separate LL
// You have to use extra space: By creating two dummy nodes and their tails(that will move) one will store all the smaller<x values and
// other will store all the values >=x then u just join the second list(big vals) after the first list(containing small vals).

// head = [1,4,3,2,5,2], x = 3
// smallDummy -> 1 -> 2 -> 2 -> bigDummy ka next
// bigDummy -> 4 -> 3 -> 5 -> NULL

TC = O(n), SC = O(1)


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummySmall = new ListNode(-1);    
        ListNode *dummyBig = new ListNode(-1);
        ListNode *stail = dummySmall;  // temp1
        ListNode *btail = dummyBig;    // temp2
        
        while(head){
            if(head->val < x){
                stail->next = head;   // stail = stail->next = head  // single liner
                stail = stail->next;  
            }
            else{
                btail->next = head;  // head ko btail k aage laga hai
                btail = btail->next;
            }
            head = head->next;
        }
        
        stail->next = dummyBig->next;
        btail->next = NULL;
        
        return dummySmall->next;
    }
};


// TC = O(N)
// SC = O(1) : we are using the same list , two extra dummy nodes and just adjusting the ptrs.

// For future if you still want to refer
https://youtu.be/KT1iUciJr4g

https://youtu.be/b4FeEwAGDtU (algorithms made easy) this also good
