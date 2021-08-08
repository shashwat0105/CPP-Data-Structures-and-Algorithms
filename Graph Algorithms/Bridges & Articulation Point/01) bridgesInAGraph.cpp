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
    cin >> n >> m;                                       // no of nodes & edges as input
    vector<int> adj[n];
    for(int i = 0; i <m; i++){                           // graph input in adjacency list 
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> tin(n, -1);
    vector<int> low(n, -1);
    vector<int> vis(n, 0);
    int timer = 0;                                       // initial timer = 0
    for(int i = 0; i <n; i++){                           // if there are multiple componenets this is how we write dfs  
        int(!vis[i]){
            dfs(i, -1, vis, tin, low, timer, adj);       // dfs call for every node i
        } 
    }

    return 0;
}

// THEORY OF EDGES
// We perform a DFS and classify the encountered edges using the following rules:

// If v is not visited:

// Tree Edge - If v is visited after uu then edge (u,v)(u,v) is called a tree edge. In other words, if v is visited for the first time and uu is currently being visited then (u,v)(u,v) is called tree edge. 
// These edges form a DFS tree and hence the name tree edges.

// If v is visited before uu:

// Back edges - If v is an ancestor of uu, then the edge (u,v)(u,v) is a back edge. vv is an ancestor exactly if we already entered v, but not exited it yet. 
// The back edges complete a cycle as there is a path from ancestor v to descendant uu (in the recursion of DFS) and an edge from descendant uu to ancestor v (back edge), thus a cycle is formed. Cycles can be detected using back edges.
// A back edge connects a node to its ancestor which is not its direct parent.
// Hene, a back edge can never be a bridge


// Forward Edges - If v is a descendant of uu, then edge (u,v)(u,v) is a forward edge. In other words, if we already visited and exited v and entry[u]<entry[v]entry[u]<entry[v] then the edge (u,v)(u,v) forms a forward edge.
// A Forward edge may or may not be a bridge.


// Cross Edges - if vv is neither an ancestor or descendant of uu, then edge (u,v)(u,v) is a cross edge. In other words, if we already visited and exited vv and entry[u]>entry[v]entry[u]>entry[v] then (u,v)(u,v) is a cross edge.



// ALTERNATE CODE
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
int in[101], low[101], vis[101];
int timer;                        // global hence initialised to zero

void dfs(int node, int par){
    vis[node] = 1;                // whenever we visit a node mark it as visited
    in[node] = low[node] = timer; // initialise its in and low time
    timer++;                      // increment the timer

    for(int child: adj[node]){
        if(child == par) continue; // if the node is its parent we cant to anything so we continue

        if(vis[child]==1){
            // edge node - child is a back edge, then we minimise the low time of the node(coz a shorted path exists)
            low[node] = min(low[node], in[child]);
        }
        else{
            // edge node - child is a forward edge
            dfs(child, node);

            // bridge condition
            if(low[child]>in[node]){    // the child should have some more value(izzat) ie more time to be part of the bridge
                cout<<node<<"-"<<child<<" is a bridge\n";
            }
            low[node] = min(low[node], low[child]);  // minimising the current node
        }
    }
}

int main(){
    int n,m,u,v;
    cin>>n>>m;

    while(m--){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);  // it is imp to pass parent for each node, to distinguish bw parent and ancestor for a visited node (anything invalid say -1 is parent of the root)

    return 0;
}



// 1--2--3
//    \  /
//     4
// low[4] < in[3] hence edge 3-4 cannot be a bridge, coz there is already a shorter path 2 - 4 and removing 3-4 edge wont split the graph into two


// low is the node(except the parent) having the least in-time(less than in[node]) from which node is reachable, 
// thus carving out an alternate path from source to node.



// Explanation for: low[node] = min(low[node], low[child]);  // minimising the current node
// we update low time of 3 marking that there is a child of 3 by which we can reach 2 and which is node 4. 
// when we backtrack to node 2, he found that low time of 3 is equal to his in time. then 2 will understand there is a back edge of 3's child to reach him. 
// thus node 2 understand 2-3 is not a bridge.
// After checking a forward edge weather it is bridge or not , 
// low[node] = min(low[node], low[child]) , this condition would update the low[node] of the parent only if its child node's low will be smaller than that of parent node .
// It would be true only if child has a backedge to a node that is ancestor to both child and parent , so it is imp to update parent low to this value.
// It would also be true when decendent of child has a backedge to a node that is ancestor to both current node and its parent , as  because of recursion it would keep on updating ....

