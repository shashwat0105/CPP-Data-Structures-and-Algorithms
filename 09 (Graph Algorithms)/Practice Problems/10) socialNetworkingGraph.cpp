// This problem is removed from hackerearth now.
// https://youtu.be/kppa3JOAj6A

// 1---2---3       
//     |   |
//     5---4

// Starting node   Distance
// 5 1                       // How many nodes are there from starting node 5 at a distance of 1
// 2 2                       // How many nodes are there from starting node 2 at a distance of 2

// 2
// 1

// We can stop BFS after our destination comes.

// Level array to indicate how many elements are there at this level from the current node

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000001];
int vis[1000001];
int level[1000001];                        // level[i] will tell us how many element are at distance i 
int dist[1000001];


void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src]=1;
    dist[src]=0;

    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(int child: adj[curr]){
            if(vis[child] == 0){
                dist[child]=dist[curr]+1;
                q.push(child);
                vis[child]=1;
                level[dist[child]]++;      // at this distance there is a node so we increment the count.
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);

    int n,m,u,v,src,d, q;                 // src is source node, d is distance, we are given q queries for the graph which we will input
    
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin>>q;
    while(q--){
        cin>>src>>d;
        for(int i=0;i<=n;i++){            // before making dfs call imp to clear the level array, start from 0 coz ques has 0 based system for no of nodes
            level[i]=0, vis[i]=0;
        }

        bfs(src);

        cout<<level[d]<<endl;
    }
    return 0;
}

