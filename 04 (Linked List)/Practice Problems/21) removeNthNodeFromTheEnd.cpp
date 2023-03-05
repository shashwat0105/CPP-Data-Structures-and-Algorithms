https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// Method 1 : 1 pointer 2 pass
// TC = O(2N)  // Interviewer may also demand for O(n) ie one pass soln
// SC = O(1)

// if total nodes say are 6
// peeche se 2nd node is aage se 5th node
// 6-2 = 4th node (and hame yahi toh chahiye hota hai, delete hone wali node k pehle wali node)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        int flag=0;    // count variable
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
        ListNode *temp2 = temp->next;      // store kar lia to delete in future
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

both moves now with same speed till fast reaches the last node coz both points at dummy initially.
hence now, slow will be at the node to be deleted ie nth node from the last.
// code with dummy node
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1 pass soln
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;

        while(n--){
            fast = fast->next;
        } 

        while(fast->next!=NULL){  // untill fast reaches the last node(started from dummy)
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;  // delete operation perform ni kia hai
        return dummy->next;
    }
};


// code without dummy handling the edge case
// C++ Code with handled edge case  ->  if(fast == NULL) return head->next;  

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode *fast = head, *slow = head;
	while(n--) fast = fast -> next;      // iterate first n nodes using fast
	if(!fast) return head -> next;       // if fast is already null, it means we have to delete head itself. So, just return next of head(edge case handled)
	while(fast -> next)                  // iterate till fast reaches the last node of list
		fast = fast -> next, slow = slow -> next;            
	slow -> next = slow -> next -> next; // remove the nth node from last
	return head;
}
