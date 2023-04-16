// http://www.i2symbol.com/symbols/arrows   (copied arrow symbols from here)

// DFS is used more than BFS due to convenience of implementation.

// YT resources followed: 1) Striver's Graph
//                        2) Codencode Graph Playlist 

// Two types of graphs
// 1) Undirected  2) Directed

// Directed graphs have arrows in defines in what direction one can move in a path
// Degree:- Is no of edges on a node/vertex
// Path:- In which a node cannot be visited twice.
// Cyclic -> a cycle can be completed
// Acyclic -> a cycle cannot be completed

// Directed acyclic graph(DAG)

// If edges are assigned values, then it becomes a weighted graph.

// Graph Representation In C++
// Input 
// u    v 
// 1    2 (there is an edge between 1 and 2, so on)
// 2    4
// 2    3
// 1    3
// 3    4
// 1    5
// 5    3

// Method 1: Adjacency matrix of size (n+1)*(n+1)
// Initialise all elements to zero, then make 1 for edge bw 1 and 2 so is bw 2 and 1
// adj[u][v] = 1; adj[v][u] = 1;
//   0  1 2 3 4 5 
// 0 0  0 0 0 0 0 
// 1 0  0 1 1 0 1
// 2 0  1 0 1 1 0 
// 3 0  1 1 0 1 1
// 4 0  0 1 1 0 0
// 5 0  1 0 1 0 0

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; // n = no of nodes, m = no of edges
    cin>>n>>m;

    // declaring the adjacent matrix
    int adj[n+1][n+1];

    // taking edges as input
    for(int i=0; i<m; i++){
        int u, v;                 // if there has been weight then: int u, v, wt 
        cin>>u>>v;                // cin>>u>>v>>wt
        adj[u][v] = 1;            // adj[u][v] = wt;
        adj[v][u] = 1;            // adj[v][u] = wt;
    }

    // Finding that there is an edge between two nodes and what is its weight happens in O(1) time ; Advantage than method 2
    if(adj[i][j]==1) return true;  // ie connected
    return adj[i][j];              // fetch me the weight

    return 0;
}
// Space = n*n
// Disadvantage of this method is that cannot be used for larger n like 10^5 size 2D array (will take approx 40GB space, while CF, SPOJ allows only 1.5GB )



// Method 2: Adjacency list

// vector<int> adj[6]             // adjacency list can be stored using vector in C++ (Each index is a vector itself so you can add elements to it ) & array list in JAVA; This creates 6 adjacency lists ie 6 vectors
// vector<vector<int>> adj;       // This also can be used.
Or better using unordered_map (I will use this from now on)
// 0 
// 1 (2, 5, 3)                    // these denotes the edge 1-2, 1-5, 1-3 and so on
// 2 (1, 3, 4)
// 3 (1, 5, 2, 4)
// 4 (2, 3)
// 5 (1, 3)

// Space Complexity = O(N + 2E)   // n = no of nodes, E = no of edges

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;                     // n = no of nodes, m = no of edges
    cin>>n>>m;

    // declaring the adjacent list
    unordered_map<int, vector<int>> adj; // if weights are also given then vector<pair<int, int>>adj[n+1] // first int will store the to edge, second int will store the weight

    // taking edges as input
    for(int i=0; i<m; i++){       // can use while(m--)  loop as well
        int u, v;
        cin>>u>>v;

        // take input of edge say between u and v, In the adjacency list of u insert v and in the adjacency list of v insert u. (coz if edge is 1 to 2 then it is also 2 to 1 in undirected graph)
        adj[u].push_back(v);      // adj[u].push_back({v, wt}); // difference if its a weighted graph
        adj[v].push_back(u);      // we wont write this if the graph is a directed one
    }
    
    // Finding that there is an edge between two nodes and what is its weight happens in O(N) time ; Disadvantage than method 1
    for(int child: adj[i]){              // pair<int, int> child : adj[i]   // in case of weight // or auto
        if(child==j) return connected;   // child.first==j
        child.second                     // will be weight if there is weight
    }   
    return 0;
}



// CONNECTED COMPONENTS IN A GRAPH (One component is connected means from every node you can reach every other node)
// Example of Undirected graph (No strong word is used)

// 1---3            2---9         5---7
//     |                              |
// 6---4                              10
// |
// 8
//  C1                C2            C3    // these are 3 components of 1 graph

// syntax
for(int i=0; i<=10; i++){         // for every node is called coz a graph can have multiple components
    if(!vis[i]){                  // if i is not visited
        dfs(i)
        bfs(i) code
    }
}

// In case of directed graph;
// If there is a path from every node to every other node: then it is called strongly connected component.

// Alogithms
// Aani hi Chahiye
// Dijasktra
// Bellmanford
// Advanced Algos and topics
// Disjoint set union         :  Good and Simple questions bante hai iske
// Minimum Spanning Tree      : Theory wise is important, implementation wise kam puchte hai
// Directed Acyclic Graph (DAG)
// Topological Sort

// DFS
// BFS
// Cycle Detection and Topological Sort
// Graph Algos on 2D Grid 
// Bipartite Graph test
// Bridges and Articulation Point
// Strongly Connected Components(SCC)

