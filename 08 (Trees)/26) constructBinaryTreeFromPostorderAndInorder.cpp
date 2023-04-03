https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

// The last element of postorder will be the root of the entire tree. Usko inorder m dhundho, uska left ar right part divide kar dega left ar right subtree mein and so on
// Again problem can be broken into subtrees whose inorder and postorders are given.

Inorder: [x 12 rem]  // x elements
Post :   [x rem 12]  // first x elements will be in left subtree , remaining elements will be in right subtree.


class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;
        
        unordered_map<int, int> inMap;
        for(int i=0; i<inorder.size(); ++i){
            inMap[inorder[i]] = i;             // hashed the inorder vector
        }
        return treeMaker(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inMap);
    }
    
    TreeNode * treeMaker(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int> &inMap){
        if(postStart>postEnd || inStart>inEnd) return NULL;
        
        TreeNode *root = new TreeNode(postorder[postEnd]);            // finding the root node in the postorder vector everytime which will always be at the end
        
        int inRoot = inMap[root->val];                               // finding that root obtained from preorder in inorder vector using the hashmap created earlier
        int numbersInLeft = inRoot - inStart;
        
        root->left = treeMaker(inorder, inStart, inRoot-1, 
                               postorder, postStart, postStart+numbersInLeft-1, inMap); // again building in left subtree
        root->right = treeMaker(inorder, inRoot+1, inEnd, 
                               postorder, postStart+numbersInLeft, postEnd-1, inMap);    // again building in right subtree
        
        return root;
    }
};

// For quick revise
In:
[inStart, inRootIdx-1]              // Left half // Root is in between the halves so eliminated.
[inRootIdx+1, inEnd]                // Right half

Post :
[postStart, postStart+numsInLeft-1]  // Left half  
[postStart+numsInLeft, postEnd-1]    // Right half  // Root is eliminated(root is the last node)
 
// Dry run on to find the left and right halfs:
       0 1  2  3  4  5
In:   40 20 50 10 60 30
Post: 40 50 20 60 30 10
