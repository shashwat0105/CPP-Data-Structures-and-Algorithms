https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// Method 1: Brute Force:
// If I write the inorder traversal, I will get the array in sorted order.
// The ques becomes simply the old two sum problem.
// TC = O(N) + O(N), SC = O(N) 
// Any coding platform will accept it.
// Checking the target value during the search, which makes the solution conciser.
unordered_set<int> s;
bool findTarget(TreeNode* root, int k) {
    if (!root) return false;
    if (s.count(k - root->val)) return true;
    s.insert(root->val);
    return findTarget(root->left, k) || findTarget(root->right, k);
}

// Method 2:
// But in interview, it will require more optimised approach.
// Interviewer will expect this appraoch:
// Implementing two pointer type approach in optimised time manner
// We can use
// i = next() to move to greater values  (Previous iterator problem se inspired)  // start pointer
// j = back() to move to smaller values   // end pointer

// Next: Left Root Right // I get array sorted in ascending order
// Back: Right Root Left // I get array sorted in descending order

// TC = O(N), SC = O(2H)

https://youtu.be/ssL3sHwPeb4 (Striver GOD)

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
    int next(){                                 // next bas naam dia hai but depending on value of reverse will act as reverse and before(DRY principle)
        TreeNode *tmpNode = myStack.top();      // stack top will be next or before whatever u are calling.
        myStack.pop();
        if(!reverse) pushAll(tmpNode->right);   // Trivial: Right jao ar fr uske left left daal do
        else pushAll(tmpNode->left);            // If reverse is true ie I want back element, so left jao ar fr uske right right daal do.
        return tmpNode->val;                    // return top value in the stack
    }
private:
    void pushAll(TreeNode *node){
        while(node){
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
        BSTIterator l(root, false);      // initilised the left iterator, passed false means this is next // created 1 object of that class
        BSTIterator r(root, true);       // initilised the right iterator, passed true means this is before // created another object of that class, so it will be treated differently
        
        int i = l.next();
        int j = r.next();                // r.before(); likhte agar do separate class bana k karte, usi code ko modify kr dia taaki wo do functionality perform kr de
        
        while(i<j){                      // two pointer approach
            if(i+j==k) return true;
            else if(i+j < k) i = l.next(); // I will call ki iska next element dedo ab
            else j = r.next();             // I will call ki ab peeche se before element de do(bas naam next rakha hai kaam back wala karta hai coz reverse is true.)
        }
        return false;
    }
};

// LC Discuss:
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/solutions/1420711/c-java-python-3-solutions-hashset-stack-python-yield-solutions-o-h-space/

// Striver said to right the above quality code in the interviews!!
