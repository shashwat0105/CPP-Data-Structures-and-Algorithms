https://leetcode.com/problems/sort-list/

// Method 1:
// Merge sort with recursion.
// Easy code but with extra stack memory.

// Spliting the list till it breaks down to single element is logn
// Merging them is n, so total time is O(nlogn)

// Using recursion hence this is not strictly O(1) solution.

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // base condition
        if(head==NULL || head->next==NULL) return head;
        
        // splitting the list into halves
        ListNode *temp = NULL;               // will be used to point the left half of the list to NULL later
        ListNode *slow = head;
        ListNode *fast = head;
        
        // Finding mid of the list code
        while(fast && fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;                 // end of first half list
        
        ListNode *list1 = sortList(head);  // left half recursive call
        ListNode *list2 = sortList(slow);  // right half recursive call
        
        return merge(list1, list2);
    }
    
    ListNode *merge(ListNode *list1, ListNode *list2){
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

        temp->next = list1 ? list1 : list2;   // either of them becomes null
        return dummy->next;
    }
};    


// Method 2:
// Strictly O(1) (For future purposes agar mood ho)
// or iterative version of merge sort (Hard hai yeh)
// YT wgyra pe bhi iska algo mil skta hai
Recursion use up-to-bottom strategy , why not try the opposite way--bottom-to-up, luckily it works, it only consumes 0(1) space
https://leetcode.com/problems/sort-list/discuss/46712/Bottom-to-up(not-recurring)-with-o(1)-space-complextity-and-o(nlgn)-time-complextity

https://leetcode.com/problems/sort-list/discuss/166324/c%2B%2B-and-java-legit-solution.-O(nlogn)-time-and-O(1)-space!-No-recursion!-With-detailed-explaination

https://leetcode.com/problems/sort-list/discuss/46767/Java-solution-with-strict-O(1)-auxiliary-space-complexity



// Method 0:
// Using selection sort
// TC = O(n^2)
// Selection Sort (ie If modifying the value and swapping is allowed)
// JAVA CODE hai
class Solution2 {
    public ListNode sortList(ListNode head) {
        if (head == null) return head;
        ListNode current = head;
        while (current != null) {
            ListNode iter = current;
            ListNode min = iter;
            while (iter != null) {
                if (iter.val < min.val)
                    min = iter;
                iter = iter.next;
            }
            int temp = current.val;
            current.val = min.val;
            min.val = temp;
            current = current.next;
        }
        return head;
    }
}

