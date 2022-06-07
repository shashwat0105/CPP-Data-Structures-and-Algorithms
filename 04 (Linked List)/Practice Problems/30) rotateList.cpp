https://leetcode.com/problems/rotate-list/

// Brute force:
// O(N*K) time
// Everytime traverse till end and rotate k times


// Optimised
// As you should not rotate 1000 times if the length of the list is just 5
// ie any multiple of length will give back original linked list again.

// 1) count the length of the list
// 2) last ->next = head;
// 3) point length - k th node to NULL

// If 2 rotations are to be made & length of the list is 5, 3rd node will be pointed to NULL

// TC = O(N) approx, O(1) space

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        
        // find length
        ListNode *temp = head;
        int len = 1;
        while(temp->next){
            temp = temp->next;
            len++;
        }
        
        temp->next = head;
        k = k%len;
        k = len-k;
        
        while(k--) temp = temp->next;
        head = temp->next;  // making new head location
        temp->next = NULL;
        
        return head;
    }
};

