https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// Same as level order traversal except every alternate level is reversed.

We will
1) keep a queue as usual
2) a vector
3) A flag: true (Direction is from left to right)
         : false (Direction is from right to left)

TC = O(N)
SC = O(N)

*** CODE ***

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;                     // tree is empty
        
        queue<TreeNode *> nodesQueue;
        nodesQueue.push(root);
        bool flag = true;                              // flag is leftToRight (marking initially it as true)
        
        while(!nodesQueue.empty()){
            int size = nodesQueue.size();
            vector<int> row(size); 
            for(int i=0; i<size; ++i){                 // I take all the nodes of a level and run a for loop    
                TreeNode * node = nodesQueue.front();
                nodesQueue.pop();
                
                // find position to fill nodes value
                int index = (flag)? i: (size-i-1);     // depending on true/false of the flag I fill the value either at the front of row vector or end of row vector   (different step) 
                row[index]=node->val;                  // filling the value
                
                if(node->left){                        // I check the left and right and push it
                    nodesQueue.push(node->left);
                }
                if(node->right){
                    nodesQueue.push(node->right);
                }
            }
            // after this level
            flag = !flag;                              // reverse the flag (Different step)
            ans.push_back(row);
        }
        return ans;
    }
};

// Better code
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode *> q;
        q.push(root);
        int flag = 0;       // left to right
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0; i<size; ++i){
                TreeNode *node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                level.push_back(node->val);
            }
            if(flag==1){
                reverse(level.begin(), level.end());
                flag=0;
            }
            else{
                flag=1;
            }
            ans.push_back(level);
        }
        return ans;
    }
};