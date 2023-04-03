https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

https://youtu.be/sWf7k1x9XR4  (Striver)

Jo iska preorder hai wo linkedlist k form m likhna hai

How is it tough then?

// You don't have to create an extra list but you have to rearrange the nodes so that they point in such a manner as required.
// Connections bannane ka khel hai

// Method 1: Recursive
Right->Left->Root

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* prev = nullptr;
        flattenHelper(root, prev);
    }

    void flattenHelper(TreeNode* root, TreeNode*& prev) {
        if (!root) {
            return;
        }
        
        flattenHelper(root->right, prev);
        flattenHelper(root->left, prev);
        
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};


// Method 2: Iterative using stack
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            if (curr->right) {
                st.push(curr->right);
            }
            if (curr->left) {
                st.push(curr->left);
            }
            if (!st.empty()) {
                curr->right = st.top();
            }
            curr->left = nullptr;
        }
    }
};


// Method 3: Morris Traversal related: O(1) space

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode* prev = curr->left;
                while (prev->right) {
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};

----------------
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/?currentPage=1&orderBy=most_votes&query=

// Read this article best hai for explanation.
https://takeuforward.org/data-structure/flatten-binary-tree-to-linked-list/
