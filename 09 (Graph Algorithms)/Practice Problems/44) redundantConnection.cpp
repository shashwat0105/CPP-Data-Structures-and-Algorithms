https://leetcode.com/problems/redundant-connection/

// Adding a redudant edge to a tree, will make cycle.
// So, we need to find cycle is formed due to which edge.

// We want to output the last input which is causing this.
// So, Maybe DFS won't be helpful here that easily.
// We will use DSU.

// DSU se jis edge(edge[0], edge[1]) ki wajah se cycle ban rahi hai usko return kar dia!!

class Solution {
public:
    int find(int node, vector<int> &parent){
        while(parent[node]!=node) node = parent[node];
        return node;
    }
    
    void connectUnion(int i, int j, vector<int> &parent){
        int iRoot = find(i, parent);
        int jRoot = find(j, parent);
        
        if(iRoot!=jRoot){
            parent[jRoot] = iRoot;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        // make node
        for(int i=1; i<=n; ++i){
            parent[i] = i;
        }
        
        // Loop in all edges 
        for(auto edge: edges){
            if(find(edge[0], parent)==find(edge[1], parent)) return edge;  // dono ka parent same nikla ie loop bana dia
            connectUnion(edge[0], edge[1], parent);
        }
        return {};
    }
};


