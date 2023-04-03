https://leetcode.com/problems/same-tree/

Method 1: During the traversal comparsion
We can do any traversal we know and solve the ques

bool isSameTree(TreeNode* p, TreeNode* q) {
    // If both trees are empty, they are the same
    if (!p && !q) {
        return true;
    }
    
    // If one of the trees is empty or they have different values, they are not the same
    if (!p || !q || p->val != q->val) {
        return false;
    }
    
    // Recursively check if the left and right subtrees are the same
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

Method 2: Comparing after complete traversal.
// Point: Agar do tree ka in order traversal same hoga toh tree same hoga - False
// Point: Agar kisi do tree k koi do traversal say In and Pre order same hai toh tree same hoga - True

// ie it takes two types of traversals to uniquely indentify a tree. (Also the location of NULL in traversal vector is to be given)
// ie while writing code we insert NULL or a large number say 10^5
// New code of inorder:

void inorder(TreeNode *root, vector<int>& v){
        if(root){
            inorder(root->left, v);
            v.push_back(root->val);
            inorder(root->right, v);
        }
        else{
            v.push_back(100000);
        }
}

// So in this ques, dono ka in ar pre order vector nikal k compare kar lo solve ho jaega ques

// Follow up:
https://leetcode.com/problems/subtree-of-another-tree/
