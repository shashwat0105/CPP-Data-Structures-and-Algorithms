      3---4
     /     \
1---2       5---7---8
     \     /
        6

// dfs(1) -> dfs(2) -> dfs(3) -> dfs(4) -> dfs(5) -> dfs(7) -> dfs(8) (goes back to 7 and 5) -> dfs(6) {sees that 5 and 2 are adjacent nodes out which 5 is opposite color but 2 is of same color}
//   1         0          1        0          1        0         1                                 0   returns false


#include <bits/stdc++.h>
using namespace std;

bool bipartiteDfs(int node, vector<int>adj[], int color[]){

    if(color[node] == -1) color[node] = 1;                   // first time u are calling a node and -1 means its not colored, then color it with 1

    for(auto it : adj[node]){                                // traversing for all its adjacent nodes
        if(color[it] == -1){                                 // if the adjacent node has not been colored
            color[it] = 1 - color[node];                     // color it with exact opposite color
            if(!bipartiteDfs(it, adf, color)){               // recursively calling dfs, boolean func so will return true or false  
                return false;                                // any of the call returns false, then it is completely false
            }
        }
        else if(color[it] == color[node]) return false;      // adjacent node has been found to be colored, and the adjacent node has same color as what I have currently
    }
    return true;
}

bool checkBipartite(vector<int>adj[], int n){  // same block of code as checkbipartite of bfs
    int color[n];
    memset(color, -1, sizeof(color));          // color array of size n and initialised by -1
    for(int i = 0; i < n; i++){                // iterating for all the nodes
        if(color[i] == -1){                    // -1 means the node has not been visited yet
            if(!bipartiteDfs(i, adj, color)){  // graph cannot be bipartite so return false
                return false;                  // if any of the component is not bipartite the entire graph is not bipartite
            }
        }
    }
    return true;
}

int main(){
    int n, m;                   // n = no of nodes, m = number of edges
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;              // taking the undirected graph as input
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(checkBipartite(adj, n)){ // calling the checkBipartite function to check if the graph is bipartite or not, passing the no of nodes & adjacency list
        cout<<"yes";    
    }
    else
        cout<<"no";
    return 0;
}




