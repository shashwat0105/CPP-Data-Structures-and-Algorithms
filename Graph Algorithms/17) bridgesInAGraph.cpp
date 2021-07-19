// Those edges are called bride in a graph on whose removal the graph is broken into two or more number of components.

// We will use two different arrays 
// tin[]  // time for insertion(tin)
// low[]  // lowest time of insertion

// Condition for an edge to be a bridge : low[it] < tin[node]

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, 
         int &timer, vector<int> adj[]){
     
     vis[node] = 1;                                      // on visiting we mark it as 1
     tin[node] = low[node] = timer++;                    // every time a node is visited timer is incremented
     for(auto it = adj[node]){                           // traverse for all its adjacent nodes
         if(it == parent) continue;                      // if its a parent I dont do a dfs call, coz if its a parent it means u are going backward and u never went back

         if(!vis[it]){
             dfs(it, node, vis, tin, low, timer, adj);
             low[node] = min(low[node], low[it]);        //  It takes the adjacent lowest time, as that adjacent has been visited previously.. 
             if(low[it] > tin[node]){
                 cout<<node<<" "<<it<<endl;
             }
         }
         else{
             low[node] = min(low[node], tin[it]);
         }
     }
}

int main(){
    int n, m;
    cin >> n >> m;               // no of nodes & edges as input
    vector<int> adj[n];
    for(int i = 0; i <m; i++){   // graph input in adjacency list 
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> tin(n, -1);
    vector<int> low(n, -1);
    vector<int> vis(n, 0);
    int timer = 0;               // initial timer = 0
    for(int i = 0; i <n; i++){   // if there are multiple componenets this is how we write dfs  
        int(!vis[i]){
            dfs(i, -1, vis, tin, low, timer, adj);   // dfs call for every node i
        } 
    }

    return 0;
}





