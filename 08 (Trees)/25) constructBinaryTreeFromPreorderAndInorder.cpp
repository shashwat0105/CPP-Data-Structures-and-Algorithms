https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

https://youtu.be/aZNaLrVebKQ 

Subtrees ka bhi inorder ar preorder dekho ar recursively call karo!!

// The first element of preorder will be the root.
// Find that element in the inorder(quick fetch can be done using hashmap as given the values are unique)
// This will divide the array in two parts, left part will be inorder of left subtree and right part will be inorder of right subtree
// Say there were x number of nodes in the left part of that array, that much elements take from preorder array to get preorder of leftsubtree

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;
        for(int i=0; i<inorder.size(); ++i){
            inMap[inorder[i]] = i;             // hashed the inorder vector
        }
        
        TreeNode *root = treeMaker(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        return root;
    }
    
    TreeNode * treeMaker(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        
        TreeNode *root = new TreeNode(preorder[preStart]);           // finding the root node in the preorder vector everytime
        
        int inRoot = inMap[root->val];                               // finding that root obtained from preorder in inorder vector using the hashmap created earlier
        int numbersInLeft = inRoot - inStart;
        
        root->left = treeMaker(preorder, preStart+1, preStart+numbersInLeft, inorder, inStart, inRoot-1, inMap); // again building in left subtree  (In do recursive calls ki changed values na smjh/bhul aye toh video ka mid to last part dekh lena)
        root->right = treeMaker(preorder, preStart+numbersInLeft+1, preEnd, inorder, inRoot+1, inEnd, inMap);    // again building in right subtree
        
        return root;
    }
};

//
TC = O(NlogN)
SC = O(N)

