https://leetcode.com/problems/linked-list-cycle/

// FAMOUS INTERVIEW QUESTION

// A cycle doesn't have NULL
// If you reach a node again it is a cycle

// Method 1(Using hashset)
// TC & SC = O(N)

// Method 2(Slow and fast pointer approach)
// without extra space
// Cycle hai ki nahi bas yeh return hai isme

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        
        if(head==NULL || head->next==NULL) return false;   // ie there is no or 1 element in the list.
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;    // we have to do this, thats why the conditions in while loop
            if(fast==slow) return true; // fast catches slow ie there was a cycle.
        }
        return false;
    }
};

// Proof of concept is by commonsense and by simple maths
(m + an + k) = 2(m + bn + k) 
k = n(a-2b) - m   
// m = length of list not in loop
// n = length of loop
// a = no of rounds by fast pointer in the loop
// b = no of rounds by slow pointer in the loop
// k = start of loop to point where they can meet. We can see k is a finite value. Hence proved.

// Even if the speed is 3x, 4x, 5x it will catch the slow pointer.

