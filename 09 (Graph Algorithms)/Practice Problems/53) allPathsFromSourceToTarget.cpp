https://leetcode.com/problems/all-paths-from-source-to-target/

// Run DFS
// Make a path vector, keep inserting until we get our target.
// Then backtrack to find other paths.

https://youtu.be/X6b02KyeyLU

// Decent ques

class Solution {
public:
    void dfs(int curr, vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int> &path){
        path.push_back(curr);
        
        if(curr == graph.size()-1){   // we reached our target node
            ans.push_back(path);
        }
        else{                         // else we call dfs on all its child
            for(auto child: graph[curr]){
                dfs(child, graph, ans, path);
            }
        }
        path.pop_back();              // backtrack 
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // vector<int> vis(n, 0); // Directed graph mein visited ka use nahi hota
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, graph, ans, path);
        return ans;
    }
};
