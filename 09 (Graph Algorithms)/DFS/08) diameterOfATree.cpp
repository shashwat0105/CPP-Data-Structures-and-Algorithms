// Longest path between any of the two nodes in a tree.

// Novice Approach

// Run DFS total N times ie for every node
// In each iteration set ith node as root and run DFS 
// And find the maximum distance and update it

// TC = O(n+e)*n = O(n)


// Better approach

// We can find diameter in just 2 DFS calls
// Take any arbitrary node and do DFS, find the farthest node and name it x
// Do DFS of x(now will be root) , the farthest distance from this node will be the diameter


// Problem Link
// https://www.spoj.com/problems/PT07Z/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10001];
int vis[10001];

int maxDist, maxNode;     // the max distance we have found and the node which is farthest

void dfs(int node, int dist){
    vis[node] = 1;
    if(dist>maxDist){
        maxDist = dist;   // we update the max distance
        maxNode = node;   // we update the farthest node
    }

    for(int child: adj[node]){
        if(vis[child] == 0){
            dfs(child, dist+1);  
        }
    }
}

int main(){
    int n, u,v;           // since a tree no of edges = n-1
    cin>>n;
 
    for(int i=1; i<=(n-1); i++){
        cin>>u>>v, adj[u].push_back(v), adj[v].push_back(u);
    }

    maxDist = -1;
    dfs(1, 0);            // since there will be an arbitrary node as 1, and pass its distance as 0

    for(int i=1; i<=n; i++) vis[i] = 0;  // before doing second dfs clear the visiting array (since only 1 tree, adjacency list won't be cleared)
    maxDist = -1;         // clearing the value of max distance before calling the second dfs
    dfs(maxNode, 0);      // calling the second dfs from maxNode and since its root node now, its distance will be zero (root to root)

    cout<<maxDist<<endl;

    return 0;
}
