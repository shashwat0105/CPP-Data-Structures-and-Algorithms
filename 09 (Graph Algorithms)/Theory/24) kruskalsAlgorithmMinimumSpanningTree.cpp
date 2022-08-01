// To get MINIMUM SPANNING TREE using Kruskal's algorithm

// Minimum Spanning Tree:
// Given a graph we want to find to a tree, whose sum of weights of edges is minimum.

// Uses disjoint set data structure 
// All nodes are imagined to be separate.
// Sort the edge weights.
// Add the edges in less to more weight if its addition doesn't form a loop(wont be a tree)

// We will not store the graph in adjacency list but in a linear data structure.
// Ste 1: Sort all the edges wrt weight.

(wt,u,v)
(1,1,4)
(2,1,2)
(3,2,3)
(3,2,4)
(4,1,5)
(5,3,4)
(7,2,6)
(8,3,6)
(9,4,5)

// TC = O(M log M) + O(M* 4 alpha) = O(n log n)
// SC = O(M)
#include<bits/stdc++.h>
using namespace std;

struct node {
    int u;
    int v;
    int wt;
    node(int first, int second, int weight){
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b){                      // comparator
    return a.wt < b.wt
}

int findPar(int u, vector<int>& parent)

int main(){
    int N, m;
    cin >> N >> m;
    vector<node> edges;
    for(int i=0; i<N; i++){
        int u,v,wt;
        cin >>u>>v>>wt;
        edges.push_back(node(u,v,wt));       // storing in a linear data structure
    }
    sort(edges.begin(), edges.end(), comp);  // sorting with the help of comparator

    vector<int> parent(N);                   // making of disjoint set data structure
    for(int i=0; i<N; i++){
        parent[i] = i;
    }
    vector<int> rank(N, 0);                  // rank array initialised with zero

    int cost = 0;                            // store the MST cost
    vector<pair<int, int>> mst;              // will store all the edges of the mst
    for(auto it : edges){
        if(findPar(it.v, parent)!= findPar(it.u, parent)){  // if they donot belong to the same component
            cost += it.wt;                    // add the edge weight to the cost
            mst.push_back({it.u, it.v});      // push it in our linear data structure
            unionn(it.u, it.v, parent, rank);
        }
    } 
    
    cout << cost << endl;
	for(auto it : mst) cout << it.first << " - " << it.second << endl; 
    return 0;
}


// Another code from LUV

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int parent[N], sz[N];

void make(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find(int v){
    if(parent[v]==v) return parent[v];
    return parent[v] = find(parent[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(sz[a]<sz[b]){
            swap(a,b);
        }
        parent[b] = a;
        sz[a]+=sz[b];
    }
}

int main(){
    int n, m;
    cin>>n>>m;   // nodes and edges

    // I have to sort the vector according to the weight of the edge {wt, {u,v}} ; u and v have an edge bw them having a weight wt;
    // In pair, pehli cheez k according sort hota hai.
    vecor<pair<int, pair<int, int>>> edges;
    for(int i=0; i<m; i++){
        int u, v, wt;
        cin>>u>>v>>wt;
        edges.push_back({wt, {u, v}});
    }
    sort(edges.begin(), edges.end());

    // calling make function for every node
    for(int i=1; i<=n; ++i) make(i);

    int total_cost = 0;
    // I will take out the smallest edge and check whether I can insert it into my MST ie whether it is making a loop
    for(auto& edge : edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find(u)==find(v)) continue;   // ie their parent is same
        Union(u, v);                     // else we will join them 
        total_cost += wt;
        cout<<u<<" "<<v<<endl;
    }
    cout<<total_cost<<endl;
}

