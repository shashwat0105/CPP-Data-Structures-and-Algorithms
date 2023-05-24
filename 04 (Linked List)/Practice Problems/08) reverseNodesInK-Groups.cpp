https://leetcode.com/problems/reverse-nodes-in-k-group/

// BADHIYA SAWAL HAI YEH!! LC HARD

https://youtu.be/TeDcLjOOiK4  (FRAZ)

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

https://youtu.be/dbRJFnQoKTI  (FRAZ)

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


// another code sample:
ListNode* reverseKGroup(ListNode* head, int k) {
	if(!head || !head->next) return head;
	ListNode newHead(0);
	ListNode *pre = &newHead, *cur = head, *next = NULL;
	newHead.next = head;
	int len = 0;
	for(ListNode *p = head; p; p = p->next) len++;
	int times = len/k;
	while(times) {
		for(int i = 1; i < k; ++i) {
			next = cur->next;
			cur->next = cur->next->next;
			next->next = pre->next;
			pre->next = next;
			if(i == k-1) {
				pre = cur;
				cur = cur->next;
			}
		}
		times--;
	}
	return newHead.next;
}

// Another recursive code
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Check if there are at least k nodes remaining
        ListNode* curr = head;
        int count = 0;
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }
        // If there are at least k nodes, reverse the current group
        if (count == k) {
            curr = reverseKGroup(curr, k); // Recursively reverse the remaining groups

            // Reverse the current group
            while (count > 0) {
                ListNode* nextNode = head->next;
                head->next = curr;
                curr = head;
                head = nextNode;
                count--;
            }
            head = curr;
        }

        return head;
    }
};
