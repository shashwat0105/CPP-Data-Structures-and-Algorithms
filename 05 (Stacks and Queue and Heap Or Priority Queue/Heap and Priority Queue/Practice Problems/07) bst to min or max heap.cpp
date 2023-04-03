https://practice.geeksforgeeks.org/problems/bst-to-max-heap/1

To max heap

1 2 3 4 5 6 7 

      7
    /   \
   3     6
/   \  /   \
1    2 4     5

1 then 2 then 3
4 then 5 then 6
left then right then root (post order ki hint) // We have to convert in a "special" maxheap
And inorder of a bst gives array in sorted order

class Solution{
  public:
    vector<int> arr;
    int i=0;
    void convertToMaxHeapUtil(Node* root){
        // Your code goes here
        inorder(root);
        postorder(root);
    }    
    
    void inorder(Node *root){
        if(root==NULL) return;
        
        inorder(root->left);
        arr.push_back(root->data);
        inorder(root->right);
    }
    
    void postorder(Node *root){
        if(root==NULL) return;
        
        postorder(root->left);
        postorder(root->right);
        root->data = arr[i];   // nodes ki value change krte gaye.
        i++;
    }
    
};


To min heap
https://www.geeksforgeeks.org/convert-bst-min-heap/

