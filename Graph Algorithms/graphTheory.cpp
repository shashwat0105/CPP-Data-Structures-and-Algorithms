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
        int u, v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}

// Space = n*n
// Disadvantage of this method is that cannot be used for larger n like 10^5 size 2D array


// Method 2: Adjacency list



