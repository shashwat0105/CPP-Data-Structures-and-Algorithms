https://youtu.be/fnmisPM6cVo
https://takeuforward.org/data-structure/check-for-children-sum-property-in-a-binary-tree/

// Given u only can increase the value and cannot decrease.

(Isme node value ko change karke kya esa tree agar nahi hai toh bana skte hai esa pucha hai)
(While going down increase the nodes value to the maximum possible(so that u never fell shortage), while coming back just add the value to get node value)
(Thus any given binary tree can be converted to such binary tree using this method)

void changeTree(BinaryTreeNode <int> *root){
    if(root==NULL) return;
    int child = 0;
    if(root->left){
        child += root->left->data;                 // if the left exist, add it to the child variable
    }
    if(root->right){
        child += root->right->data;                // if the right exist, add it
    }

    // Now I want to see whether I want to update child nodes data or root data: jo chota hai use bada banaenge.
    if(child >= root->data) root->data = child;  // agar dono bottom nodes k sum(child variable) ki value badi thi root ki value se toh root ki value ko badha do equivalent to the sum
    else{
        root->left->data = root->data;           // else dono bottom nodes ki value ko root k barabar kar do
        root->right->data = root->data;
    }

    // I do above while going down.
    changeTree(root->left);
    changeTree(root->right);

    // I do below when I come back.
    int tot = 0;
    if(root->left) tot += root->left->data;
    if(root->right) tot += root->right->data;
    if(root->left or root->right) root->data = tot;  // while going back we update the value of root
}



// Just return true or false 
https://practice.geeksforgeeks.org/problems/children-sum-parent/1/

Check whether all of its nodes have the value equal to the sum of their child nodes.

// Using DFS

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value equal to the sum of their child nodes.
    int isSumProperty(Node *root){    // returning either 1 or 0 so it is bool only
     // Add your code here
        if(root==NULL) return 1;
        
        if(root->left==NULL && root->right==NULL) return 1;  // they are leaf nodes
        
        // else
        int sum=0;
        if(root->left) sum += root->left->data;
        if(root->right) sum += root->right->data;
        if(sum!=root->data) return 0;
        
        bool a = isSumProperty(root->left);
        bool b = isSumProperty(root->right);
        
        return a&b;   // or return isSumProperty(root->left) & isSumProperty(root->right);
    }
};

// Using BFS

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root){ 
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; ++i){
                auto node = q.front();
                q.pop();
                int sum = 0;
                if(node->left){
                    q.push(node->left);
                    sum+=node->left->data;
                }
                if(node->right){
                    q.push(node->right);
                    sum+=node->right->data;
                }
                if(sum && sum!=node->data) return 0;
            }
        }
        return 1;
    }
};
