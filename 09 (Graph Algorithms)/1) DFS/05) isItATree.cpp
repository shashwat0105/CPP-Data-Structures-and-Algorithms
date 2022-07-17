// https://www.spoj.com/problems/PT07Y/

// Conditions of a tree:
// From every node u can reach every other node, if there are two conneceted components then it is not a tree. ie there should be exactly one conneceted component.
// A Tree doesn't contain any cycle. ie edges = n-1 (for a single component graph only)


// An undirected graph is a tree when the following two conditions are true:

//    1. The graph is a connected graph.
//    2. The graph does not have a cycle.

// A directed graph is a tree when the following three conditions are true:

//    1. The graph is a connected graph.
//    2. The graph does not have a cycle.
//    3. Each node except root should have exactly one parent.


// Hence we need to check 2 things: i) single conneceted component ii) no of edges = n-1

#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10001];
int vis[10001];

void dfs(int node)
{
	vis[node] = 1;
	for(int child : adj[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
}

int main(){
    int n,m,u,v;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        cin>>u>>v, adj[u].push_back(v), adj[v].push_back(u); 
    }

    int cc=0;
    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            dfs(i), cc++;
        }
    }

    if(cc == 1 && (m== n-1))
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}

// Take care of for loop i=0 or 1, < or <= , I did a mistake here.

// m == n-1 means not a cycle only with single connected graph ie it has to be a tree
// m != n-1 means can or cannot be a cycle

