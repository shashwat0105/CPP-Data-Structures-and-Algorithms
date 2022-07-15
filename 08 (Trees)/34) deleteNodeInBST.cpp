https://leetcode.com/problems/delete-node-in-a-bst/

Delete the particular node and rearrange the BST and then return it.
// Delete the node
// If there exist both left and right
// Either attach the left part to left part of the right node 
// Or attach the right part to right part of the left node. (Iska code likha hai)

// If there is either left or right (edge cases)

// code:
// Isme right wale ko break karenge ar left wale k righmost child m attach karenge

https://youtu.be/kouxiP_H5WE // Last mein 14:29 second ka dry run image refer kar lena agar doubt ho

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key) return helper(root);
        
        TreeNode *dummy = root;
        while(root){
            if(root->val > key){                                  // searching the key in BST
                if(root->left!=NULL && root->left->val==key){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right!=NULL && root->right->val==key){
                    root->right = helper(root->right);            // we have found the key now the helper function will make the connections
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        return dummy;
    }
    TreeNode *helper(TreeNode *root){
        if(root->left==NULL) return root->right;         // key node ka left exist nahi karta toh, key->left mein key->left->right jod do
        else if(root->right==NULL) return root->left;    // key node ka right exist nahi karta toh, key->left mein key->left->left jod do
        TreeNode *rightChild = root->right;              // right subtree ka root
        TreeNode *lastRight = findLastRight(root->left); // will help me find righmost element in the left subtree jisse baad mein jodna hai
        lastRight->right = rightChild;                   // jo upar right child declare kia hai uska connection lastRight se bana do
        return root->left;                               // yaha se fr leftsubtree ka root return kar do
    }
    TreeNode *findLastRight(TreeNode *root){
        if(root->right==NULL) return root;
        return findLastRight(root->right);
    }
};

// TC = O(Height of the tree)
// SC = O(1)




