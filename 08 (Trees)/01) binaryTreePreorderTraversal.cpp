https://leetcode.com/problems/binary-tree-preorder-traversal/

Root - Left - Right

LC Discuss
https://leetcode.com/problems/binary-tree-preorder-traversal/discuss/45466/C%2B%2B-Iterative-Recursive-and-Morris-Traversal

// Recursive Solution, O(N) Time and Space both

See, since when you encounter a nullptr you need to do nothing ie simply return;.
But since the return type is vector<int>, you need to make a helper function that does what you want.
(Yaha mai atak raha tha)

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(ans, root);
        return ans;
    }

private:
    void preorder(vector<int> &ans,TreeNode* root){
        if(root==nullptr) return;
        ans.push_back(root->val);
        preorder(ans, root->left);
        preorder(ans, root->right);
    }
};

// Iterative Traversal 
// O(N) time and space (call stack)
// We use stack DS (LIFO)
// I push right then left first in stack because of LIFO

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            ans.push_back(root->val);
            if(root->right!=NULL) st.push(root->right);  // if there exist a right push in the stack
            if(root->left!=NULL) st.push(root->left);    // if there exist a left push in the stack
        }
        return ans;
    }
};


// Morris Traversal 
// O(N) time, O(1) space (WAAH!!)
// But It also modifies the tree so it is not preferred in 99.99999% of the cases.


