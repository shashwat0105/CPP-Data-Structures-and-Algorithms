https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

// The last element of postorder will be the root of the entire tree. Usko inorder m dhundho, uska left ar right part divide kar dega left ar right subtree mein and so on
// Again problem can be broken into subtrees whose inorder and postorders are given.

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;
        
        map<int, int> inMap;
        for(int i=0; i<inorder.size(); ++i){
            inMap[inorder[i]] = i;             // hashed the inorder vector
        }
        return treeMaker(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inMap);
    }
    
    TreeNode * treeMaker(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, map<int, int> &inMap){
        if(postStart>postEnd || inStart>inEnd) return NULL;
        
        TreeNode *root = new TreeNode(postorder[postEnd]);            // finding the root node in the postorder vector everytime which will always be at the end
        
        int inRoot = inMap[root->val];                               // finding that root obtained from preorder in inorder vector using the hashmap created earlier
        int numbersInLeft = inRoot - inStart;
        
        root->left = treeMaker(inorder, inStart, inRoot-1, postorder, postStart, postStart+numbersInLeft-1, inMap); // again building in left subtree
        root->right = treeMaker(inorder, inRoot+1, inEnd, postorder, postStart+numbersInLeft, postEnd-1, inMap);    // again building in right subtree
        
        return root;
    }
};

