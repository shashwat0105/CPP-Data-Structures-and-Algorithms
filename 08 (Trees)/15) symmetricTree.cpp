https://leetcode.com/problems/symmetric-tree/

Left -> Right  (Mirror property)
     <-

If I stand at the root of left subtree and move: Root->left->right
And simultaneously I stand at the root of right subtree and move: Root->right->left
I will be facing the same nodes, if its symmetric

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root==NULL || isSymmetricHelper(root->left, root->right);
    }
    
    bool isSymmetricHelper(TreeNode *left, TreeNode* right){
        if(left==NULL || right==NULL) return left==right;
        
        if(left->val!=right->val) return false;
        
        return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);  // Jab left k left m jaoge toh right k right m jana hai, jab left k right mein jaoge tab right k left mein jana hai.
    }
};

//
TC = O(N) = SC (In case of skew trees)
