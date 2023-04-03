https://leetcode.com/problems/binary-tree-inorder-traversal/

left - root - right

// Recursive solutions k liye helper banaya karo acha rehta hai

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


// Iterative (Important)

// If the node is not null I continuosly move to the left and add all the nodes to the stack.
// when there is no left node it is time to get the elements to fill in ans
// I add the top node to my ans, and mark my current node as right node of the node popped,(now keep repeating) I again move left of this right node... ie left root right

https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/31231/C%2B%2B-Iterative-Recursive-and-Morris

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans;
        stack<TreeNode *> st;
        TreeNode *curr = root;
        
        while(!st.empty() || curr){
            if(curr){
                st.push(curr);
                pCurr = pCurr->left;
            }  // If it becomes NULL
            else{
                curr = st.top();
                st.pop();
                ans.push_back(curr -> val);
                curr = curr ->right;
            }
        }
        return ans;
    }
};


// Morris Traversal
https://youtu.be/80Zug6D1_r4 (Striver)
// Time= O(N)
// SC = O(1)

// Uses the concept of threaded binary tree

// Observation:
// From the last node of any subtree you go back to the root.

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {   // MORRIS
        vector<int> inorder;
        TreeNode* curr = root;
        while (curr) {
            if (!curr->left) {  // If the current node has no left child, add its value to the inorder vector and move to the right subtree
                inorder.push_back(curr->val);
                curr = curr->right;
            } 
            else {  // If the current node has a left child, find the rightmost node in its left subtree
                TreeNode* rightmost = curr->left;
                while (rightmost->right && rightmost->right != curr) {
                    rightmost = rightmost->right;
                }

                if (!rightmost->right) {  // If the rightmost node does not have a threaded link to the current node, create one and move to the left child
                    rightmost->right = curr;
                    curr = curr->left;
                } 
                else {  // If the rightmost node already has a threaded link to the current node, add the current node's value to the inorder vector and remove(cut) the threaded link
                    inorder.push_back(curr->val);
                    rightmost->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};
