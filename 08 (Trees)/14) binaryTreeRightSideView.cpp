https://leetcode.com/problems/binary-tree-right-side-view/

Right or Left
here we will see right view!

Recursive code is easier here
But it is a variation of preorder:
Root->right->left

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
    void recursion(TreeNode *root, int level, vector<int> &res){
        if(root==NULL) return;
        
        if(res.size()==level) res.push_back(root->val);   // isse ek level ka ek hi element insert hoga wo bhi ek ek karke
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
};


// If left view is asked.
Root->left->right

