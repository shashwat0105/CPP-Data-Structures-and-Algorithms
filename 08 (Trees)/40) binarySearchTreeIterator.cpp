https://leetcode.com/problems/binary-search-tree-iterator/

// If you are allowed to store the inorder in a vector, then this problem is easy.
// You can tell which number is next or whether next exists or not.
// I have submitted this code as well(see submissions)

// If you are not allowed.

https://youtu.be/D2jMcmxU4bs  (Video dekh lena dry run se hi samjhega agar bhul jao) // Striver

// Crux is wrting next():  When next() be called, I just pop one element and process its right child as new root, by adding all left left of this node.

// SC = O(H) as at a particular time u will store height number of elements in the stack 
// TC = O(1)  // Amortised or Average

class BSTIterator {
private: stack<TreeNode *> s;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode *temp = s.top();    // Always top element of the stack is the next guy
        s.pop();                     // and remove it
        pushAll(temp->right);        // Now we push more elements in stack: agar us element ka right exist karta hai toh ab us right wale ko pushAll kar do ie uske saare left left lo ar stack mein daal do
        return temp->val;            // jo next node hai uski value return kar do
    }
    
    bool hasNext() {
        return !s.empty();          // if stack has some elements or not 
    }
private:
    void pushAll(TreeNode *node){   // take all the left left and push it into the stack // this is kind of partial inorder.
        while(node){
            s.push(node);
            node = node->left;
        }
    }
};


// Follow up:
// Implement before()
// Push All right
// Right Node Left : Sorted in descending order.

