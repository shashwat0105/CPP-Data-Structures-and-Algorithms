// https://leetcode.com/problems/binary-tree-maximum-path-sum/

// Any node to any :- leaf to leaf, non leaf to leaf, leaf to non leaf, non leaf to non leaf (any combo, no restriction)

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 
The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42

        10
        / \
       2    10
      /  \    \
    20    1   -25
              /  \
             3    4

Output = 20 + 2 + 10 + 10  = 42

temp <- max(20, 9) + value of parent node  // makes sense
temp <- max(-40, -10) + value of parent node // does not make sense, better we just take val of parent node only
ans <- l + r + val of parent node

// Code

int solve(Node * root, int& res){  
    // BASE CONDITION
    if(root == nullptr){
        return 0;
    }

    // HYPOTHESIS SAME FOR EVERY QUES
    int l = solve(root->left, res);
    int r = solve(root->right, res);

    // INDUCTION STEPS CHANGES ACC TO QUES (here temp and relation)
    int temp = max(max(l,r) + root->value, root->value); // combining the 2 cases when it dont wants to be the turning the node, max of value when it is +ve or -ve node
    int ans = max(temp, l + r + root->value);
    res = max(res, ans);

    return temp; 
}

int main(){
    int res = INT_MIN;
    solve(root,res);
    return res;
}




// WORKING CODE FOR LEETCODE PROBLEM // https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Same as above only
int solve(TreeNode* root,int& res)
{
    if(root==nullptr)
    {
        return 0;
    }
    
    int l=solve(root->left,res);
    int r=solve(root->right,res);
    
    int temp=max(max(l,r)+root->val,root->val);
    int ans=max(temp,l+r+root->val);
    res=max(res,ans);
    
    return temp;
}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
    int res=INT_MIN;
    solve(root,res);
    return res;
        
    }
};


