https://leetcode.com/problems/boundary-of-binary-tree/
(premium ques hai)

https://youtu.be/0ca1nvR0be4  (Striver)

We will do anticlockwise boundary traversal.

https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1/

Steps:
// 1) Left boundary excluding leafs    
// 2) Leaf Nodes  (For getting leaf nodes, )
// 3) Right boundary in "reverse" order excluding leafs ()

// For left boundary:
// Take a pointer(curr) that start from root's left
// If there is a left node go to left, if there is not a left node go to right. (ie either u go left or right)
// Until you reach a leaf node.

// For leaf nodes:
// To print the leaf nodes, we can do a simple preorder traversal, and check if the current node is a leaf node or not. 
// If it is a leaf node just print it.
// We can do any traversal just left to right print hona chahiye. Here we go first left and then right(ie dono jana hai)


// For right boundary in reverse order:
// Take a pointer(curr) that start from root's right.
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
    
    void addLeftBoundary(Node *root, vector<int> &res){
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
    
    void addRightBoundary(Node *root, vector<int> &res){
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
        addLeftBoundary(root, res);
        addLeafNodes(root, res);
        addRightBoundary(root, res);
        return res;
    }
};




// Instead of a while loop using recursive going down the tree
void traverseleft(Node *root, vector<int> &ans){
    if(!root || (root->left==NULL && root->right==NULL)) return;  // if root is null or leaf node found.
    
    ans.push_back(root->data);                                    // isme jaate time hi push kar dia
    if(root->left) traverseleft(root->left,ans);
    else traverseleft(root->right,ans);
}
   
void traverseleaf(Node *root, vector<int> &ans){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    traverseleaf(root->left, ans);
    traverseleaf(root->right, ans);
}


void traverseright(Node *root,vector<int> &ans){
    if(!root || (root->left==NULL && root->right==NULL)) return;  // if root is null or leaf node found.
    
    if(root->right) traverseright(root->right,ans);
    else traverseright(root->left,ans);
    ans.push_back(root->data);                 // adding data while going back, can say post order type  
}

public:
   vector <int> boundary(Node *root){
       vector<int> ans;
       if(root==NULL)
           return ans;
       
       if(root->left || root->right) ans.push_back(root->data);  // wo leaf node na ho toh hi I will push

       traverseleft(root->left,ans);          //left part
       traverseleaf(root,ans);                //leaf part
       traverseright(root->right,ans);        //Right part
       
       return ans;
    }
