https://www.geeksforgeeks.org/swap-nodes-in-a-linked-list-without-swapping-data/

For future abhi yeh jaroori nahi qki thoda complex padta hai

https://youtu.be/ws8hmOpxdIM

https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
Isme kya hai ki sirf value change krne ko keh raha hai toh asan hai.

// sirf value hi change krni thi
class Solution {
public:
// We traverse the list until we reach the kth node.
// Then we set "kth" to that node to remember it, set ptr2 to head and continue traversing the list, while we move both ptr1 and ptr2.
// When ptr1 reaches the end - ptr2 is on the (n-k)th node.
// Now we swap "kth" and "ptr2" and we're done!
// Important: The problem description specifically asks to swap values, not nodes themselves.

// agar nodes swap krni hai toh refer: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/solutions/1366214/Optimized-Solution-o(n)-time-or-Swapping-of-Nodes-in-Java/  (lengthy)
     ListNode* swapNodes(ListNode* head, int k) {
        ListNode *ptr1 = head, *ptr2 = head, *kth = NULL;
        while (--k)
            ptr1 = ptr1->next;
        
        kth = ptr1;
        ptr1 = ptr1->next;
        
        while (ptr1) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        swap(ptr2->val, kth->val);
        return head;
    }
};