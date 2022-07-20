https://leetcode.com/problems/binary-search-tree-iterator/

// Isko dusre solutions etc k sath ar revise ar solve krna hai baad mein khud se

// If you are allowed to store the inorder in a vector, then this problem is easy.
// You can tell which number is next or whether next exists or not.

// If you are not allowed.

https://youtu.be/D2jMcmxU4bs  (Video dekh lena dry run se hi samjhega agar bhul jao)

// SC = O(H) as at a particular time u will store height number of elements in the stack 
// TC = O(1)

class BSTIterator {
private: stack<TreeNode *> myStack;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode *tmpNode = myStack.top();    // top element of the stack is the next guy
        myStack.pop();                        // and remove it
        pushAll(tmpNode->right);              // agar us element ka right exist karta hai toh ab us right wale ko pushAll kar do ie uske saare left left lo ar stack mein daal do
        return tmpNode->val;                  // jo next node hai uski value return kar do
    }
    
    bool hasNext() {
        return !myStack.empty();   // if stack has some elements or not 
    }
private:
    void pushAll(TreeNode *node){   // take all the left left and push it into the stack
        for(; node!=NULL; myStack.push(node), node = node->left);
    }
    
};

// Other code:
class BSTIterator {
public:
    stack<TreeNode*> s;
    
    BSTIterator(TreeNode* root) {
        partialInorder(root);
        
    }
    void partialInorder(TreeNode* root){
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
    }
    int next() {
        TreeNode* top = s.top();
        s.pop();
        partialInorder(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

// Follow up:
// Implement before()
// Push All right
// Right Node Left : Sorted in descending order.

