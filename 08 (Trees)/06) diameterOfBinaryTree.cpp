https://leetcode.com/problems/diameter-of-binary-tree/

Diameter of binary tree
1) Longest path between two nodes.
2) Path need not pass through the root.


// We can find lH and rH at every node, and add them up and compare. The max will be the ans.
// We know to calculate height of tree in O(N) time. (Is the crux of optimisation)

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root, diameter);
        return diameter;
    }
    
    int height(TreeNode *root, int &diameter){
        if(root==NULL){
            return 0;
        }
        
        int lH = height(root->left, diameter);
        int rH = height(root->right, diameter);
        diameter = max(diameter, lH+rH);         // diameter kya hoga? har instance pe leftHeight + rightHeight mein maximum
        
        return 1+max(lH, rH);  // lH akela calculate karne mein bhi toh 1+ karna hi padta hai ie chahe left height nikalna ho ya right height
    }
};



