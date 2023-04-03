https://www.interviewbit.com/problems/path-to-given-node/

// Either the node will be given or node value will be given.

// Path to given node
// Root to node path
// Root to leaf path
// These are the variations

// We will use preorder traversal as it will be simpler for this ques.
// We will start from root and find ki yeh wali node milti hai ya nahi.
// I try to go to every direction and use a DS to store the path values and return true, false accordingly if we get the desired value.

bool getPath(TreeNode* root, vector<int> &arr, int x){                           // using bool return type because we want to return false agar element na mila us particular path mein
    if(root==NULL){
        return false;
    }

    arr.push_back(root->val);

    if(root->val==x) return true;
    if(getPath(root->left, arr, x) || getPath(root->right, arr, x)) return true; // if node x is present in root’s left or right subtree, return true.
    
    arr.pop_back();                                                              // Else remove root’s data value from arr[] (backtrack) and return false.
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> arr;
    if(A==NULL) return arr;
    getPath(A, arr, B);
    return arr;
}

// In ques there is given b always exist.

// 
https://leetcode.com/problems/binary-tree-paths/

All paths from root to leaf is asked here.

class Solution {
public:
    void getPaths(TreeNode *root, string s, vector<string> &ans){
        if(!root->left && !root->right){
            ans.push_back(s);
            return;
        } 

        if(root->left) getPaths(root->left, s + "->" + to_string(root->left->val), ans);
        if(root->right) getPaths(root->right, s + "->" + to_string(root->right->val), ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;

        string s = to_string(root->val);
        getPaths(root, s, ans);
        return ans;
    }
};

// With backtracking
https://leetcode.com/problems/binary-tree-paths/solutions/1805157/c-backtracking/

https://leetcode.com/problems/binary-tree-paths/solutions/3147262/backtracking-c/
