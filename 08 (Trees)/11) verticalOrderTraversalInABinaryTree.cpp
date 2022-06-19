https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

https://youtu.be/q_a6lpbKJdw

Coordinates bana k kiya hai tab clearly visualise hoga!! (See above video)

Using level order traversal(Queue DS), can use other traversal algorithms.

Using verticals and levels.

On moving left: vertical changes by -1, and level by +1
On moving right: vertical changes by +1 and level by +1

After popping we put it into vertical -> level -> multset value

Queue(node, vertical, level)

map<int,    map<int, multset<int>>>
  vertical     levels      on every level there can be multinodes of different or same value.

**** CODE ****

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});                   // node, vertical, level
        
        while(!todo.empty()){                        // performing level order traversal
            auto p = todo.front();                   // I take the node
            todo.pop(); 
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;  // I take the vertical, I take the level
            nodes[x][y].insert(node->val);                // insert in our DS (in vertical x and level y) (multiset so we insert it)
            if(node->left){                               // if there is left or right put it into our queue
                todo.push({node->left, {x-1, y+1}});
            }
            if(node->right){
                todo.push({node->right, {x+1, y+1}});
            }
        }                                                // level order traversal is completed
        
        vector<vector<int>> ans;
        for(auto p: nodes){                              // traversing in our DS  (For every vertical ie -2, -1, 0, 1 , 2)
            vector<int> col;
            for(auto q: p.second){                       // traversing for every level
                col.insert(col.end(), q.second.begin(), q.second.end());   // mtlb col vector k end mein jitne bhi multiset k elements hai wo daal do
            }
            ans.push_back(col);
        }
        return ans;
    }
};

*******  
Vertical  Level    Element
0           0       {2}  
            1       {4, 5}
            2       {9, 9, 9}  

1          ... and so on

// Isme map wala insert ar last ka traversal analyse karna hai
// Basically map dikh kaisa raha hai wo dry run karna hai

