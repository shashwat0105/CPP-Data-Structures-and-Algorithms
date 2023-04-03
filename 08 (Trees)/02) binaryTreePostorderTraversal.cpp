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
// Stack 1 mein popped element ka left(if it exist) ar right(if it exist) daalo
// Stack 2 k elements will be your ans.
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        vector<int> ans;
        s1.push(root);

        if(root==NULL) return ans;
        
        while(!s1.empty()){                 
            TreeNode *node = s1.top();
            s2.push(s1.top());
            s1.pop();
            if(node->left) s1.push(node->left);
            if(node->right) s1.push(node->right);
        }
        while(!s2.empty()){
           int x = s2.top()->val;
           ans.push_back(x);
           s2.pop(); 
        }
        return ans;
    }
};

// 2) Using 1 stack
Method 1: 
In the previous 2 stack video, instead of using 2nd stack we can push into ans. And in the end, we can reverse ans.

Method 2:
We go: left -> left -> left... -> null -> right -> right/left whatever -> null -> print
(Ratne wala method hai)
Code in 3b

https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/45648/3-ways-of-Iterative-PostOrder-Traversing-(Morris-traversal)

// MORRIS POSTORDER

vector<int> morrisPostorderTraversal(TreeNode* root) {
    vector<int> postorder;  // create an empty vector to store the postorder traversal
    TreeNode* curr = root;  // initialize the current node to the root

    // traverse the binary tree using Morris traversal
    while (curr) {
        if (!curr->right) {  // If the current node has no right child, add its value to the postorder vector and move to the left subtree
            postorder.push_back(curr->val);
            curr = curr->left;
        } else {  // If the current node has a right child, find the leftmost node in its right subtree
            TreeNode* leftmost = curr->right;
            while (leftmost->left && leftmost->left != curr) {  // find the leftmost node in the right subtree by following its left child links, stopping at the first node with a threaded link to the current node (or the last node in the leftmost path)
                leftmost = leftmost->left;
            }

            if (!leftmost->left) {  // If the leftmost node does not have a threaded link to the current node, create one and move to the right child
                leftmost->left = curr;  // create a threaded link from the leftmost node in the right subtree to the current node
                postorder.push_back(curr->val);  // add the value of the current node to the postorder vector
                curr = curr->right;  // move to the right child
            } else {  // If the leftmost node already has a threaded link to the current node, remove the threaded link and move to the left subtree
                leftmost->left = NULL;  // remove the threaded link from the leftmost node in the right subtree
                curr = curr->left;  // move to the left subtree
            }
        }
    }

    reverse(postorder.begin(), postorder.end());  // reverse the postorder vector to obtain the postorder traversal
    return postorder;  // return the vector containing the postorder traversal
}

