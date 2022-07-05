https://leetcode.com/problems/boundary-of-binary-tree/
(premium ques hai)

https://youtu.be/0ca1nvR0be4  (Striver)

We will do anticlockwise boundary traversal.

https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1/


// Left boundary excluding leafs    
// Leaf Nodes  (For getting leaf nodes, )
// Right boundary in reverse order excluding leafs ()

// For left boundary:
// You will start from root's left
// If there is a left node go to left, if there is not a left node go to right.
// Until you reach a leaf node.

// For leaf nodes:
// To print the leaf nodes, we can do a simple preorder traversal, and check if the current node is a leaf node or not. If it is a leaf node just print it.

// For right boundary in reverse order:
// You will start from root's right.
// Go to right, right, if there does not exist a right, go to left until you reach a leaf node.
// store the elements in  a stack/vector and add the elements from the top to the data structure

// This ques is made up of:
// Root, Left Boundary, Leaf and Right Boundary
// Not left view, bottom view and right view questions

class Solution {
public:
    bool isLeaf(Node *node){
        return (node->left==NULL && node->right==NULL);
    }
    
    void leftBoundary(Node *root, vector<int> &res){
        Node * curr = root->left;
        while(curr){
           if(!isLeaf(curr)) res.push_back(curr->data);
           if (curr->left) curr = curr->left;
           else curr = curr->right;
        }
    }
    
    void addLeafNodes(Node *root, vector<int> &res){
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left) addLeafNodes(root->left, res);
        if(root->right) addLeafNodes(root->right, res);
    }
    
    void rightBoundary(Node *root, vector<int> &res){
        Node *curr = root->right;
        vector<int> temp;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        for(int i=temp.size()-1; i>=0; --i){
            res.push_back(temp[i]);
        }
    }
    vector <int> boundary(Node *root){
        //Your code here
        vector<int> res;
        if(root==NULL) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        leftBoundary(root, res);
        addLeafNodes(root, res);
        rightBoundary(root, res);
        return res;
        
    }
};




// Instead of while using recursive goin down the tree
private: void traverseleft(Node *root,vector<int> &ans){
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
        return;
    ans.push_back(root->data);                      // isme jaate time hi push kar dia
    if(root->left)
        traverseleft(root->left,ans);
    else
        traverseleft(root->right,ans);
}
   
void traverseleaf(Node *root,vector<int> &ans){
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(root->data);
            return;
        }
        traverseleaf(root->left,ans);
        traverseleaf(root->right,ans);
}
void traverseright(Node *root,vector<int> &ans){
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
        return;
    
    if(root->right)
        traverseright(root->right,ans);
    else
        traverseright(root->left,ans);
        
    ans.push_back(root->data);                 // adding data while going back, can say post order type  
}
public:
   vector <int> boundary(Node *root)
   {
       vector<int> ans;
       if(root==NULL)
           return ans;
       
       ans.push_back(root->data);
       //left part
       traverseleft(root->left,ans);
       //left leaf
       traverseleaf(root->left,ans);
       //right leaf
       traverseleaf(root->right,ans);
       //Right part
       traverseright(root->right,ans);
       
       return ans;
       //Your code here
   }

