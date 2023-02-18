https://leetcode.com/problems/intersection-of-two-linked-lists/

https://youtu.be/u4FWXfgS8jw  (Striver)

    1->2-
         \ 
           8 -> 7 -> 6    // yaha wala 8 hai intersection though pehle 1, 1 value same ho chuki hai(nodes are same not just value)
         /
2->8->1 -

// Brute Force 
// TC = O(m*n)
// SC = O(1)

// Compare all the nodes of one list to other.

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode * temp1 = headA;
    ListNode * temp2 = headB;
    if(temp1==NULL || temp2==NULL)
        return NULL;

    while(temp1!=NULL || temp2!=NULL){
        temp1 = headA;
        if(temp1 == temp2)
            return temp1;
        
        else{
            temp1 = temp1->next;
            while(temp1!=NULL){
                if(temp1 == temp2)
                    return temp1;
                temp1 = temp1->next;
            }
            temp2 = temp2->next;
        }
    }
    return NULL;
}


// Method 2: Using set data structure
// TC = O(m+n)
// SC = (m+n)  (Interviewer still no happy with extra space)
// [Using Hashing we store address(ie node itself)(not values) of each node and find common addresses b/w 2 linked lists]
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		unordered_map<ListNode*, int> m;
		while(headA != NULL){
			m[headA]++;
			headA = headA -> next;
		}
		while(headB != NULL){
			if(m[headB] > 0){
				return headB;
			}
			headB = headB -> next;
		}
		return NULL;
	}
};


// Method 3 (Opitimal but longer soln): Length Difference solution
// TC = O(m+n)
// SC = O(1)
// 1) Finding the length of both linked list
// L1 = 6
// L2 = 4

// 2) Then Skip 2(L1-L2) places in L1 to make the starting point same ie total length now to be travered is 4
// 3) Start traversing together, point where they will be equal at the same time will be either intersection point or NULL ie end of the LL

// Can refer all solns here
https://leetcode.com/problems/intersection-of-two-linked-lists/solutions/1093014/c-four-different-solutions/


// Method 4 (Optimal and shorter soln)(Two ptr solution):  
// (Same jo extra length hai usko bina alag se calculate kiye bas pointer move karke travel kar dia taaki sabke starting pt same ho jae)
// Tricky coz no-one can think if he hasn't read it before, after reading its simple.
https://youtu.be/DGEqY5rLyVc (fraz)(Discussion of this method is in the later half of the video)
// TC = O(m+n)
// SC = O(1)

// Generalised length
// Distance moved by A: (m+x) + (n+x)     // ie after A moves its length make it at start of B
// Distance moved by B: (n+x) + (m+x)     // ie after B moves its length make it at start of A
// Making their travelled length equal so that they come at sync.

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA, *b = headB;

        while(a!=b){                     // till they not become equal
            if(a==NULL) a = headB;       // a reaches its end, make it start of B and vice versa for B
            else a = a->next;            // else simply move it forward
            
            if(b==NULL) b = headA;
            else b = b->next;
        }
        return a;                        // return either a or b, that point will be either intersection or NULL so handles both the cases automatically.
    }
};


