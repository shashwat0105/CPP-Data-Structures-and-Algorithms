https://leetcode.com/problems/binary-tree-level-order-traversal/
Isme vector of vector return karte hai unlike other three traversals

https://youtu.be/EoAsWbO7sqg

TC = O(N)
SC = O(N)  // queue


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;                         // if the tree given to us is empty
        queue<TreeNode*> q;                                // queue will store nodes of the tree, so we make it of that type
        q.push(root);
        
        while(!q.empty()){                                 // first I will have one element in queue, then no of elements in next layer, and so on  (Ek depth k saare elements ko queue m dalega fr dusre depth k saare elements ko dalega)
            int size = q.size();
            vector<int> level;
            for(int i=0; i<size; ++i){                     // traverse for every queue element // For loop is used to keep track of the levels.
                TreeNode* node = q.front();                // take that node 
                q.pop();                                   // take it out
                if(node->left)  q.push(node->left);        // and push the left and right of that node
                if(node->right) q.push(node->right);
                level.push_back(node->val);                // storing the value of the node in a vector
            }
            ans.push_back(level);                          // pushing all the levels
        }
        return ans;
    }
};

// In above code I am traversing left to right in every level.
// If I want to traverse from right to left in every level.
if(root->right) q.push(root->right);    // I am traversing right to left       
if(root->left)  q.push(root->left);

// In n-ary tree
https://leetcode.com/problems/n-ary-tree-level-order-traversal/

// Diagonal Traversal 
https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/

Saare left waalo ko queue m pehle daalo if they exist simultaneously moving in the right direction
void solve(Node *root, vector<int> &ans){
    if(root==NULL) return;
    
    queue<Node *> q;
    q.push(root);
    
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        while(temp){
            ans.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            temp = temp->right;
        }
    }
}

vector<int> diagonal(Node *root){
   vector<int> ans;
   solve(root, ans);
   return ans;
}