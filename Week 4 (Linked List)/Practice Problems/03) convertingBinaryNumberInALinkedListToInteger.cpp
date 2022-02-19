https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/submissions/

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
    int getDecimalValue(ListNode* head) {
        ListNode *temp = head;
        int flag = 0;              // to find the number of nodes in a linkedlist
        while(temp!=NULL){
            flag++;
            temp = temp->next;
        }
        
        int res = 0;
        temp = head;              // reinitialize the temp with head
        while(temp!=NULL){
            res += (pow(2, flag-1)*(temp->val));    // 2^(total nodes-1) * current value either 0 or 1
            flag--;
            temp = temp->next;
        }
        return res;
    }
};
