https://leetcode.com/problems/reverse-nodes-in-k-group/

// BADHIYA SAWAL HAI YEH!! LC HARD

https://youtu.be/TeDcLjOOiK4

// We have swapped the nodes, not the values inside the nodes

// I will reverse the first k nodes, rest work will be done by recursion

// Method 1 (Using recursion)

// TC = O(N)
// SC = O(N/K)  // Internal stack

class Solution {
public:
    void reverse(ListNode *s, ListNode *e){
        ListNode *p=NULL, *c=s, *n;
        while(p!=e){                                      // ie jabtak previous end node tak na pahuch jae, coz current NULL pahuchega we dont know
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL||k==1) return head;  // base condition
    
        ListNode *s = head, *e = head;
        int inc = k-1;
        while(inc--){
            e = e->next;                                  // e is now at the end of k terms, s is at the start
            if(e==NULL) return head;                      // a sublinked list has length < k ie e reaches NULL, then do nothing ie return head
        }

        ListNode *nextHead  = reverseKGroup(e->next, k);  // nextHead is the new head of a smaller reversed sublinkedlist  // calling recursively
        reverse(s, e);
        s->next = nextHead;

        return e;                                         // e after reversal will be the head of the linkedlist, that's why we return it
    }
};


// Method 2 

https://youtu.be/dbRJFnQoKTI

TC = O(N)
SC = O(1)

ie eliminating recursion by solving by iteration


class Solution {
public:
    void reverse(ListNode *s, ListNode *e){
        ListNode *p=NULL, *c=s, *n=s->next;
        while(p!=e){  // ie jabtak previous end node tak na pahuch jae, coz current NULL pahuchega we dont know
            c->next = p;
            p = c;
            c = n;
            if(n!=NULL) n = n->next;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==1) return head;
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *beforeStart = dummy, *e = head;
        int i = 0;
        
        while(e!=NULL){
            i++;
            if(i%k==0){
                // reversal
                ListNode *s = beforeStart->next, *temp = e->next;
                reverse(s,e);
                beforeStart->next = e;
                s->next = temp;
                beforeStart = s;
                e = temp;
            }
            else{
                e = e->next;
            }
        }
        return dummy->next;
    }
};

