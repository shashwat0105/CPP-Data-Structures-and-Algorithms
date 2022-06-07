// Kosajaru Algorithm: Helps us to find all the strongly connected components(SCC) in a directed graph.
// In undirected graph there is no notion of SCC but simply connected components.

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
    int n, m;                             // taking directed graph input
    cin >> n >> m;
    vector<int> adj[n];
    for(int i = 0; i <m; i++){
        int u, v;
        cin>> u >> v;
        adj[u].push_back(v);
    }

    // step 1
    stack<int> st;                        // toposort
    vector<int> vis(n, 0);
    for(int i=0;i<n;i++){                 // insert all the nodes in oreder of definition time in toposort
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

//******************************************************************************************************************

// Problem: Given a directed graph
// (i) Find no of SCC
// (ii) Print the vertices of each connected component.

// Transpose Graph
// In a directed graph, transpose can be formed by inverting the edge direction & vertices remaining the same.

// Kosaraju's algo uses 2 DFS & in the 2nd DFS it runs on transpose graph
// Transpose graph has same no of SCC as the original graph

// CONDENSATION GRAPH
// A graph made with SCC of original graph
// Each SCC of original graph acts as a vertex in Condensation Graph
// & there is a edge from one vertex to other & its direction depending on edge direction in original graph
// Condensation graph does not contain any cycle.
// If there is an edge a -> b
// Then     Out time of a > Out time of b

// Here the condensation graph is a DAG
// A Directed Acyclic Graph (DAG) has at least 1 node with in-degree 0
// Proof by contradiction: https://math.stackexchange.com/questions/3232341/prove-that-a-directed-graph-with-no-cycles-has-at-least-one-node-of-indegree-zer
// If we run dfs on the component having 0 in degree then only the nodes of that strongly connected component will get traversed.

// Transpose of this graph will have out-degree 0

// We will sort the nodes in increasing order of out time & call DFS accordingly.

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];         // adjacency list for graph
vector<int> trans[1001];       // adjacency list for transpose graph

vector<int> order;
vector<int> SCC;               // a list to print all the strongly connected components

int vis[1001];

void dfs(int node){
    vis[node] = 1;

    for(int child: adj[node]){
        if(vis[child] == 0){
            dfs(child);
        }
    }

    order.push_back(node);       // to store the nodes according to the out times
}

void dfs1(int node){
    vis[node] = 1;

    for(int child : trans[node]){   // we use the transpose graph
        if(vis[child] == 0){
            dfs1(child);
        }
    }
    SCC.push_back(node);         // this current node is part of the SCC
}

int main(){
    int n,m,a,b,t;
    cin>>t;
    while(t--){
        cin>>n>>m;

        // clearing the input from previous test case.
        for(int i=1; i<=n; i++){
            adj[i].clear();
            trans[i].clear();
            order.clear();
            vis[i] = 0;
        }

        // taking input of the original and transpose graph
        for(int i=1; i<=m; i++){
            cin>>a>>b;
            adj[a].push_back(b);
            trans[b].push_back(a);
        }

        // first normal dfs to find the order for next dfs
        for(int i=1; i <= n; i++){
            if(vis[i]==0) dfs(i); 
        }

        for(int i=1; i <= n; i++){
             vis[i]=0;
        }

        for(int i=1; i<=n; i++){
            if(vis[order[n-i]]==0){
                SCC.clear();
                dfs1(order[n-i]);

                cout<<"dfs1() called from "<<order[n-i]<<" and printing SCC"<<endl;
                for(int node: SCC){
                    cout<<node<<" ";
                    cout<<endl;
                }
            }
        }
    }
    return 0;
}
