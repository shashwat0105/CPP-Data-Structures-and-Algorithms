https://leetcode.com/problems/is-graph-bipartite/

BFS:

// Color scheme.
// -1 -> not colored
// 1  -> colored with a color say blue
// 0  -> colored with a another color say red

class Solution {
public:
    bool bipartiteBfs(int src, vector<vector<int>>& adj, int color[]){ // this func is bfs in component
    queue<int>q;                                 // queue data structure
    q.push(src);                                 // pushed the starting node
    color[src] = 1;                              // initially colored with one
    while(!q.empty()){                           // bfs traversal - traversing in the queue till it is not empty
        int node = q.front();
        q.pop();

        for(auto it : adj[node]){                // check for its adjacent node
            if(color[it] == -1){                 // not been colored yet  
                color[it] = 1-color[node];       // coloring with opposite color to the adjacent node, 1-1=0, 1-1=0
                q.push(it);                      // once it is colored I push it in my queue data structure
            }
            else if(color[it] == color[node]){   // already been colored and if the adjacent node has same color as I have, hence it is not bipartite
                return false;                    
            }
        }
    }
    return true;                                 // completed the entire bfs traversal, queue became empty, successfully able to color with 2 different colors
}
    
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    int color[n];
    memset(color, -1, sizeof(color));            // color array of size n and initialised by -1
    for(int i = 0; i < n; i++){                  // iterating for all the nodes
        if(color[i] == -1){                      // -1 means the node has not been visited yet
            if(!bipartiteBfs(i, graph, color)){  // graph cannot be bipartite so return false
                return false;                    // if any of the component is not bipartite the entire graph is not bipartite
            }
        }
    }
    return true;
    }
};


// Using Union Find
// That we are checking the node that parent, and initial node parent are the same.

class Solution {
public:
    vector<int> parent;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        parent.resize(graph.size());
        // make
        for(int i = 0; i<n; ++i) parent[i] = i;
        
        for(int i = 0; i<n; ++i){
            vector<int> nodes = graph[i];
            for(auto node: nodes){
                if(find(i) == find(node)) return false;
                connectUnion(node, nodes[0]);
            }
        }
        return true;
    }
    
    int find(int point){
        if(parent[point]==point) return point;
        parent[point] = find(parent[point]);
        return parent[point];
    }
    
    void connectUnion(int x, int y){
        int parentX = find(x);
        int parentY = find(y);
        
        if(parentX != parentY) parent[parentX] = parentY;
    }
    
};
