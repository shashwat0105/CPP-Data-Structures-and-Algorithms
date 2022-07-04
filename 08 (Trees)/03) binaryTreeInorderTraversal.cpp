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
                node = node->left;       // If the node is not null I continuosly move to the left
            }
            else{                        // when there is no node it is time to get the elements to fill in ans
                if(st.empty()) break;    // directly break out when there are no nodes anywhere to travel
                node = st.top();         // for all the nodes that were put into the stack
                st.pop();
                ans.push_back(node->val);
                node = node->right;      // while going back, we take the right nodes   
            }
        }
        return ans;
    }
};

https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/31231/C%2B%2B-Iterative-Recursive-and-Morris

https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/31232/Three-Methods-to-Solve-(C%2B%2B)
(Refer Method 2 and 3)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> st;
        TreeNode *pCurrent = root;
        
        while(!st.empty() || pCurrent){
            if(pCurrent){
                st.push(pCurrent);
                pCurrent = pCurrent->left;
            }
            else{
                TreeNode *pNode = st.top();
                ans.push_back(pNode -> val);
                st.pop();
                pCurrent = pNode ->right;
            }
        }
        return ans;
    }
};
