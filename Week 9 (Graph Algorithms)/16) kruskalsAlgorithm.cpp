// To get MINIMUM SPANNING TREE using Kruskal's algorithm
// Uses disjoint set data structure 

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




