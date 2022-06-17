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

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode *node = root;
        while(true){
            if(node!=NULL){
                st.push(node);
                node = node->left;       // If the node is not null I move to the left
            }
            else{                        // when there is no node it is time to get the elements to fill in ans
                if(st.empty()) break;    // directly break out
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }
};

https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/31231/C%2B%2B-Iterative-Recursive-and-Morris

