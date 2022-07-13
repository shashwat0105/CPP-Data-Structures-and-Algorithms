https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// We will use a hashmap to store the parent of a particular node.
// Keep on moving 1 distance everytime radially outwards and mark it as visited.
// After k steps, nodes inside my queue ds, will be at a distance of k

// Striver solution (All BFS)
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
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track, TreeNode * target){  // isko bfs ya dfs kaise bhi create kar skte 
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
        markParents(root, parent_track, target);                       // I call this function and my parent map is ready(Isme target pass karne ki koi jaroorat nahi hai)
        
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
    // Record visited node, store just int val(unique)(given in question). So, we can also use a set instead of a map
    std::unordered_set<int> visit;

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
        if (!node || visit.find(node->val) != visit.end()) {
            return;
        }
        visit.insert(node->val);
        if (K == 0) {
            ans.push_back(node->val);
            return;
        }
        dfs(node->left, K - 1);
        dfs(node->right, K - 1);
        dfs(parent[node->val], K - 1);
    }
};

