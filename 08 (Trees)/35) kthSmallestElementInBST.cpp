https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// Naive approach
// You can do a traversal, store all values in a vector, sort it and then return kth smallest/largest whatever is asked.
// TC = O(N+Nlogn), SC = O(N)

// Optimised
// TC = O(N)
// SC = O(1)

// Inorder traversal of a BST gives the nodes in sorted order!! We will use this.
// No sorting time of nlogn will be required.
// Instead of storing it in a vector, we can do count++ to save the space too if we use Morris inorder traversal.
// Recursive/iterative inorder mein space aa hi jaegi.

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int cnt = 0;
        inorder(root, k, ans, cnt);
        return ans;
    }
    
    void inorder(TreeNode *root, int k, int &ans, int &cnt){
        if(root==NULL) return;
        inorder(root->left, k, ans, cnt);
        cnt++;
        if(cnt==k) ans = root->val;
        inorder(root->right, k, ans, cnt);
    }
};


// If kth largest is aked
// 1 traversal to compute the total number of nodes.
// Then traverse to find n-kth node.
or
// Kth largest element can be done in single traversal. By using reverse inorder traversal i.e.(Right-Root-Left)

// Iterative inorder:
int kthLargest(TreeNode* root, int k) {
    stack<TreeNode*> st; 
    TreeNode* node = root;
    int cnt = 0; 
    while(true) {
        if(node != NULL) {
            st.push(node); 
            node = node->right; 
        }
        else {
            if(st.empty() == true) break; 
            node = st.top(); 
            st.pop(); 
            cnt++; 
            if(cnt == k) return node->val; 
            node = node->left; 
        }  
    }
    return -1;
}

// yeh article ar leetcode discuss padh lena last mein in future
https://takeuforward.org/data-structure/kth-largest-smallest-element-in-binary-search-tree/
