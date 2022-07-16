https://leetcode.com/problems/recover-binary-search-tree/

// First brute force approach that comes to mind
// I will do any traversal
// Then I sort the vector, I will get correct inorder of the BST
// I inorder traverse the given incorrect bst and compare this with sorted vector and change the values.
// TC = O(2N + NLOGN), SC = O(N)

// Optimised
// Swap can have two cases in an array
// 1) The swapped elements are not adjacent
// While doing the inorder traversal, you can keep track of previous node and current node, there will be two points of violation.
// Then you can swap the two
// {3, 25,   7, 8, 10, 15, 20, 5} : 25 and 5 wer swapped
      first mid              last                      
// 2) The swapped elements are adjacent
// Here, only one violation will be found while moving.
// {3, 5, 8, 7, 10, 15, 20, 25}: 8, 7 were swapped

// TC = O(N)
// SC = O(N) in recursive and O(1) in morris(Yeh interviewer ko bol skte ho ki morris bhi exist krta hai)

class Solution {
private:                  // these are member variables not global variables becoz these are declared inside a class
    TreeNode *first;
    TreeNode *prev;
    TreeNode *middle;
    TreeNode *last;
public:
    void inorder(TreeNode* root) {
        if(root==NULL) return;
        inorder(root->left);
        
        if(prev!=NULL && (root->val < prev->val)){   // all the business
            // if this is the first violation mark these two nodes as first and middle
            if(first==NULL){
                first = prev;
                middle = root;
            }
            // If this is the second violation, mark this node as last
            else{                                    // first value has been changed hence it is the second violation
                last = root;
            }
        }
        // mark this node as previous
        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode *root){
        first = middle  = last = NULL;                           // sabko null bana dia
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);           // if there are two violations
        else if(first && middle) swap(first->val, middle->val);  // if there is one violation
    }
};


