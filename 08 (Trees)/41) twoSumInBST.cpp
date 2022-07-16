https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// Method 1: Brute Force:
// If I write the inorder traversal, I will get the array in sorted order.
// The ques becomes simply the old two sum problem.
// TC = O(N) + O(N), SC = O(N) 
// Any coding platform will accept it.

// But in interview, it will require more optimised approach.
// Implementing two pointer type approach in optimised time manner
// We can use
// i = next() to move to greater values  (Previous iterator problem se inspired)
// j = back() to move to smaller values

// TC = O(N), SC = O(2H)

https://youtu.be/ssL3sHwPeb4


class BSTIterator{
    stack<TreeNode *>myStack;
    // reverse->true = before
    // reverse->false = next
    
    bool reverse = true;
public:
    BSTIterator(TreeNode *root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    
    // return whether we have a next smallest number
    bool hasNext(){
        return !myStack.empty();
    }
    // return the next smallest number
    int next(){                                 // next naam dia hai but depending on value of reverse will act as reverse and before(DRY principle)
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->val;                    // return top value in the stack
    }
private:
    void pushAll(TreeNode *node){
        for(;node!=NULL;){
            myStack.push(node);
            if(reverse){                // if reverse is true ie before so I go right right right
                node = node->right;
            }
            else{                       // ie the trivial next, ie left left left
                node = node->left;  
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        BSTIterator l(root, false);      // initilised the left iterator, means next and passed false // created 1 object of that class
        BSTIterator r(root, true);       // initilised the right iterator, means before and passed true // created another object of that class, so it will be treated differently
        
        int i = l.next();
        int j = r.next();                // r.before() likhte agar do separate class bana k karte
        
        while(i<j){                      // two pointer approach
            if(i+j==k) return true;
            else if(i+j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};

// Iska bhi LC discuss, YT, self solve krna hai
// Striver said to right the above quality code in the interviews!!
