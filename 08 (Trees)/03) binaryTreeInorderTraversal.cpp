https://leetcode.com/problems/binary-tree-inorder-traversal/

left - root - right

// Recursive

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(ans, root);
        return ans;
    }
    private:
    void inorder(vector<int> &ans,TreeNode* root){
        if(root==nullptr) return;
        inorder(ans, root->left);
        ans.push_back(root->val);           // only change coz root beech mein aata hai isme
        inorder(ans, root->right);
    }
};

// Iterative

