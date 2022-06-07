// Depth-first search can be conveniently implemented using recursion.
// Hence used to in applications more in compare to BFS
// https://youtu.be/rEa4014IxR8 

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

// In recursive call complete left side is called first then moving to right and so on, which is nothing but going in depth ie DFS

class Solution{
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &res){     // takes the argument of current node not total number of nodes.
        res.push_back(node);                 // we push the node
        vis[node] = 1;                       // now the node is visited so we mark it as 1
        for(auto it: adj[node]){             // for every node we check its adjacency node if
            if(!vis[it]){                    // if it is not visited then we call the dfs function again
                dfs(it, vis, adj, res);      // using recursion cos recursive calls are dfs
            }
        }
    }
public:
    vector<int>dfsOfGraph(int V, vector<int>adj[]){  // no of node = V, edges and nodes stored in adjacency list
        vector<int>vis(V+1, 0);                      // size of the array V+1 and initialised to all 0
        vector<int>res;                              // store our dfs result
        for(int i = 1; i<=V; i++){                   // we go to every node and see (coz there could be multiple components)     
            if(!vis[i]){                             // if the node is not visited ie is not 0
                dfs(i, vis, adj, res);               // we call the dfs recursive function
            }
        }

        return res;
    }
};


// We use two things visted array & adjacency list,,, the compiler here creates a stack which keep track of executing the function

void dfs(int v){                          // takes the argument of current node
    vis[v] = 1;                           // as we reach node we mark it as visited '1'
    cout<<v<<"->";                        // printing the node for dfs order  
    for(int i=0; i<adj[v].size(); i++){   // move in the adjacency list of 
        int child = adj[v][i];            // child is the node connected to current node
        if(vis[child]==0)                 // we check if it is visited or not
            dfs(child);                   // if it is not visited we make recursive call to that child
    }
}

// or (We use this)

void dfs(int v){                          // takes the argument of current node
    vis[v] = 1;                           // as we reach node we mark it as visited '1'
    cout<<v<<"->";                        // printing the node for dfs order  
    for(int child: adj[v]){               // move in the adjacency list of ,,, using for each loop
        if(vis[child]==0)                 // we check if it is visited or not
            dfs(child);                   // if it is not visited we make recursive call to that child
    }
}

