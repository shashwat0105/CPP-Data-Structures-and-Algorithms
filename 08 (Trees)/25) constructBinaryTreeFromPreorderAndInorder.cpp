https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// Subtrees ka bhi inorder ar preorder dekho ar recursively call karo!!

// The first element of preorder will be the root.
// Find that element in the inorder(quick fetch can be done using hashmap as given the values are unique)
// This will divide the array in two parts, left part will be inorder of left subtree and right part will be inorder of right subtree
// Say there were x number of nodes in the left part of that array, that much elements take from preorder array to get preorder of leftsubtree

// Method 1:  https://youtu.be/G5c1wM3Kpuw  (MIK)
// TC = O(N^2) // bcz O(n) for traversing in preorder and O(n) for searching in inorder.
// SC = Stack space

// Using 3 variables, start, end, idx : start end move in inorder. While idx move in preorder.
class Solution {
public:
    TreeNode *solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int &idx){ // idx passed by ref
        if(start>end) return NULL;

        int rootVal = preorder[idx];
        int i = start;
        while(inorder[i]!=rootVal) i++;  // finding i in inorder
        idx++; // is index ka kaam ho gya

        TreeNode *root = new TreeNode(rootVal);
        root->left = solve(preorder, inorder, start, i-1, idx);
        root->right = solve(preorder, inorder, i+1, end, idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;
        return solve(preorder, inorder, 0, n-1, idx);
    }
};


// Method 2: https://youtu.be/aZNaLrVebKQ (Striver)
Build a hashmap to record the relation of value -> index for inorder, so that we can find the position of root in constant time.
// TC = O(N)
// SC = Stack Space + Map Space

// Using 3 variables, start, end, idx : start and end move in inorder. While idx move in preorder.
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> hash;
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            hash[inorder[i]] = i;
        }
        int idx = 0;
        return buildTreeHelper(preorder, hash, 0, n - 1, idx);
    }
    
    TreeNode* buildTreeHelper(vector<int>& preorder, unordered_map<int, int>& hash, int start, int end, int& idx) {
        if (start > end) {
            return NULL;
        }
        int curr = preorder[idx];
        idx++;
        TreeNode* node = new TreeNode(curr);
        int pos = hash[curr];
        node->left = buildTreeHelper(preorder, hash, start, pos - 1, idx);
        node->right = buildTreeHelper(preorder, hash, pos + 1, end, idx);
        return node;
    }
};

// Using 4 variables:
// By using 4 variables to represent the range of indices of the inorder array for each recursive call, we explicitly define the range of indices for the left and right subtrees, 
// making it easier to reason about the code. Additionally, it allows us to calculate the length of each subtree by subtracting the indices of the left and right subtrees.

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for(int i=0; i<inorder.size(); ++i){
            inMap[inorder[i]] = i;             // hashed the inorder vector
        }
        
        TreeNode *root = treeMaker(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        return root;
    }
    
    TreeNode * treeMaker(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int> &inMap, int preStart, int preEnd, int inStart, int inEnd){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        
        TreeNode *root = new TreeNode(preorder[preStart]);           // finding the root node in the preorder vector everytime
        int inRootIdx = inMap[root->val];                            // finding index of that root obtained from preorder in inorder vector using the hashmap created earlier
        int numsInLeft = inRootIdx - inStart;
        
        root->left = treeMaker(preorder, inorder, inMap, preStart+1, preStart+numsInLeft, inStart, inRootIdx-1); // again building in left subtree  (In do recursive calls ki changed values na smjh/bhul aye toh video ka mid to last part dekh lena)
        root->right = treeMaker(preorder, inorder, inMap, preStart+numsInLeft+1, preEnd, inRootIdx+1, inEnd);    // again building in right subtree
        
        return root;
    }
};

//  In each recursive call, we find the root node of the current subtree in the preorder array using the preStart index, 
//  and then we use the hash map mp to find the index of the root node in the inorder array, which gives us the sizes of the left and right subtrees.

// For quick revise
Pre :
[preStart+1, preStart+numsInLeft]  // Left half  // Root is eliminated(root is the first node)
[preStart+numsInLeft+1, preEnd]    // Right half // ie jaha se left wala pre khatam hua hoga uske baad se hi toh right wala pre start hoga.

In:
[inStart, inRootIdx-1]              // Left half // Root is in between the halves so eliminated.
[inRootIdx+1, inEnd]


// Adding leetcode discuss links:
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solutions/2279613/c-recursive-using-map-approaches/
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solutions/34538/my-accepted-java-solution/
