https://leetcode.com/problems/search-in-a-binary-search-tree/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;
        
        if(root->val==val) return root;
        if(root->val>val) return searchBST(root->left, val);
        else return searchBST(root->right, val);               // yaha pe if laga k condition mat check karo, non void wala error aa jata ki kuch return nahi kia, ya ek separate void function bhi bana skte ho
    }
};

// Single liner without recursion

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL && root->val!=val){
            root = val < root->val ? root->left : root->right;
        }
        return root;
    }
};
