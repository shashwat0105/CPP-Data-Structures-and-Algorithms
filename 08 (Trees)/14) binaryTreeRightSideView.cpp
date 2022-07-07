https://leetcode.com/problems/binary-tree-right-side-view/

Right or Left
here we will see right view!

// Last Node of every level will be my right view as well if taking level from left to right.

Recursive code is easier here
But it is a variation of preorder(reverse preorder):
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
                               
        if(res.size()==level) res.push_back(root->val);   // isse ek level ka ek hi element insert hoga wo bhi ek ek karke // smart technique, if I come to a level for the first time, then why dont u add that particular node
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
};


// If left view is asked.
// Root->left->right

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        recurse(root, 0, ans);
        return ans;
    }
    
    void recurse(TreeNode *root, int level, vector<int> &ans){
        if(root==NULL) return;
        
        if(ans.size()==level) ans.push_back(root->val);
        recurse(root->left, level+1, ans);
        recurse(root->right, level+1, ans);
    }
};
