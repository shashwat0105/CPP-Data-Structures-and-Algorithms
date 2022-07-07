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
    
    arr.pop_back();                                                              // Else remove root’s data value from arr[] and return false.
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> arr;
    if(A==NULL) return arr;
    getPath(A, arr, B);
    return arr;
}

// In ques there is given b always exist.
