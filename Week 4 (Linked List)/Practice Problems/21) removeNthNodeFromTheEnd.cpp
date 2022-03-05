https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// Method 1 : 1 pointer 2 pass

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        int flag=0;
        while(temp){
            temp = temp->next;
            flag++;
        }
        if(flag == n) return head -> next;  // VVIP (If the head node is to be deleted return head->next) (For this edge case can make dummy node as well)
        int nf = flag - n;
        
        temp = head;
        while(--nf){
            temp = temp->next;
        }
        ListNode *temp2 = temp->next;
        temp->next = temp->next->next;
        delete temp2;
        return head;
    }
};


// Method 2: 2 pointer 1 pass
https://leetcode.com/problems/remove-nth-node-from-end-of-list/discuss/1164537/Short-and-Simple-One-Pass-Solution-w-Explanation-or-Beats-100-or-No-dummy-node-required!

Using fast and slow

fast = head
slow = head

fast moves n steps , gap between fast and slow is of n

both moves now with same speed till fast reaches NULL
hence now, slow will be at the node to be deleted ie nth node from the last.
