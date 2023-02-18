https://leetcode.com/problems/merge-two-sorted-lists/

Merge two lists in sorted manner.

https://youtu.be/0QPpgAsd4IY

// This can be done by using a third LL or modifying the existing linked list, depending on the demand of the interviewer.

// Using recursion (without using third LL)
// TC = O(m+n)
// SC = O(m+n)

class Solution {
public:
    ListNode *merge(ListNode *l1, ListNode *l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val < l2->val){               
            l1->next = merge(l1->next, l2);  // ie jiski value kam thi uske phle le lia ar baaki pe merge ko dobara call kar dia
            return l1;
        }
        else{
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return merge(list1, list2);
    }
};


// Iterative approach (Still without any extra LL)
// Just like merge sort in arrays

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        
        while(list1 && list2){              // when both the lists are not null
            if(list1->val < list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        // if(list1) temp->next = list1;
        // else temp->next = list2;
        temp->next = list1 ? list1 : list2;   // either of them becomes null
        
        return dummy->next;
    }
};

