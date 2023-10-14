https://leetcode.com/problems/maximum-depth-of-binary-tree/  (This ques is in recursion folder)
 
https://leetcode.com/problems/balanced-binary-tree/

Balanced BT = For every node: Height of Left subtree - Height of Right subtree <= 1

// Naive solution to go on every node and check for the above condition

// Proper solution
// We know to find height of tree from a node in O(n) time.
// I want to return boolean true false as well as height(integer) so what I will do?:
// If it is not a balanced tree it returns -1, else returns the height of the tree.

// This code can be slightly faster due to "early return" as soon as u get an unbalanced node.
class Solution {
public:
    bool isBalanced(TreeNode* root) {
       return dfsHeight(root)!=-1;
    }
    
    int dfsHeight(TreeNode* root){
        if(root==NULL) return 0;
        
        int lH = dfsHeight(root->left);
        // cout<<lH<<endl;
        if(lH==-1) return -1;     
              
        int rH = dfsHeight(root->right);
        // cout<<rH<<endl;
        if(rH==-1) return -1;
        
        if(abs(lH-rH)>1) return -1;
        return max(lH, rH)+1;
    }
};

// But what is the need of checking lH==-1, rH==-1? (Common doubt, ie ki height kab negative ho jaegi)

// I was also confused by the return -1.
// Please understand that when you return something in recursion it goes to the calling function just above the stack.
// Take the example [1,2,2,3,null,null,3,4,null,null,4], this is a case where the tree is unbalanced at 2 but balanced at root that is 1.
// Now lets us consider the case where we do NOT write if (lH==-1 || rH==-1) return -1; then only the call that was one step above the stack receives -1 but the thing is once we find the difference is -1, there is no point in further calculations (cause the tree will be unbalanced).
// And to propagate this we have to return -1 everytime without changing the value until the first call on the stack which is in the isBalanced() function.

// Also,,
// The -1 is actually returned by the statement
// if(lH-rH<-1 || lH-rH>1){
// return -1;
// }

// Baaki code toh simple hai

// Ek ar similar code (more concise and readable)

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int flag = false;  // false means it is balanced
        height(root, flag);
        return !flag;
    }

    int height(TreeNode *root, int &flag){
        if(root==NULL) return 0;

        int lH = height(root->left, flag);
        int rH = height(root->right, flag);

        if(abs(lH-rH)>1) flag = true; // ie it is unbalanced // Instead of returning ek variable ki value change kar di
        return max(lH, rH) + 1;
    }
};
