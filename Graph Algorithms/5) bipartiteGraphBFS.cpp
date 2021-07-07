// A graph that can be colored exactly using 2 colors.
// Such that none adjacent nodes can have same color.

// Let's color by B = Blue and G = Green
//           G---B
//          /     \
// B---G---B       G---B---G       // even(here 6) no of elements in the cycle
//          \     /                // Yes, bipartite
//           G---B


//        B
//      /   \                      // odd(here 5) no of elements in the cycle
// B---G     G---B---G             // Not bipartite
//     |     |                     // Here, G G came adjacent
//     B-----G


// B---G   B---G                  // Not cyclic
//     |   |                      // Yes, Bipartite
//     B---G

// Hence, If a graph has odd length cycle it is not bipartite, else bipartite

// Code Building

//       3---4
//      /    | 
// 1---2     |
//      \    |
//       8---5---6---7

// We take two colors 0 and 1
// In code of bfs we use queue, in dfs we make recursive calls

#include <bits/stdc++.h>
using namespace std;

bool bipartiteBfs(int src, vector<int>adj[], int color[]){ // this func is bfs in component
    queue<int>q;                                 // queue data structure
    q.push(src);                                 // pushed the starting node
    color[src] = 1;                              // initially colored with one
    while(!q.empty()){                           // bfs traversal - traversing in the queue till it is not empty
        int node = q.front();
        q.pop();

        for(auto it = adj[node]){                // check for its adjacent node
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

bool checkBipartite(vector<int>adj[], int n){
    int color[n];
    memset(color, -1, sizeof(color));          // color array of size n and initialised by -1
    for(int i = 0; i < n; i++){                // iterating for all the nodes
        if(color[i] == -1){                    // -1 means the node has not been visited yet
            if(!bipartiteBfs(i, adj, color)){  // graph cannot be bipartite so return false
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


