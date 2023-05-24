https://leetcode.com/problems/merge-k-sorted-lists/

Revise from 
https://youtu.be/Q64u-W3l3mA (MIK)


https://youtu.be/RYJ3vs8qx10 (FRAZ)

// Approach 1:
// Make a vector, insert all the lists, sort the list and take out every element and make it as node
// TC = O(NK log NK)   , k = no of lists, n = average size of each list

// Approach 2:
// Compare 2 lists merge them into 1, then merge this with other and so on. 

// Approach 3: 
// Compare 1st elements of all the lists add it to the result 
// TC = O(K * NK)

// Whenever we have a question that requires minimum:
// 1) sorting
// 2) Also requires insertion or deletion and we want minimum or maximum so we use a HEAP data structure

// Here we will use min heap
// Minimum element is always at the top of the min heap
// Insertion/Deletion : TC = O(logn)
// Search : TC = O(N)

// TC of this method = O(N log K)
// SC = O(K)   // size of the heap

// Priority queue is used in C++ to make a min-heap

// Approach 3:

class cmp{
public:  // by default is private so we need to make it public
    bool operator() (ListNode *a, ListNode *b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;  // we use comparator to make a special minheap
        ListNode *dummy = new ListNode(-1);                   // ans ka first node is dummy node
        ListNode *tail = dummy;                               // smallest is insert in the ans ka last for which we need a tail
        
        for(int i = 0; i<lists.size(); i++){
            if(lists[i]!=NULL) q.push(lists[i]);             // I add basically the first node of every list in my heap
        }
        
        while(q.size()){
            ListNode *temp = q.top();
            tail->next = temp;
            tail = temp;                                     // or tail = tail->next;  ie move tail forward
            q.pop();
            if(temp->next!=NULL) q.push(temp->next);         // Insert next node of that list from which the node was extracted
        }
        
        return dummy->next;
    }
};

// Approach 4:
// Similar to merge sort, break into two halfs, till u have solo or two lists and you know to merge them easily.

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
    ListNode* mergeTwoSortedLists(ListNode *l1, ListNode *l2){
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1->val <= l2->val){
            l1->next = mergeTwoSortedLists(l1->next, l2);
            return l1; 
        }
        else{
            l2->next = mergeTwoSortedLists(l1, l2->next);
            return l2;
        }
        return NULL;
    }

    ListNode* partitionAndMerge(int start, int end, vector<ListNode*>& lists){
        if(start>end){
            return NULL;
        }
        if(start==end){
            return lists[start];
        }

        int mid = (start+end)>>1;

        ListNode* L1 = partitionAndMerge(start, mid, lists);
        ListNode* L2 = partitionAndMerge(mid+1, end, lists);

        return mergeTwoSortedLists(L1, L2);  // wapas aate hue merge krna hai so wrote after the recursive call
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0){
            return NULL;
        }
        return partitionAndMerge(0, k-1, lists);
    }
};
