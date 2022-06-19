https://leetcode.com/problems/same-tree/

We can do any traversal we know and solve the ques

// Algorithm for the recursion:
// 1)
// If one of the node is NULL then return the equality result of p an q.
// This boils down to if both are NULL then return true, 
// but if one of them is NULL but not the other one then return false
// 2)
// At this point both root nodes represent valid pointers.
// Return true if the root nodes have same value and 
// the left tree of the roots are same (recursion)
// and the right tree of the roots are same (recursion). 
// Otherwise return false. 

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL) return (p==q);
        
        return (p->val==q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

