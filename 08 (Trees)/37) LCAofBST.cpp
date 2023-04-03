https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

// LCA of BT: TC = O(N)
// LCA of BST: TC = O(Height of tree) ie O(H) ie logn

// Possibilities
// Say (5, 9) 
// 1) Node is one among them
// 2) Both lies to the left
// 3) Both lies to the right
// 4) One is on the left, other is on the right. (At this point I can say this is my lCA)

// Say root node is 10, and the numbers are (5, 9)
// Since,  5 & 9 are smaller than 10, both will lie to the left of 10

// Can write recursive code or while loop code(wont take extra stack space)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left, p, q);      // 2) left mein tab move krna hai jab dono choti ho
        }
        if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right, p, q);     // 3) right mein tab move karna hai jab dono badi ho
        }
        return root;                                            // 4) root tab return krna hai jab ek choti ho ek badi ho ie ek left mein ek right mein OR 1) special case ek node equal ho gyi ho ie usi ko return kar do
    } 
};

// Iterative Code:
TreeNode *LCAinaBST(TreeNode *root, TreeNode *p, TreeNode *q){
    while (root){
        if (root->data > p->data && root->data > q->data)
            root = root->left;                              //both values are on left of current node
        else if (root->data < q->data && root->data < p->data)
            root = root->right;                             //both values are on right of current node
        else
            return root;                                    //this node is LCA of p and q
    }
    return NULL;
}
