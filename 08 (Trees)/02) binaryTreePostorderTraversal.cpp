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

// Iterative
// 1) Using 2 stacks
// TC = O(N), SC = O(2N)
// Stack 1 mein root daalo, top element pop karke stack 2 mein dalo,
// Stack 1 mein popped element ka left ar right daalo
// Stack 2 k elements will be your ans.

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        vector<int> ans;
        s1.push(root);
        
        while(!s1.empty() && root){                 // is && root ki jagah root==NULL return ans;
            TreeNode *node = s1.top();
            s2.push(s1.top());
            s1.pop();
            if(node->left) s1.push(node->left);
            if(node->right) s1.push(node->right);
        }
        while(!s2.empty()){
           int x=s2.top()->val;
           ans.push_back(x);
           s2.pop(); 
        }
        return ans;
    }
};

// 2) Using 1 stack
We go: left -> left -> left... -> null -> right -> right/left whatever -> null -> print

https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/45648/3-ways-of-Iterative-PostOrder-Traversing-(Morris-traversal)

