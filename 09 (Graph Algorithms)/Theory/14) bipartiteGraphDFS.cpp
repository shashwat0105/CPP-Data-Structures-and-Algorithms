DFS:

      3---4
     /     \
1---2       5---7---8
     \     /
        6

// dfs(1) -> dfs(2) -> dfs(3) -> dfs(4) -> dfs(5) -> dfs(7) -> dfs(8) (goes back to 7 and 5) -> dfs(6) {sees that 5 and 2 are adjacent nodes out which 5 is opposite color but 2 is of same color}
//   1         0          1        0          1        0         1                                 0   returns false


https://practice.geeksforgeeks.org/problems/bipartite-graph/1

bool checkBipartiteDFS(int curr, vector<int>adj[], vector<int> &color, int currColor){
    color[curr] = currColor;                                      // color the current node

    // ab jaate hai adjancent nodes pe
    for(int &v: adj[curr]){
        if(color[v]==-1){                                         // if the adjacent node has not been colored
            // int colorOfV = 1 - color[curr];                    // color it with exact opposite color // 1-0 = 1 // 1-1 = 0
            if(!checkBipartiteDFS(v, adj, color, 1-color[curr]))  // recursively calling dfs, boolean func so will return true or false // !color[u] bhi pass kr skte the
                return false;                                     // any of the call returns false, then it is completely false
        }
        else if(color[v]==color[curr]) return false;              // adjacent node has been found to be colored, and the adjacent node has same color as what I have currently
    }
    return true;
}

bool isBipartite(int V, vector<int>adj[]){        // same block of code as checkbipartite of bfs
    vector<int> color(V, -1);                     // color array of size V and initialised by -1
    
    // red = 1, green = 0
    for(int i = 0; i < V; i++){                   // iterating for all the nodes
        if(color[i] == -1){                       // -1 means the node has not been visited yet
            if(!checkBipartiteDFS(i, adj, color, 1)){  // Anywhere it becomes false // start with color 1
                return false;                     // if any of the component is not bipartite the entire graph is not bipartite
            }
        }
    }
    return true;
}

