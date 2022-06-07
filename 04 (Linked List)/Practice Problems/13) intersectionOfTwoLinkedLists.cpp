https://leetcode.com/problems/intersection-of-two-linked-lists/

// Brute Force 
// TC = O(m*n)
// SC = O(1)

// Abhi isko khud se bhi code krna hai phle
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode * temp1 = headA;
    ListNode * temp2 = headB;
    if(temp1==NULL || temp2==NULL)
        return NULL;
    while(temp1!=NULL || temp2!=NULL)
    {
        temp1 = headA;
        if(temp1 == temp2)
            return temp1;
        else
        {
            temp1 = temp1->next;
            while(temp1!=NULL)
            {
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
// SC = (m+n)

// unordered set wala usmein agar kisi ek point pe dono list mein same elements hain but lists are not intersecting tab kaise hoga ?


// Method 3:
// By finding the length of the of linked list
// L1 = 6
// L2 = 4

// Skip 2 places in L1 to make the starting point same ie total length now to be travered is 4
// Start traversing together, point where they will be equal at the same time will be either intersection point or NULL ie end of the LL



// Method 4:
// Tricky coz no-one can think if he hasn't read it before, after reading its simple.
https://youtu.be/DGEqY5rLyVc (Discussion of this method is in the later half of the video)
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


