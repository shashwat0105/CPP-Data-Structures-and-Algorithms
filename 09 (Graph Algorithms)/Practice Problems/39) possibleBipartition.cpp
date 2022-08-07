https://leetcode.com/problems/possible-bipartition/

// Method 1:
// Using 2 maps or sets and using conditional statements, whether this exists in this map or not.

// Method 2:
// Bipartite Graph

// Note: Disjoint set means the two sets won't be having any common element between them and independent set means there won't be any direct edge between the elements of the same set. 

// In bipartite graph you can have only even edge length cycle.

// The edge can also be assumed to be undirected. (coz we just want to separate them)

// We can use bipartite BFS or DFS

// Graph can be multi component.


class Solution {
public:
    bool checkBipartite(vector<vector<int>> &adj, int n, int node, vector<int> &color){
        queue<int> q;
        q.push(node);
        color[node] = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int child: adj[curr]){
                if(color[child]==color[curr]) return false;
                if(color[child]==-1){  // unvisited node
                    color[child] = 1 - color[curr];
                    q.push(child);
                } 
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // graph is not made so we will make the graph
        vector<vector<int>> adj(n+1);
        for(int i=0; i<dislikes.size(); ++i){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);  // making it undirected

        }
        vector<int> color(n+1, -1);
        for(int i=1; i<=n; ++i){  // node values are from 1 to n
            if(color[i]==-1){     // if the current node is not colored then we will call BFS or DFS
                if(!checkBipartite(adj, n, i, color)) return false;    // V IMP, agar false return kare toh false return kar skte hai, but agar true return kare toh true return nahi kar skte, kya pata aage false return kar de qki.
            }
        }
        return true;
    }
};
