https://leetcode.com/problems/binary-tree-maximum-path-sum/

// Esa diameter jiski nodes values ka sum maximum ho. wo nikalna hai, toh jaha pe height k liye +1 karte the waha pe bas node ki values daal denge

If I am standing at a node,
I can figure out the max value at left and max value at right of that node, then max path sum using that node as a curve will be
maxL + val at that node + maxR

If I try this at every node and then I take their maximum.

Also we need to ignore all the negative path sums coming from left or right.

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }
    
    int maxPathDown(TreeNode *node, int &maxi){
        if(node==NULL) return 0;
        
        int leftSum = max(0, maxPathDown(node->left, maxi));      // 0 because if we get a -ve number we will not consider it instead we take 0. Coz kisi bhi node se kisi bhi node tak ka sum nikalna hai toh neeche ki nodes m jana jaroori nahi hai
        int rightSum = max(0, maxPathDown(node->right, maxi));
        maxi = max(maxi, leftSum + rightSum + node->val);         // formula of getting maximum
        return max(leftSum, rightSum) + node->val;                // now I am standing at a node, ab I will see ki yaha se left wale sum ko node ki value mein add krna hai ya right wale ko select karke add krna hai, isi ko toh return krna hai
    } 
};


https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/603072/C%2B%2B-solution-O(n)-with-detailed-explanation

