https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode *dummy = new ListNode(-1); 
                                                                
        dummy->next = head;
        
        
        ListNode *prev = dummy;
        ListNode *left = head;
    
        while(left){
            if(left->next && left->val == left->next->val){
                while(left->next && left->val == left->next->val){
                    left = left->next;                   // move till the end of duplicates sublist
                } 
                prev->next = left->next;                 // skip all duplicates // left is pointing to the last duplicate node
            }
            else{
                prev = prev->next;                      // otherwise, move predecessor
            }
            left = left->next;                          // move forward
        }
        return dummy->next;
    }
};

// In this ques we are never comparing value of dummy node with other nodes, so you can keep it anything.
// For future:
ListNode *dummy = new ListNode(0 == head->val ? 1 : 0); // to guarantee the dummy node is not same as the original head. (Because elements range from -100 to 100)



// Recursive approach

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        if(head->val != head->next->val){
            head->next = deleteDuplicates(head->next);    // coz head will be the part of the solution 
            return head;
        }
        else{
            while(head->next && head->val==head->next->val) head = head->next;
            return deleteDuplicates(head->next);
        }
    }
};