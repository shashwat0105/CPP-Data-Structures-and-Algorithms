https://leetcode.com/problems/binary-tree-postorder-traversal/

left - right - root (Whatever is here write in recursive code)

// Recursive
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(ans, root);
        return ans;
    }
private:
    void postorder(vector<int> &ans,TreeNode* root){
        if(root==nullptr) return;
        postorder(ans, root->left);
        postorder(ans, root->right);
        ans.push_back(root->val);           // Only this line is modified from preorder
    }
};