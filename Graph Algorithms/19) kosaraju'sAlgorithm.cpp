// Kosajaru Algorithm: Helps us to find all the strongly connected components(SCC) in a directed graph.

// SCC -> Every node is reacheable to every other node in that component.

// 1  →  2  →  4
//  ↖   ↙      ↓
//    3        5 

// Here, (1,2,3) , (4), (5)  are SCC
// (4,5) is not an SCC because 4 can reach 5 but 5 cannot reach 4

// If we do dfs calls from start dfs(1) -> dfs(2)... dfs(5) every node will be visited
// But if we do dfs from end node ie dfs(5) will be only visited, then dfs(4) it will end coz dfs(5) is already visited.

// 3 Steps:
// Step 1: Sort all the nodes in order of finishing time. (Topological Sort Algorithm)
// Step 2: Transpose the graph .
// 1  ←  2  ←  4
//  ↘   ↗      ↑
//    3        5 

// Step 3: Do DFS according to the finishing time.

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[i]){
            dfs(it, st, vis, adj);
        }
    }

    st.push(node);
}

void revDFS(int node, vector<int> &vis, vector<int> transpose[]){
    cout<< node << " ";
    vis[node] = 1;
    for(auto it : transpose[node]){
        if(!vis[i]){
            revDFS(it, vis, transpose);
        }
    }
}

int main(){
    int n, m;                     // taking directed graph input
    cin >> n >> m;
    vector<int> adj[n];
    for(int i = 0; i <m; i++){
        int u, v;
        cin>> u >> v;
        adj[u].push_back(v);
    }

    // step 1
    stack<int> st;                  // toposort
    vector<int> vis(n, 0);
    for(int i=0;i<n;i++){           // insert all the nodes in oreder of definition time in toposort
        if(!vis[i]){
            dfs(i, st, vis, adj);   
        }
    }

    // step 2
    vector<int> transpose[n];
    for(int i = 0; i < n; i++){
        vis[i] = 0;                       // remark the visited as 0, coz above toposort marked it visited
        for(auto it : adj[i]){            // previously we have edge from i to it, now from it to i
            transpose[it].push_back(i);   
        }
    }

    // step 3
    while(!st.empty()){
        int node = st.top();               // go on the nodes according to the finishing time ie top of the stack
        st.pop();
        if(!vis[node]){                    // for unvisited nodes call reverse dfs
            cout << "SCC: ";
            revDFS(node, vis, transpose);  
            cout<< endl;
        }
    }

    return 0;
}

