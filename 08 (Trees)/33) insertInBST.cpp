https://leetcode.com/problems/insert-into-a-binary-search-tree/

// Easy ques coz, the node to be inserted can be inserted in leaf node positions.

// There can be many ans, return any
// Any number which is already present in BST will not be asked to be inserted.
Logic:
Find where it can be? and insert..
Hack: Easy to insert it in leaf nodes wahi insert kr do.
Starting from root, each time move to the left or right child. Once we reach a leaf node, insert val.

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        TreeNode *cur = root;                             // making a copy of the root, bcz in last we need to return root of the tree.
        TreeNode *node = new TreeNode(val);
        while(true){
            if(cur->val <= val){                          // badi value insert karani hai toh wo right mein insert hogi
                if(cur->right) cur = cur->right;          // will keep moving to right jab tak not null ar <= follow hoga
                else{                                     // its null ie should have been on the right side, but its not there so we insert it
                    cur->right = node;
                    break;
                }
            }
            else{                                        // har left right jaane pe cur ka comparison hoga
                if(cur->left) cur = cur->left;
                else{
                    cur->left = node;
                    break;
                }
            }
        }
        return root;
    }
};

https://youtu.be/FiFiNvM29ps  (For more clarity and revision see the dry run during the last part of the video)
(Striver)

TC = O(log(base 2)n)

// Recursive:
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            return new TreeNode(val);
        }

        if(val < root->val){
            root->left = insertIntoBST(root->left , val);
        }
        else{
            root->right = insertIntoBST(root->right , val);
        }
        return root;
    }
};
