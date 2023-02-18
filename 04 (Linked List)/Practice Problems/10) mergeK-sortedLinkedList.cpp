https://leetcode.com/problems/merge-k-sorted-lists/

https://youtu.be/RYJ3vs8qx10

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
// Search : TC = O(l)

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
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;  // default is maxheap, we use a comparator to make it a minheap
        ListNode *dummy = new ListNode(-1);                   // ans ka first node is dummy node
        ListNode *tail = dummy;                               // smallest is insert in the ans ka last for which we need a tail
        
        for(int i = 0; i<lists.size(); i++){
            if(lists[i]!=NULL) q.push(lists[i]);
        }
        
        while(q.size()){
            ListNode *temp = q.top();
            tail->next = temp;
            tail = temp;                                     // or tail = tail->next;  ie move tail forward
            q.pop();
            if(temp->next!=NULL) q.push(temp->next);
        }
        
        return dummy->next;
    }
};
