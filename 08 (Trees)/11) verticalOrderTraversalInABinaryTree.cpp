https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

https://youtu.be/q_a6lpbKJdw

// Coordinates bana k kiya hai tab clearly visualise hoga!! (See above video)

// Using level order traversal(Queue DS), can use other traversal algorithms.
// As I traverse, on reaching every node I need to assign verticals, levels ie x, y coordinates.
// I haven't used for loop(i in range size of q), because I just want to traverse all the nodes. 


// Using verticals and levels.

// On moving left: vertical changes by -1, and level by +1
// On moving right: vertical changes by +1 and level by +1

// After popping we put it into vertical -> level -> multset value

// Queue(node, vertical, level)

// map<int,    map<int, multset<int>>>
//   verticals    levels      on every level there can be multinodes of different or same value(so multiset). Also multiset stores in sorted order
// Ek hi vertical k saari nodes sorted ni chahta hai. Ek hi vertical k ek same level ki nodes bas sorted ho, isliye vertical k sath uska level bhi store krna pada.

**** CODE **** TC and SC are O(N)

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});                                         // node, vertical, level
        
        while(!q.empty()){                                              // performing level order traversal
            auto p = q.front();                                         // I take the node
            q.pop(); 
            TreeNode* node = p.first;
            int vertical = p.second.first, level = p.second.second;        // I take the vertical, I take the level
            mp[vertical][level].insert(node->val);                         // insert in our DS (in vertical and level) (multiset so we insert it)
            if(node->left){                                                // if there is left or right put it into our queue
                q.push({node->left, {vertical-1, level+1}});
            }
            if(node->right){
                q.push({node->right, {vertical+1, level+1}});
            }
        }                                                                  // level order traversal is completed
        
        vector<vector<int>> ans;
        for(auto p: mp){                                                   // Just traversing in our DS to get ans  (For every vertical ie -2, -1, 0, 1 , 2)
            vector<int> col;
            for(auto q: p.second){                                         // traversing for every level
                col.insert(col.end(), q.second.begin(), q.second.end());   // mtlb col vector k end mein jitne bhi multiset k elements hai wo daal do
            }                                                              // ek doubt yeh bhi hai ki .insert kyu use kia hai ar push_back use karne pe galat aa raha, ar baaki jagah insert use karne pe galat!
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

// Using DFS (This is also good)
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/solutions/2703650/dfs-explained-with-example-c/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map < int, map < int, multiset < int >>> nodes;
        traverse (root, 0, 0, nodes);
        vector<vector< int >> ans;
        for (auto p: nodes) {
            vector < int > col;
            for (auto q: p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
private:
    void traverse(TreeNode *root, int vertical, int level, map<int, map<int, multiset<int>>> &mp){
        if(root == NULL) return;
        mp[vertical][level].insert(root->val);

        traverse(root->left, vertical-1, level+1, mp);
        traverse(root->right, vertical+1, level+1, mp);
        return;
    } 
};
