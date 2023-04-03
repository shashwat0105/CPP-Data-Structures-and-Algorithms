https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-sumtree/

Node = Sum of left Subtree + Right Subtree(not node) then return true else false

// Isme apne ko old node ka bhi track rakhna hoga so, bool mein dfs likhne m dikkat hogi. 

class Solution
{
    public:
    int calculateSum(Node *root, int &flag){
        if(root==NULL) return 0;                                       // sum ko 0 return krna hai
        if(root->left==NULL && root->right==NULL) return root->data;   // they are leaf nodes
        
        if(f==0) return 0;                              // dobara stack space recursion ki nahi lagegi agar f 0 ho jae beech mein
        int leftSum = calculateSum(root->left, flag);
        int rightSum = calculateSum(root->right, flag);
        
        // while going back
        if(root->data != leftSum+rightSum) flag = 0;    // marking flag as 0, when it violates the condition
        return leftSum + rightSum + root->data;
    }
    
    bool isSumTree(Node* root)
    {
         // Your code here
         int flag = 1; // ie it is a sum tree
         calculateSum(root, flag);
         return flag;
    }
};

// Transform to Sum tree
https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1/
https://www.geeksforgeeks.org/convert-a-given-tree-to-sum-tree/

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int solve(Node *node){
        if(node==NULL) return 0; 
        //if(node->left==NULL && node->right==NULL) node->data = 0;  (Iski jaroorat nahi hai, leftsum + rightsum 0+0 se ho jaega automatically qki uski left ar right node exist nahi karti(base case))
        
        int leftSum = solve(node->left);
        int rightSum = solve(node->right);
        // while going back
        int x = node->data;                      // save the old value, as it will get updated later
        node->data = leftSum + rightSum;
        return leftSum + rightSum + x;
    }
    
    void toSumTree(Node *node)
    {
        // Your code here
        solve(node);
    }
};


