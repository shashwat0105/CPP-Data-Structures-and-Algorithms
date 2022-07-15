https://leetcode.com/problems/insert-into-a-binary-search-tree/

// There can be many ans, return any
// Any number which is already present in BST will not be asked to be inserted.
Logic:
Find where it can be? and insert..

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        TreeNode *cur = root;   // making a copy of the root, bcz in last we need to return root.
        while(true){
            if(cur->val <= val){                          // badi value insert karani hai toh wo right mein insert hogi
                if(cur->right!=NULL) cur = cur->right;    // will keep moving to right jab tak not null ar <= follow hoga
                else{                                     // its null ie should have been on the right side, but its not there so we insert it
                    cur->right = new TreeNode(val);
                    break;
                }
            }
            else{                                        // har left right jaane pe cur ka comparison hoga
                if(cur->left!=NULL) cur = cur->left;
                else{
                    cur->left = new TreeNode(val);
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

