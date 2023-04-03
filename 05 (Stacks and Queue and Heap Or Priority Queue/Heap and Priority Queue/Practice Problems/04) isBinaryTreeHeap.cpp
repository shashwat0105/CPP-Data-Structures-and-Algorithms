https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-heap/

To check for two properties:
1) It is a CBT
2) Max heap

class Solution {
    int countNodes(Node *tree){
        if(!tree)return 0;
        
        return 1 + countNodes(tree->left)+countNodes(tree->right);
    }
    
    bool isCBT(Node *tree,int index,int &count){
        if(!tree)return 1;
        
        if(index >= count)return 0;                      // any index in a cbt cannot be greater than count
        
        else{
            bool left = isCBT(tree->left, 2*index+1,count);
            bool right = isCBT(tree->right, 2*index+2,count);
            return left && right;
        }
    }
    
    bool isMaxHeap(Node *tree){
        if(tree->left==NULL && tree->right==NULL) return true;     // leaf node
        
        if(!tree->right)return tree->data >= tree->left->data;
        
        else{
            bool left = isMaxHeap(tree->left);
            bool right = isMaxHeap(tree->right);
            bool cur = (tree->data >= tree->left->data) && (tree->data >= tree->right->data);
            return left && right && cur;
        }
    }
    
  public:
    bool isHeap(struct Node* tree) {
        // code here
        int index = 0;
        int count = countNodes(tree);
        return isCBT(tree,index,count) && isMaxHeap(tree);
    }
};



// LEETCODE: Check CBT

https://leetcode.com/problems/check-completeness-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode *root){
        if(!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool isCBTHelp(TreeNode *root, int idx, int cnt){
        if(!root) return 1;
        if(idx>=cnt) return 0;   // any index in cbt cannot be greater than count
        else{
            bool left = isCBTHelp(root->left, 2*idx+1, cnt);
            bool right = isCBTHelp(root->right, 2*idx+2, cnt);
            return left && right;
        }
    }

    bool isCompleteTree(TreeNode* root) {
        int idx = 0;
        int cnt = countNodes(root);
        return isCBTHelp(root, idx, cnt);
    }
};
