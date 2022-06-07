// https://www.spoj.com/problems/SUBMERGE/

// We have to find number of articulation points.

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10001];
int vis[10001], in[10001], low[10001];
set<int>AP;                                              // set of articulation points
int timer;

void dfs(int node, int par){
    vis[node]=1;

    in[node]=low[node]=timer++;
    int child_cnt=0;                                    // to count the number of subtrees root at 'node' (this is used to check whether the root is articulation point or not)

    for(int child: adj[node]){
        if(child==par) continue;

        if(vis[child]==1){                              // this is a backedge
            low[node]=min(low[node], in[child]);
        }
        else{                                           // is a forward edge
            dfs(child,node);
            child_cnt++;
            low[node]=min(low[node],low[child]);        // minimise the low time of current node by low time of its child

            if(in[node]<=low[child] && par!=-1){        // whether the current node is articulation point wrt current child & the current node should not be root
                AP.insert(node);
            }
        }
    }
    if(par==-1 && child_cnt>1){                         // for root node to be articulation point
        AP.insert(node);
    }
}


int main(){
    int n,m,u,v;
    while(1){
        cin>>n>>m;
        if(n==0 && m==0)
            break;

        for(int i=1;i<=n;i++){
            adj[i].clear();
            vis[i]=0; 
            AP.clear();                                 // clearing the set data structure
            timer = 1;                                  // resetting the timer  
        } 
        while(m--){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=1;i<=n;i++){
            if(vis[i]==0){                            // this connected component has not been visited in which the ith node lies
                dfs(i,-1);                            // since this node will be the root, -1 will be its parent
            }
        }

        cout<<AP.size()<<endl; 
    }

    return 0;
}


//*********************
// in bridge algo it is essential that low[child] < in[node] as it guarantee that child will remain connected despite removing this edge .....
// but in articulation algo both ends of bridge can be articulation point and hence the equality to ensure that we take both the child and node into account ie use in[node] <= low[child] 
