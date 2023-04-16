// An articulation point(or Cut Vertex) is a vertex which when removed makes the graph disconnected Or
// more precisely it increases the number of connected components.

https://youtu.be/j1QDfU21iZk  (Striver)

// We will use two different arrays 
// tin[]  // time for insertion(tin)  // The first time you are reaching a node during dfs
// low[]  // lowest time of insertion // minimum of all adjacent nodes apart from parent and visited.(slight different from bridge)


// Formulae which we will use:
// low[it] <= tin[node]  && parent!= -1
// if(child>1 && parent== -1)  // for starting node to be articulation point it has to be multple children // we deal it separtely

https://practice.geeksforgeeks.org/problems/articulation-point-1/1

CODE:

class Solution {
  private:
  void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[], vector<int> &isArticulation){
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    int child = 0;
    for (auto it : adj[node]) {
        if (it == parent) continue;
        if (!vis[it]) {
            dfs(it, node, vis, tin, low, timer, adj, isArticulation);
            low[node] = min(low[node], low[it]);
            if (low[it] >= tin[node] && parent != -1) {  // If u cannot reach somewhere before me and not the first guy
                isArticulation[node] = 1;
            }
            child++;
        }
        else {
            low[node] = min(low[node], tin[it]);  // This time I wont take low[it], I take tin[it]
        }
    }
    if (child > 1 && parent == -1) {
        isArticulation[node] = 1;
    }
    
}
  public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int> tin(n, -1);           // assigned time of insertion as -1
        vector<int> low(n, -1);           // lowest time of insertion as -1
        vector<int> vis(n, 0);            // visited array as 0
        vector<int> isArticulation(n, 0); // it could be printed multiple times so we carry a hash
    
        int timer = 0;
        for (int i = 0; i < n; i++){
            if (!vis[i]){
                dfs(i, -1, vis, tin, low, timer, adj, isArticulation);
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++){
            if (isArticulation[i] == 1)
                ans.push_back(i);
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};


// **************************************************

// Relation b/w Bridges & Articulation point
// An end point of a bridge is actually an articulation point
// Will all the end points be articulation points? Ans: NO 

// So, whatever end point of a bridge having degree >=2 is an articulation point.

// Can Articulation point exist without a bridge? Ans: YES
// Hence, finding bridge algo cannot be used to find articulation point, we have to modify the dfs tree algo.

// & For the root node, if it has more than 1 subtree then is the articulation point.

// Since the same node can be found as articulation point by many subtrees, it is a good idea to use a set. (stores unique values), instead of a count variable and cnt ++

// Readings:
// https://cp-algorithms.com/graph/cutpoints.html
// https://codeforces.com/blog/entry/68138    (EXTREMELY RECOMMENDED)


