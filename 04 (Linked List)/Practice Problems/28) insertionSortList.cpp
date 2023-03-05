https://leetcode.com/problems/insertion-sort-list/

https://youtu.be/Kk6mXAzqX3Y


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
// jo node sahi jagah pe nahi hai use utha k aage lana hai
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = head, *prev = dummy;
        while(cur){
            if(cur->next && (cur->next->val < cur->val)){
                // insertion
                while(prev->next && (prev->next->val < cur->next->val)) prev = prev->next;

                // making connections
                ListNode *temp = prev->next; // storing ki kho na jae
                prev->next = cur->next;
                cur->next = cur->next->next;
                prev->next->next = temp;
                prev = dummy;  // firse yaha se comparsion start krna padega
            }
            else cur = cur->next; // element at right position already
        }
        return dummy->next;
    }
};
