https://leetcode.com/problems/number-of-operations-to-make-network-connected/

// https://www.youtube.com/watch?v=q2xBd-D_1KQ   (MIK)

// See Hint: 
As long as there are at least (n - 1) connections, there is definitely a way to connect all computers.
Use DFS to determine the number of isolated computer clusters.

CODE:

class Solution {
public:
    void dfs(int i, unordered_map<int, vector<int>> &adj, vector<int> &vis){
        vis[i] = 1;
        for(auto it: adj[i]){
            if(vis[it]==0){
                dfs(it, adj, vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        
        unordered_map<int, vector<int>> adj;
        for(auto &connection: connections){
            int u = connection[0];
            int v = connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);  
        int cnt = 0;
        for(int i=0; i<n; ++i){
            if(vis[i]==0){
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt-1;  // if there are n components then n-1 wires will be required to connect them.
    }
};

// In ques it was asked to do using extra edges and also that ans is always possible. So, I didnt count the extra edges.
// Refer below code using DSu for extra edges
Redundant edge: Removal of an edge so that it doesnot create another component. That edge is a redundant edge

Either you can count unique components by number of unique ultimate parents or by decresing the components count by number of times the connection is made.

// Using DSU (actually is of same time complexity but runs faster)
CODE:
//User function Template for C++
class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // void unionByRank(int u, int v) {
    //     int ulp_u = findUPar(u);
    //     int ulp_v = findUPar(v);
    //     if (ulp_u == ulp_v) return;
    //     if (rank[ulp_u] < rank[ulp_v]) {
    //         parent[ulp_u] = ulp_v;
    //     }
    //     else if (rank[ulp_v] < rank[ulp_u]) {
    //         parent[ulp_v] = ulp_u;
    //     }
    //     else {
    //         parent[ulp_v] = ulp_u;
    //         rank[ulp_u]++;
    //     }
    // }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);  // constructor of that class
        int cntExtras = 0;
        int cntC = n;

        // union set ds graph is made:
        for(auto &connection: connections){
            int u = connection[0];
            int v = connection[1];
            if(ds.findUPar(u) == ds.findUPar(v)){ // belong to same component
                cntExtras++;
            }
            else{
                ds.unionBySize(u, v);
                cntC--;
            }
        }
        // counting unique ultimate parents
        // int cntC = 0;
        // for(int i=0; i<n; ++i){
        //     if(ds.parent[i]==i) cntC++;
        // }
        int ans = cntC - 1;
        if(cntExtras>=ans) return ans;
        return -1;
    }
};
