// https://www.spoj.com/problems/BUGLIFE/

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[2001];
int vis[2001], col[2001];

bool dfs(int node, int c){
    vis[node] = 1;
    col[node] = c;

    for(int child: adj[node]){
        if(vis[child]==0){
            bool res = dfs(child, c^1);
            if(res == false)
                return false;
        }
        else if(col[node] == col[child])
            return false;
    }
    return true;
}

int main(){
    int t,n,m,u,v;
    cin>>t;
    for(int tc=1; tc<=t; tc++){          // we didn't used while loop coz we have to print scenario no for each test case.
        cin>>n>>m;

        for(int i=1; i< n; i++) adj[i].clear(), vis[i]=0; // since we have multiple test cases(graphs) we need to clear the adjacency list & the visited array for next graph as it will contain past info

        for(int i=1; i<=m; i++)
            cin>>u>>v, adj[u].push_back(v), adj[v].push_back(u);

        bool flag = true;

        for(int i=1; i<=n; i++){
            if(vis[i]==0){
                flag = dfs(i, 0);
            }
        }
        cout<<"Scenario #"<<tc<<":"<<endl;

        if(flag==false)
            cout<<"Suspicios bugs found!"<<endl;
        else
            cout<<"No suspicios bugs found!"<<endl;
    }
    return 0;
}

