https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// Basically converted the tree into a graph
// When you have to traverse back use a map to store the parent node of a particular node
// Keep on moving 1 distance everytime(with every node u push in queue) radially outwards(in 3 directions: up, left, right) and mark it as visited.
// After k steps, nodes inside my queue ds, will be at a distance of k ie my ans

Let say u called for target node = 5 and u got: 6, 3 and 2 as they are at 1 distance from 5.
Now: 6 k liye teeno direction call hongi, 3 k liye, 2 k liye, and so on. (this is moving radially outwards).

// Striver solution (All BFS) // One BFS to mark the parent nodes, other BFS to move radially outwards.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track){  // isko bfs ya dfs kaise bhi create kar skte 
        queue<TreeNode *> queue;
        queue.push(root);
        while(!queue.empty()){
            TreeNode *current = queue.front();
            queue.pop();
            if(current->left){
                parent_track[current->left]= current;
                queue.push(current->left);
            }
            if(current->right){
                parent_track[current->right]=current;
                queue.push(current->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *, TreeNode *> parent_track;
        markParents(root, parent_track);                               // I call this function and my parent map is ready
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode *> queue;
        queue.push(target);                                            // Initially we start from the target, as from there we have to move radially outwards, so we puch it into the queue.
        visited[target] = true;
        int curr_level=0;
        while(!queue.empty()){
            int size =  queue.size();
            if(curr_level++ == k) break;                              // breakout if we have moved k steps
            for(int i=0; i<size; i++){
                TreeNode *current = queue.front(); queue.pop();
                if(current->left && !visited[current->left]){         // radially left
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]){       // radially right
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]){    // radially parent
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> result;
        while(!queue.empty()){                                         // figured out all the nodes at a distance k
            TreeNode *current = queue.front(); queue.pop();
            result.push_back(current->val);
        }
        return result;
    }
};


// Other Solution (All DFS)
1. Using recursion to find all of the son=>parent pair into a map.
2. Using dfs to find K distance node, visited nodes will be recorded

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root) {
            return {};
        }
        findParent(root);
        dfs(target, k);
        return ans;
    }
private:
    std::vector<int> ans;   
    std::unordered_map<int, TreeNode*> parent; // son(n->val) => parent.  
    std::unordered_set<int> visited;           // Record visited node, store just int val(unique)(given in question). So, we can also use a set instead of a map

    void findParent(TreeNode* node){
        if (!node) {
            return;
        }
        if (node->left) {
            parent[node->left->val] = node;
            findParent(node->left);
        }
        if (node->right) {
            parent[node->right->val] = node;
            findParent(node->right);
        }
    }
    
    void dfs(TreeNode* node, int K) {
        if (!node || visited.find(node->val) != visited.end()) {
            return;
        }
        visited.insert(node->val);       // mark as visited
        if (K == 0) {
            ans.push_back(node->val);
            return;
        }
        dfs(node->left, K - 1);
        dfs(node->right, K - 1);
        dfs(parent[node->val], K - 1);
    }
};

// This made entire graph both directions (extra)
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/solutions/1199584/c-build-graph-and-bfs-commented/
