https://leetcode.com/problems/count-complete-tree-nodes/

Every level except the last is completely filled.

// Naive:
// Do any traversal and count++
// TC = O(N)
// SC = O(H): H = height of binary tree, complete tree: logn is the height
void traverse(TreeNode *root, int &cnt){
    if(!root) return;
    cnt++;
    traverse(root->left, cnt);
    traverse(root->right, cnt);
}
int countNodes(TreeNode* root) {
    int cnt=0;
    traverse(root, cnt);
    return cnt;
}

// Optimisation < O(N) is asked
// We will use property of complete tree

// No of nodes in a complete binary tree: 2^(height of the tree) - 1

// For every node I compute the left and right height
// Actually this is the length of left left left nodes(not exactly the left height), same for right part.
// Qki height nikalne k liye maximum lena padta tha!!
// Middle part of the tree nodes are filled as it is a complete binary tree so uski height ka koi fark ni padega
// If left height =  right height, we can directly use above formula as the tree/subtree is a complete tree and return from there
// Else 1 + left side + right side

// TC = O(logN*logN)

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        
        int lH, rH = 0;
        TreeNode *leftNode = root;
        TreeNode *rightNode = root;
        
        while(leftNode){
            lH++;
            leftNode = leftNode->left;   // left node always is thre coz complete binary tree
        }
        while(rightNode){
            rH++;
            rightNode = rightNode->right;
        }
        
        if(lH == rH) return (1<<lH) - 1;      // this is faster than pow operation // 2^lH - 1
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
