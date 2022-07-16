https://leetcode.com/problems/inorder-successor-in-bst/ (Premium)

Inorder Successor/Predecessor in BST

https://youtu.be/SXKAD2svfmI

// Inorder successor is the number greater than a key in the inorder vector.
// Say the array is : { 1, 2, 3, 4, 5}
// Inorder successor of 3 is 4

// Brute Force:
// 1) Find the inorder
// 2) Using binary or linear search find the first value > key.
// 3) If there is no such value return NULL
// TC and SC = O(N)

// Better
// Via doing Morris/recursive inorder you can stop as u find value greater than key.

// Best
// Using searching in BST to find the first value > key 
// Ki left m jane pe milega ya right mein

TreeNode * inorderSuccessor(TreeNode *root, TreeNode *k){
    TreeNode *successor = NULL;
    while(root){
        if(k->val >= root->val){
            root = root->left;
        }
        else{
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

----
https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1/
// Yaha pe -> val ko ->key define kar rakha hai BC, dont get confused.

void findPreSuc(Node* root, Node*& pre, Node*& suc, int k){
    // Your code goes here
    if(root==NULL) return;
    suc = NULL;
    pre = NULL;
    
    Node* temp=root;                  // root value will change so, I saved it for later
    while(temp){
        if(k >= temp->key){
            temp = temp->right;
        }
        else{
            suc = temp;               // qki mai strictly chahta hu ki jab < ho tab hi update ho
            temp = temp->left;
        }
    }
    temp = root;                      // updating temp back to root
    while(temp){
        if(k <= temp->key){
            temp = temp->left;
        }
        else{
            pre = temp;                // qki mai strictly chahta hu ki jab > ho tab hi update ho
            temp = temp->right;
        }
    }
}

// Recurise code for future visit.
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
    if(!root) return ; 
    findPreSuc(root->left,pre,suc,key);
    if(root->key<key)
    pre = root; 
    if(root->key>key and suc==nullptr)
    { suc=root;}
    findPreSuc(root->right,pre,suc,key);
}
