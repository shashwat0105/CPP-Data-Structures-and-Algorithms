// Cycle Detection Template using coloring method

bool detectCycle_util(vector<vector<int>> &adj, vector<int> &vis, int node){
    if(vis[node] == 1) return true;
    if(vis[node] == 2) return false;
    
    vis[node] = 1;  // mark current as visited
    for(auto child: adj[node]){
        if(detectCycle_util(adj, vis, child)) return true;
    }
    vis[node] = 2;  // mark node as processed
    return false;
}

bool detectCycle(vector<vector<int>> &adj, int n){
    vector<int> vis(n, 0);
    for(int i=0; i<n; ++i){
        if(vis[i]==0){
            if(detectCycle_util(adj, vis, i)) // there can be multiple components
                return true;
        }
    }
    return false;
}

// Cycle Detection:
Undirected:
We use a visited array and parent node.
Directed
We use 2 arrays: Visited array and inRecursion Array(ie the node is in current recursion call stack).

// Kahns algo: (Topo sort using BFS) // Only possible for DAG
We insert the nodes with indegree 0 in our queue first.


DSU Template:
https://ide.geeksforgeeks.org/392f3f85-cb79-4631-9da2-3dd78e775873

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

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

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
