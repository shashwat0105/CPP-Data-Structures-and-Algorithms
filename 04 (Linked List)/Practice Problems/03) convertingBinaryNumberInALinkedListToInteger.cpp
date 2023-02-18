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


// Method 2
// In a single traversal
// We assume when we go on a node its the last node so we multiply it with  2^0 ie 1  
// if we find another node we multiple with 2 
// addition of each new node will multiply all current node's value by 2.

// Parse linked list starting from the head: while head.next:
// The current value is head.next.val. Update the result by shifting it by one to the left and 
// adding the current value using logical OR: num = (num << 1) | head.next.val.

// Return num.


class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode *temp = head;
        int res = 0;
        while(temp!=NULL){
            res*=2;
            res += (temp->val);    // val * 2^0 = val
            temp = temp->next;
        }
        return res;
    }
};

// Bit manipulation of above
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        num = head.val
        while head.next:
            num = (num << 1) | head.next.val
            head = head.next
        return num