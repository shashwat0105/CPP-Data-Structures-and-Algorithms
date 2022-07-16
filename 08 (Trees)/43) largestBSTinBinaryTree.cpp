https://practice.geeksforgeeks.org/problems/largest-bst/1

// Brute force:
// For every node apply "Validate BST" problem ka solution: O(N*N) TC
// Again pass that node to find the number of nodes. 
// 

// Optimisation
https://youtu.be/X0oXMdtUDwo

// Largest Node in the left side < Node < Smallest Node in right side
// size = no. of elements on left + no. of elements on right + 1

// TC = O(N), SC = O(1)

// Solution courtesy LC Discuss: waha se ar bhi dekh lena 
// Abhi isko bhi khud se solve krna hai

class NodeValue{
public:
    int maxNode, minNode, maxSize;
    
    NodeValue(int minNode, int maxNode, int maxSize){
        this->maxNode =  maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution{
    private:
    NodeValue largestBSTSubtreeHelper(Node *root){
        // An empty tree is a BST of size 0
        if(root==NULL) return NodeValue(INT_MAX, INT_MIN, 0);
        
        // Get values from left and right subtree of current tree
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        // Current node is greater than max in left AND smaller than min in right
        if(left.maxNode < root->data && root->data < right.minNode){
            // It is a BST
            return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize+right.maxSize+1);
        }
        
        // Otherwise, return[-inf, inf] so that parent cant be a valid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
    	return largestBSTSubtreeHelper(root).maxSize;
    }
};

