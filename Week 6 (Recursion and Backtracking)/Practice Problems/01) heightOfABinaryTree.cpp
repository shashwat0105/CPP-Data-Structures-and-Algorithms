https://leetcode.com/problems/maximum-depth-of-binary-tree/

https://youtu.be/aqLTbtWh40E

Hypothesis:
(Jo kaam karwana chahoge wo yeh karega)
height(root) = will give me height from root
height(root->left) = will give me height from left child
height(root->right) = will give me height from right child

Induction:
return 1 + max(leftHeight, rightHeight)

Base case:
// Think of smallest valid input
// coz leaf nodes of a tree will point to NULL ie height = 0;

// CODE:
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int lH = maxDepth(root->left);
        int rH = maxDepth(root->right);
        
        return 1 + max(lH, rH);
    }
};


// In interview you can clarify this from the interviewer.
The height of tree can be represented into two forms, according to nodes (above code) and according to edges. 
With some changes such as returning -1 instead of 0 will give the height in terms of edges.
