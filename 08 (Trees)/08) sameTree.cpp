https://leetcode.com/problems/same-tree/

We can do any traversal we know and solve the ques

// Algorithm for the recursion:
// 1)
// If one of the node is NULL then return the equality result of p and q.
// This boils down to if both are NULL then return true, 
// but if one of them is NULL but not the other one then return false
// 2)
// At this point both root nodes represent valid pointers ie both are not null
// Return true if the root nodes have same value and (Matlab node value same ho ar left ar right subtree bhi same ho)
// the left tree of the roots are same (recursion)
// and the right tree of the roots are same (recursion). 
// Otherwise return false. 

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL) return (p==q);
        
        return (p->val==q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);    // agar dono null nahi hai 
    }
};


// OR
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        if(p->val!=q->val)     return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


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
