// https://codeforces.com/problemset/problem/118/E


// CRUX:
// If the graph has a(one or more) bridge then it is not possible to find a unidirectional solution to the problem.
// Coz then it will not be a strongly connected graph ie we can reach every node from every other node

// DFS Tree method for finding directions so that the graph is strongly connected.

// We can orient all the forward edges from parent to child
// We would orient all the back edges from child to ancestor

// The graph must not have any bridges and then we have to print the orientation


#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int in[100001], low[100001], vis[100001], timer;
bool hasBridge;                                     // globally initialised to false
vector<pair<int, int>> edgeList;

void dfs(int node, int par){
    vis[node] = 1;
    in[node] = low[node] = timer++;

    for(int child: adj[node]){
        if(child == par) continue;

        if(vis[child]){
           low[node] = min(low[node], in[child]); 

            // orient it from current node to ancestor(here child) coz a back edge
            if(in[node]>in[child]){                 // to check if the current node is descendant or not
                edgeList.push_back({node,child});
            }
        }
        
        else{                                       // we rechead a forward edge
            dfs(child, node);
            if(low[child]>in[node]){                // found a bridge
                hasBridge = true;
                return;
            }

            // this edge is not a bridge but a forward edge
            // node -> child
            edgeList.push_back({node,child});  // so that the orientation will be from node to child
            low[node] = min(low[node], low[child]);
        }
    }
}

int main(){
    int n, m, u, v;
    cin>>n>>m;

    while(m--){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);                                     // passing -1 as parent of root
    
    if(hasBridge){
        cout<<0;
    }
    else{
        for(pair<int,int>e: edgeList){
            cout<<e.first<<" "<<e.second<<endl;
        }
    }

    return 0;
}




