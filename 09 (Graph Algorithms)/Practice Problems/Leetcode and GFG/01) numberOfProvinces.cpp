https://leetcode.com/problems/number-of-provinces/

// CRUX: Counting number of connected components.

// Even the node values are from 1-n
// Since we only need to count components, we can run loops of 0 to n-1

https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/BFS_DFS/Number%20of%20Provinces.cpp
// Isne extra nodes bhi adjacency list m add kr di hai but wo call ni hongi coz wo already visited ho jaengi


// My first approach:
class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &vis){
        vis[node] = 1;
        for(auto child: adj[node]){
            if(vis[child]==0){
                dfs(child, adj, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Adjacency matrix is given.
        // Making Adjacency list graph
        int n = isConnected.size();
        unordered_map<int, vector<int>> adj;                 // creating adjacency list graph from matrix
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j); 
                    adj[j].push_back(i);                    // Iski jaroorat ni hai par kar do koi farq ni padega                  
                }
            }
        }
        vector<int> vis(n, 0);
        int cnt = 0;
        for(int i=0; i<n; ++i){
            if(vis[i]==0){
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};


// Space optimized solution without visited array:

class Solution {
public:
    
    void dfs(vector<vector<int>>& M, int i, int j){
        M[i][j]=M[j][i]=0;  
        for(int k=0; k<M.size(); k++)
            if(M[j][k]) dfs(M,j,k);
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(M[i][j]){
                    dfs(M,i,j);
                    ans++;
                }
            }
        }
        return ans;        
    }
};

// Using DSU:

We can count number of ultimate parents that will be our ans

CODE:

// DSU
// copy pasted the class snippet of striver
class DisjointSet {
public: 
    vector<int> rank, parent, size;   // make it under public to access in other functions
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    // void unionByRank(int u, int v) {
    //     int ulp_u = findUPar(u); 
    //     int ulp_v = findUPar(v); 
    //     if(ulp_u == ulp_v) return; 
    //     if(rank[ulp_u] < rank[ulp_v]) {
    //         parent[ulp_u] = ulp_v; 
    //     }
    //     else if(rank[ulp_v] < rank[ulp_u]) {
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
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);       // created a constructor of the same size
        for(int i=0; i<n; ++i){  // traversing in the matrix
            for(int j=0; j<n; ++j){
                if(isConnected[i][j]){
                    ds.unionBySize(i, j);
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<n; ++i){
            if(ds.parent[i]==i) cnt++; // counting unique ultimate parents
        }
        return cnt;
    }
};

