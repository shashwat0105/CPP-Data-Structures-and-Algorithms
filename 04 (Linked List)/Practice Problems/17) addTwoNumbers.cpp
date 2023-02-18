https://leetcode.com/problems/add-two-numbers/

https://youtu.be/LBVsXSMOIk4

Edge cases: Linked list of unequal lengths. (pehle interviewer se discuss karo taaki use yeh na lage ki tmne yeh pehle kia hua hai)

// Addition happens from ones digit and so on & the list is already reversed so no issue ie directly addition of digits can be performed digit by digit.

TC = O(max(n1, n2)) // n1, n2 are the length of the linked lists.

// Iterative approach (Preffered)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        int carry = 0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum = 0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode *cur_node = new ListNode(sum%10);
            temp->next= cur_node;                           // jo new node banayi hai use attach bhi toh krna padega
            temp = temp->next;
        }
        return dummy->next;
    }
};


// Recursive approach

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		return helper(l1, l2, 0);
	}
private:
	ListNode* helper(ListNode* n1, ListNode* n2, int carry) {
		if (!n1 && !n2 && !carry) {
			return NULL;
		}
		int cur_sum = (n1 ? n1->val : 0) + (n2 ? n2->val : 0) + carry;
		ListNode* cur_node = new ListNode(cur_sum % 10);
		cur_node->next = helper(n1?n1->next:NULL, n2?n2->next:NULL, cur_sum / 10);
		return cur_node;
	}
};


// OR

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(!l1 && !l2) return NULL;
    int c = (l1? l1->val:0) + (l2? l2->val:0);
    ListNode *newHead = new ListNode(c%10), *next = l1? l1->next:NULL;
    c /= 10;
    if(next) next->val += c;
    else if(c) next = new ListNode(c);
    newHead->next = addTwoNumbers(l2? l2->next:NULL, next);
    return newHead;
}