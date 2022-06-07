https://leetcode.com/problems/reorder-list/

Method 1: O(1) space

// Divide the list into two halves. (Using fast and slow pointers)
// Reverse the second half.
// Merge the two lists L1 after L2 after L1 and so on. (Different from sorted merging we did in the past)

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        // spliting into two different lists.
        ListNode *head2 = slow->next;
        slow->next = NULL;
        
        // reversing the second half list
        ListNode *p = NULL, *c = head2, *n;
        while(c){
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        
        // merge the two lists
        ListNode *fH = head, *sH = p;    // fH is the head of the first list, sH is the head of the second list.
        while(sH){
            ListNode *temp1=fH->next, *temp2=sH->next;
            fH->next = sH;
            sH->next = temp1;
            fH = temp1;
            sH = temp2;
        }
        
    }
};

Method 2: If extra space is allowed. (generally not allowed)
Then put the elements in an array/deque and using two pointers elements can be extracted easily.

// Using array
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> arr;
        for(auto iter = head; iter; iter = iter -> next)
            arr.push_back(iter);
        
		// pointers to start and end of list. Re-order in alternating fashion from both end
        int L = 1, R = size(arr)-1;
        for(int i = 0; i < size(arr); i++, head = head -> next) 
            if(i & 1)                             // odd iteration:
                head -> next = arr[L++];          //        - pick node from L & update L ptr
            else                                  // even iteration
                head -> next = arr[R--];          //        - pick node from R & update R ptr
        
        head -> next = nullptr;
    }
};

// Using deque


class Solution {
public:
    void reorderList(ListNode* head) {
        // ---------Efficent Solution------------
         deque<ListNode*> dq;
         ListNode *prev = head,* curr = head->next;
         while(curr)
         { 
             dq.push_back(curr);
             prev->next = nullptr;
             prev = curr;
             curr = curr->next;
         }
        curr = head;
        while(!dq.empty())
        {
            curr->next = dq.back();
            dq.pop_back();
            curr = curr->next;
            if(!dq.empty())
            { 
              curr->next = dq.front();
              dq.pop_front();
              curr = curr->next;
            }
        }
    }
};
