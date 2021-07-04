// 1---2---4       3---5
//     |   |
//     7---6

// above are 2 components of a graph
// Adjacency List for the given graph
// 1 -> 2
// 2 -> 1 4 7
// 3 -> 5
// 4 -> 2 6
// 5 -> 3
// 6 -> 4 7
// 7 -> 2 6

// DFS Traversal -> 1 2 4 6 7 3 5 or 1 2 7 6 4 3 5

// In recursive call complete left side is called first then moving to right and so on, which is nothing but going in depth it DFS

class Solution{
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs){
        storeDfs.push_back(node);            // we push a node
        vis[node] = 1;                       // now the node is visited so we mark it as 1
        for(auto it: adj[node]){             // for every node we check its adjacency node if
            if(!vis[it]){                    // if it is not visited then we call the dfs function again
                dfs(it, vis, adj, storeDfs); // using recursion cos recursive calls are dfs
            }
        }
    }
public:
    vector<int>dfsOfGraph(int V, vector<int>adj[]){  // no of node = V, edges and nodes stored in adjacency list
        vector<int>storeDfs;                         // store our dfs result
        vector<int>vis(V+1, 0);                      // size of the array V+1 and initialised to all 0
        for(int i = 1; i<=V; i++){                   // we go to every node and see 
            if(!vis[i]){                             // if the node is not visited ie is not 0
                dfs(i, vis, adj, storeDfs);          // we call the dfs recursive function
            }
        }

        return storeDfs;
    }
};

// DO MORE RESEARCH ON THIS CODE 


