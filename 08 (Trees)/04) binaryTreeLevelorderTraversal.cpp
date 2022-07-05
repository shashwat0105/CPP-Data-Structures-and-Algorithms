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
            int size=q.size();
            vector<int> level;
            for(int i=0; i<size; ++i){                     // traverse for every queue element
                TreeNode* node = q.front();                // take that node 
                q.pop();                                   // take it out
                if(node->left!=NULL)  q.push(node->left);  // and push the left and right of that node
                if(node->right!=NULL) q.push(node->right);
                level.push_back(node->val);                // storing the value of the node in a vector
            }
            ans.push_back(level);                          // pushing all the levels
        }
        return ans;
    }
};


