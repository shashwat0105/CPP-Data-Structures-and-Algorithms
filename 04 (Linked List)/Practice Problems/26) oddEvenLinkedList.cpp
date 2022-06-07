https://leetcode.com/problems/odd-even-linked-list/

// Similar to partitionList problem

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode *dummyLeft = new ListNode(-1);
        ListNode *dummyRight = new ListNode(-1);
        ListNode *ltail = dummyLeft;  // temp1
        ListNode *rtail = dummyRight; // temp2
        
        int flag = 1;
        while(head){
            if(flag==1){
                ltail->next = head;
                ltail = ltail->next;
                flag--;
            }
            else if(flag==0){
                rtail->next = head;
                rtail = rtail->next;
                flag++;
                //cout<<flag;
            }
            head = head->next;
        }
        ltail->next = dummyRight->next;
        rtail->next = NULL; 
        
        return dummyLeft->next;
    }
};

