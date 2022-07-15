https://leetcode.com/problems/validate-binary-search-tree/

To tell whether a given BT is a BST or not.

// Method 1: Inorder likho ar dekho ki agar sorted nahi mil raha toh not a BST
// Vector m store karne ki jagah variables bhi use kar skte hai
// Normal Inorder

// Iterative:

public boolean isValidBST(TreeNode root) {
   if (root == null) return true;
   Stack<TreeNode> stack = new Stack<>();
   TreeNode pre = null;
   while (root != null || !stack.isEmpty()) {
      while (root != null) {
         stack.push(root);
         root = root.left;
      }
      root = stack.pop();
      if(pre != null && root.val <= pre.val) return false;
      pre = root;
      root = root.right;
   }
   return true;
}

// Morris Inorder



// Method 2: Min Max wala   
// Every node will lie between [INT_MIN, INT_MAX] ie giving a range to every node [Low, High]   
// Suppose root node is 13
// When we go to the left our range will become [INT_MIN, 13]
// And for the right our range will become [13,INT_MAX]
// and so on

// We often tend to not look at the constraints which itself says that the range is in long not int

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return checkBST(root, LONG_MIN, LONG_MAX);
    }
    bool checkBST(TreeNode *root, long min, long max){
        if(root==NULL) return true;
        if(root->val >= max || root->val <= min) return false;
        return checkBST(root->left, min, root->val) && checkBST(root->right, root->val, max);
    }
};

// 13-1, 13+1 karne mein overflow ka risk rehta hai

