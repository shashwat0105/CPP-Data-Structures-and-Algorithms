Hard category
https://leetcode.com/problems/largest-bst-subtree/ (Premium)
https://practice.geeksforgeeks.org/problems/largest-bst/1

// Brute force:
// For every node apply "Validate BST" problem ka solution: O(N*N) TC
// Again pass that node to find the number of nodes. 


// Optimisation
https://youtu.be/X0oXMdtUDwo  (Striver)

The idea is to calculate the size of the largest BST subtree rooted at each node in the binary tree using a bottom-up approach, 
and maintain a global maximum to track the size of the largest BST subtree seen so far.

// Property to be followed.
// Largest Node in the left side < Node < Smallest Node in right side
// size = no. of elements on left + no. of elements on right + 1
// If a bottom guy is BST it will pass above, ki yeh bst hai and so on.

// I need largest from left, and smallest from right ie left and right have to be computed. ie I want left then right then I do the business ie Postorder.

// TC = O(N), SC = O(1)

// Solution courtesy LC Discuss: waha se ar bhi dekh lena 
// Abhi isko bhi khud se solve krna hai

class NodeValue{
public:
    int maxNode, minNode, maxSize;
    
    NodeValue(int minNode, int maxNode, int maxSize){
        this->maxNode =  maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution{
    private:
    NodeValue largestBSTSubtreeHelper(Node *root){
        // An empty tree is a BST of size 0
        if(root==NULL) return NodeValue(INT_MAX, INT_MIN, 0);
        
        // Get values from left and right subtree of current tree
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        // Current node is greater than max in left AND smaller than min in right
        if(left.maxNode < root->data && root->data < right.minNode){
            // It is a BST
            return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize+right.maxSize+1);
        }
        
        // Otherwise, return[-inf, inf] so that parent can not be a valid BST // size will be max of left max or right max
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    
    public:
        // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
    	return largestBSTSubtreeHelper(root).maxSize;
    }
};

// Follow up
https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

There are two cases:

1) If the Current Root be the root of the BST (when its value lies between maximum value in its left BST and minimum in its right BST). 
   In that case, the sum it will store will be simply, left_sum + right_sum + root->val.
2) Otherwise, the sum it will store will be max(left_sum,right_sum) because in this case we have max sum BST in either of its left and right subtree.

// See my submission, same as striver approach
// created class container to store maximum,minimum,and maxsum values
 class cont{
     public:
        int maxsum;
        int maxval;
        int minval;
    cont(int ms,int mx,int mi){
        maxsum=ms;
        maxval=mx;
        minval=mi;
    }
 };
class Solution {
public:
    int res;    // created this variable to keep track on maxsum till now
    cont solve(TreeNode* root){
        if(root==NULL){
            return cont(0,INT_MIN,INT_MAX);
        }

        auto left = solve(root->left);
        auto right=solve(root->right);

        if((root->val > left.maxval) && (root->val < right.minval)){  // If it is a BST
            int s=root->val+left.maxsum+right.maxsum;
            res=max(res,s);
            return cont(s,max(root->val,right.maxval),min(root->val,left.minval));
        }

        return cont(max(left.maxsum,right.maxsum),INT_MAX,INT_MIN);  // Not a BST
    }
    int maxSumBST(TreeNode* root) {
        res=0;
        solve(root).maxsum;
        return res; 
    }
};