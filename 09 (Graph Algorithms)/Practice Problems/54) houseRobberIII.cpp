https://leetcode.com/problems/house-robber-iii/

// Ans: max(Sum of even levels, Sum of odd levels) (Actually Not)
// Instead: Basically you want to compare which one is bigger between 1) you + sum of your grandchildren and 2) sum of your children.

// This is why: why level order traversal won;t work here? used queue to implement this but it is not working for this case: 4->1->2->3, 
// here correct o/p: 7(4+3) but mine is max(6,4): 6.
//  Level Order traversal will not work because as this case: 4->1->2->3, max sum could be between Odd level or even level which is not directly connected 


// Without memoisation (TLE)
class Solution {
public:
    int rob(TreeNode* root) {
        if(root==NULL) return 0;
        
        int evenSum = root->val;  // sum of 0, 2, 4, 6... levels
        
        if(root->left){
            evenSum+=rob(root->left->left);
            evenSum+=rob(root->left->right);
        }
        if(root->right){
            evenSum+=rob(root->right->left);
            evenSum+=rob(root->right->right);
        }
        
        int oddSum = rob(root->left) + rob(root->right);
        
        return max(evenSum, oddSum);
    }
};

// Memoised the repetetive sum.

class Solution {
public:
    unordered_map<TreeNode *, int> umap;   // Isko andar declare
    int rob(TreeNode* root) {
        if(root==NULL) return 0;
        
        if(umap.find(root)!=umap.end()){
            return umap[root];
        }
        
        int evenSum = root->val;  // sum of 0, 2, 4, 6... levels
        
        if(root->left){
            evenSum+=rob(root->left->left);
            evenSum+=rob(root->left->right);
        }
        if(root->right){
            evenSum+=rob(root->right->left);
            evenSum+=rob(root->right->right);
        }
        
        int oddSum = rob(root->left) + rob(root->right);
        int res = max(evenSum, oddSum);
        umap[root] = res;
        return res;
        
    }
};

// Other solution without map
// Instead: Basically you want to compare which one is bigger between 1) you + sum of your grandchildren and 2) sum of your children.

class Solution {
public:
    void maxSum(TreeNode* root, int &childSum, int &grandChildSum) {
        if (!root) return;

        if (root->right == root->left) {
            // no grand child so gChildSum is 0 and childSum is current value
            childSum = root->val;
            grandChildSum = 0;
            return;
        }
        
        // Collect left and right childSum and thier grandChild sum
        int lChildSum = 0;
        int rChildSum = 0;
        int lgrandChildSum = 0;
        int rgrandChildSum = 0;
        
        if (root->left)  maxSum(root->left, lChildSum, lgrandChildSum);
        if (root->right) maxSum(root->right,rChildSum, rgrandChildSum);
        
        // maximumm sum can be obtained from below :
        // 1. current node + grandchild's sum from next level
        // 2. childSum of the current level
        childSum = max((root->val + lgrandChildSum + rgrandChildSum),lChildSum+rChildSum);
        
        // make the current child sum as grandChildSum for next level
        grandChildSum = lChildSum + rChildSum;
        
        return;
    }
    int rob(TreeNode* root) {
        int childSum = 0;
        int grandChildSum = 0;
        maxSum(root,childSum,grandChildSum);
        return (childSum);
    }
};
