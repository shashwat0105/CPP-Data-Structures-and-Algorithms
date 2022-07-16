https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

// Method 1:
// Preorder is given we can manually create the tree such as:
// {8, 5, 1, 7, 10, 12} 
// 8 will be the main root, 5,1,7 will be on the left and 10, 12 will be on the right.
// And so on
// TC = O(N*N)


// Method 2:
// Preorder array is given.
// If I sort this array I will get inorder array. Now I have preorder and inorder arrays.
// I can get the unique tree!!
// TC = O(NlogN) + O(N)
// SC = O(N) : to store the inorder in a vector


// Method 3:
// Most optimised
// TC = O(3N) = O(N), SC = O(1)
// In this INT_MIN k bina bhi kaam ho jaega, see through code, similar to validate a BST approach.

//      5
//    1   
// Suppose you want to insert 7, 
// To insert in left of 1 you have to compare with < 1  (root->val will be the bound)
// To insert in right of 1 you have to compare with < 5  (bound)

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder, i, INT_MAX);
    }
    TreeNode *build(vector<int> &preorder, int &i, int bound){
        if(i==preorder.size() || preorder[i]>bound) return NULL;
        
        TreeNode * root = new TreeNode(preorder[i++]);
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);
        return root;
    }
};




