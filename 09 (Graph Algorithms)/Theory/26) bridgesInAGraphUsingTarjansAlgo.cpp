// Those edges are called bride in a graph on whose removal the graph is broken into two or more number of components.

https://youtu.be/qrAub5z8FeA (Striver)
https://takeuforward.org/graph/bridges-in-graph-using-tarjans-algorithm-of-time-in-and-low-time-g-55/

// We will use two different arrays 
// tin[]  // time for insertion(tin)  // The first time you are reaching a node during dfs
// low[]  // lowest time of insertion // Will look at all the adjacent nodes and see which has the lowest value, except the parent.

// Condition for an edge to be a bridge : low[it] < tin[node]
// We detect the bridge while backtracking that whether this can be bridge or not.
// ie in any other path via I can reach this node then this cannot be a bridge.

To print/return all the bridges in the graph.

Direct ques
https://leetcode.com/problems/critical-connections-in-a-network/description/

class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, unordered_map<int, vector<int>> &adj, int tin[], int low[], vector<vector<int>> &bridges){
        vis[node] = 1;
        tin[node] =  low[node] = timer;              // every time a node is visited timer is incremented
        timer++;
        for(auto &it: adj[node]){
            if(it==parent) continue;
            if(vis[it]==0){  // not visited yet
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[it], low[node]);

                // node----it // can be a bridge?     // If the adjacent nodes lowest time is smaller or equal to current node, so it can reach again via some path, so if its greater, it cannot! 
                if(low[it] > tin[node]){              // adjacent(child) nodes ka time jada hai ie it wont be able to reach if disconnected hence it is a bridge. // the child should have some more value(izzat) ie more time to be part of the bridge
                    bridges.push_back({it, node});
                }
            }
            else{                                     // you are coming to a node via visiting it, hence it cannot be bridge
                low[node] = min(low[it], low[node]);  // edge node - child is a back edge, then we minimise the low time of the node(coz a shorted path exists)
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // make graph.
        unordered_map<int, vector<int>> adj;
        for(auto &connection: connections){
            int u = connection[0];
            int v = connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, tin, low, bridges);     // given there is a single component. for multiple use a for loop
        return bridges;
    }
};


******

// THEORY OF EDGES
// We perform a DFS and classify the encountered edges using the following rules:

// If v is not visited:

// Tree Edge - If v is visited after uu then edge (u,v)(u,v) is called a tree edge. In other words, if v is visited for the first time and uu is currently being visited then (u,v)(u,v) is called tree edge. 
// These edges form a DFS tree and hence the name tree edges.

// If v is visited before uu:

// Back edges - If v is an ancestor of uu, then the edge (u,v)(u,v) is a back edge. vv is an ancestor exactly if we already entered v, but not exited it yet. 
// The back edges complete a cycle as there is a path from ancestor v to descendant uu (in the recursion of DFS) and an edge from descendant uu to ancestor v (back edge), thus a cycle is formed. Cycles can be detected using back edges.
// A back edge connects a node to its ancestor which is not its direct parent.
// Hene, a back edge can never be a bridge


// Forward Edges - If v is a descendant of uu, then edge (u,v)(u,v) is a forward edge. In other words, if we already visited and exited v and entry[u]<entry[v]entry[u]<entry[v] then the edge (u,v)(u,v) forms a forward edge.
// A Forward edge may or may not be a bridge.


// Cross Edges - if vv is neither an ancestor or descendant of uu, then edge (u,v)(u,v) is a cross edge. In other words, if we already visited and exited vv and entry[u]>entry[v]entry[u]>entry[v] then (u,v)(u,v) is a cross edge.

// 1--2--3
//    \  /
//     4
// low[4] < in[3] hence edge 3-4 cannot be a bridge, coz there is already a shorter path 2 - 4 and removing 3-4 edge wont split the graph into two


// low is the node(except the parent) having the least in-time(less than in[node]) from which node is reachable, 
// thus carving out an alternate path from source to node.



// Explanation for: low[node] = min(low[node], low[child]);  // minimising the current node
// we update low time of 3 marking that there is a child of 3 by which we can reach 2 and which is node 4. 
// when we backtrack to node 2, he found that low time of 3 is equal to his in time. then 2 will understand there is a back edge of 3's child to reach him. 
// thus node 2 understand 2-3 is not a bridge.
// After checking a forward edge whether it is bridge or not, 
// low[node] = min(low[node], low[child]) , this condition would update the low[node] of the parent only if its child node's low will be smaller than that of parent node .
// It would be true only if child has a backedge to a node that is ancestor to both child and parent , so it is imp to update parent low to this value.
// It would also be true when decendent of child has a backedge to a node that is ancestor to both current node and its parent , as  because of recursion it would keep on updating ....

