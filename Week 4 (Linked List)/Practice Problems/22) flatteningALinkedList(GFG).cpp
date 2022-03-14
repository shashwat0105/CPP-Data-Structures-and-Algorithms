https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

https://youtu.be/ysytSSXpAI0

// This is same as merging k linked lists.

The TC of optimal approach will be (2x + 3x + 4x + 5x + ..... kx) assuming the single linkedlist to be of size x on average. 
We cannot use min heap here(but below is a working code) because, we want to change the current LinkedList pointers. 
So thinking of min heap is not a good idea because you need to flatten the linkedlist only!

// TC = O(Total no of nodes)

Node *mergeTwoLists(Node *a, Node *b){
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    while(a && b){
        if(a->data < b->data){
            temp->bottom = a;
            a = a->bottom;
        }
        else{
            temp->bottom = b;
            b = b->bottom;
        }
        temp = temp->bottom;
    }
    temp->bottom = a ? a : b;
    return dummy->bottom;
}
/*  Function which returns the  root of the flattened linked list. */

// recursive
Node *flatten(Node *root)
{
   // base case
   if(root==NULL || root->next==NULL) return root;
   // recursive call for list on right
   root->next = flatten(root->next);
   // now merging
   root = mergeTwoLists(root, root->next);

   return root;
}

// iterative
Node *flatten(Node *root){
    Node *h1 = root;
    Node *h2 = root->next;
    while(h2!=NULL){
        h1 = mergeTwoLists(h1, h2);
        h2 = h2->next;
    }
   return h1;
}

// Another approach:
// Using priority queue (Better time and space in people opinion)
struct compare {
    bool operator()(const Node* l, const Node* r) {
        return l->data > r->data;
    }
};
Node *flatten(Node *root){
    if(root==NULL)return root;
    vector<Node*>lists;
    Node* temp=root;
    while(temp!=NULL){
        lists.push_back(temp);
        temp=temp->next;
    }
    priority_queue<Node*,vector<Node*>,compare> pq;
    Node* res= new Node(0);
    temp=res;
    for(int i=0;i<lists.size();++i){
        if(lists[i]!=NULL)pq.push(lists[i]);
    }
    // cout<<pq.size();
    while(pq.size()!=0){
        Node* x=pq.top();
        pq.pop();
        if(x->bottom!=NULL){
            pq.push(x->bottom);
        }
        temp->bottom=x;
        temp=temp->bottom;
    }
    return res->bottom;
}

