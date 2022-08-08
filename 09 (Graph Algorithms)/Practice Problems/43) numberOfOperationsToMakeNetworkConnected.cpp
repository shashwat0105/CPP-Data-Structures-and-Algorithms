https://leetcode.com/problems/number-of-operations-to-make-network-connected/

// See Hint: 
As long as there are at least (n - 1) connections, there is definitely a way to connect all computers.
Use DFS to determine the number of isolated computer clusters.
//

class Solution {
public:
    void dfs(int i, vector<vector<int>> &adj, vector<int> &vis){    // adj and vis are passed by reference
        vis[i] = 1;
        for(int it: adj[i]){
            if(vis[it]==0){                                          // Here I made mistake, I have to check vis[child] 
                dfs(it, adj, vis);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) 
            return -1;
        vector<vector<int>> adj(n);
        
        for(auto connection: connections){
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        
        vector<int> vis(n, 0);
        int cnt = 0;
        for(int i=0; i<n; ++i){
            if(vis[i]==0){
                dfs(i, adj, vis);
                cnt++;
            }
        }
        return cnt-1;       // number of connected components - 1 will be the required min number of wires.
    }
};

//
Redundant edge: Removal of an edge so that it doesnot create another component. That edge is a redundant edge

// Refer my other submission, there I have used map instead of adj (same thing)

