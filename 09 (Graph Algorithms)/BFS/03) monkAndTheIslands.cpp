// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/

// Sample Test Cases:
//   1---2---3                        1---2----3
//                                         \  /
//                                           4
// Shortest distance bw 1 and 3 is 2 
// Shortest distance bw 1 and 4 is 2

#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int vis[100001];
int dist[100001];

void bfs(int src){
    
    queue<int>q;                             // create a queue
    q.push(src);                             // insert the source node
    vis[src]=1;                              // mark the source node to be visited
    dist[src]=0;                             // and set the distance of source node 0
  
    while(!q.empty()){                       // run the while loop till the loop is not empty 
        int current = q.front();             // we take the front element of the queue as current element
        q.pop();

        for(auto it: adj[current]){          // we traverse the adjacency list of current node
            if(vis[it]==0){
                q.push(it);                  // if it is not visited we insert it into the queue
                dist[it] = dist[current]+1;  // and set its distance as distance of current node + 1
                vis[it]=1;                   // and mark it as visited
            }
        }
    }

}

int main(){
    int t,n,m,u,v;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1; i<=n; i++) vis[i]=0, adj[i].clear();  

        for(int i=1; i<=m; i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bfs(1);

        cout<<dist[n]<<endl;
    }
}