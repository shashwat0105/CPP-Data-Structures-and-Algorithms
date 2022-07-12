https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

Root node, one of the two nodes can also be LCA

// Brute force:
// LCA(4, 7)
// We write the path from 4 to root
// and path from 7 to root.
// we will compare the paths and first where they match first is our ans.
// In this approach they is extra space as we have to store both the paths.

// Optimised: (Dry run karke dekh lo samajh aa jaega)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {   // dfsTraversal
        // base case
        if(root==NULL || root==p || root==q){                         // if current root == p or root == q ie we found p or q in the tree ar wo return kar denge
            return root;
        }
        TreeNode *left  = lowestCommonAncestor(root->left, p, q);     // because the return function is TreeNode type
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        // (Jab har subtree ki left ar right calls complete ho jaengi tab aage yeh chalega)
        if(left==NULL)       return right;   // if left is NULL, return right whatever it is, be it NULL too(ie neither p nor q was in that subtree)    
        else if(right==NULL) return left;  
        else return root;                    // both left and right are not, we found our ans. (ie under this root both p and q lie)
    }
};

// If the current (sub)tree contains both p and q, then the function result is their LCA. 
// If only one of them is in that subtree, then the result is that one of them. 
// If neither are in that subtree, the result is null/None/nil.

