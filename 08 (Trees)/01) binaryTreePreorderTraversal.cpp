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
        solvePreorder(root, ans);
        return ans;
    }

    void solvePreorder(TreeNode *root, vector<int> &ans){
        if(root==NULL) return;

        ans.push_back(root->val);
        solvePreorder(root->left, ans);
        solvePreorder(root->right, ans);
    }
};

// Iterative Traversal 
// O(N) time and space (call stack)
// We use stack DS (LIFO)
// ***** I push right then left first in stack because of LIFO *****

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root=st.top();                                // Yeh alag se store karke karna jaroori hai nahi toh TLE ayega
            st.pop();
            ans.push_back(root->val);
            if(root->right!=NULL) st.push(root->right);   // if there exist a right push in the stack
            if(root->left !=NULL) st.push(root->left);    // if there exist a left push in the stack
        }
        return ans;
    }
};

// Other method u can see in 3b file.

// Morris Traversal 
// O(N) time, O(1) space (WAAH!!)
// But It also modifies the tree so it is not preferred in 99.99999% of the cases. U can modify it back after finishing it. 

// 1 line change from morris traversal of inorder so pehle uska code dekh skte ho

vector<int> morrisPreorderTraversal(TreeNode* root) {
    vector<int> preorder;
    TreeNode* curr = root;
    while (curr) {
        if (!curr->left) {                                           // If the current node has no left child, add its value to the preorder vector and move to the right subtree
            preorder.push_back(curr->val);
            curr = curr->right;
        } 
        else {                                                       // If the current node has a left child, find the rightmost node in its left subtree
            TreeNode* rightmost = curr->left;
            while (rightmost->right && rightmost->right != curr) {   // find the rightmost node in the left subtree by following its right child links, stopping at the first node with a threaded link to the current node (or the last node in the rightmost path)
                rightmost = rightmost->right;
            }
            if (!rightmost->right) {               // If the rightmost node does not have a threaded link to the current node, create one and add the current node's value to the preorder vector, then move to the left child
                preorder.push_back(curr->val);     // Only this line is different (neeche k else se hata k yaha likh dia)
                rightmost->right = curr;           // create a threaded link from the rightmost node in the left subtree to the current node
                curr = curr->left;
            } 
            else {                       // If the rightmost node already has a threaded link to the current node, remove the threaded link and move to the right child
                rightmost->right = NULL; // remove the threaded link from the rightmost node in the left subtree
                curr = curr->right;      // move to the right child
            }
        }
    }
    return preorder;
}

// 
Limitations of Morris:

Morris traversal is a method of traversing a binary tree without using recursion or a stack, which reduces the space complexity to O(1). However, it has some limitations.
Firstly, it modifies the tree structure by creating temporary links, which may not be allowed in certain scenarios. For example, if the binary tree is read-only or shared by multiple threads, Morris traversal may not be suitable.
Secondly, it may not work well with certain types of binary trees, such as skewed trees, where one subtree is much larger than the other. In such cases, Morris traversal may result in an unbalanced traversal, leading to poor performance.
Finally, Morris traversal requires careful handling of edge cases, such as handling the root node and dealing with nodes with only one child. This may add complexity to the implementation and make it harder to debug.


// N-ary tree pre order traversal
https://leetcode.com/problems/n-ary-tree-preorder-traversal/

