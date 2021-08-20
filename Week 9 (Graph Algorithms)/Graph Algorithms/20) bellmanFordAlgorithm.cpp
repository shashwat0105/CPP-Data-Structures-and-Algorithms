// To find shortest distance from any source to all other nodes.

// Dijakstra's algorithm didn't worked for negative edge weights.
//    -2
// O------O  when we move from O to O again and again -2-2-2-2... = -8 and so on it will keep becoming lesser and dijakstra fails.

// Bellman ford works for directed graph whether positive or negative edges
// If there is undirected graph convert it into directed by making bi-directional edges.


// Relax all the edges  n-1 times.
// if(dist[u] + wt < dist[v])
//      dist[v] = dist[u] + wt;

#include <bits/stdc++.h>
using namespace std;

struct node{
    int u, u, wt;
    node(int first, int second, int weight){
        u = first;
        v = second;
        wt = weight;
    }

};

int main(){
    int N, m;
    cin >> N >> m;
    vector<node> edges;
    for(int i = 0; i <m; i++){
        int u, v, wt;
        cin>> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }
    
    int src;
    cin>>src;

    int inf = 10000000;
    vector<int> dist(n, inf);

    dist[src] = 0;                                   // distance to source will always be zero                 

    for(int i = 1; i <= N-1; i++){                   // relaxing the edges
        for(auto it : edges){
            if(dist[it.u] + it.wt < dist[it.v]){
                dist[it.v] = dist[it.u]  + it.wt;
            }
        }
    }
    int fl = 0;                                     // one more relaxation to check if there is negative cycle. 
    for(auto it : edges){
        if(dist[it.u] + it.wt < dist[it.v]){        // more relaxation and distance should not reduce but it is still reducing hence we declare it as negative cycle 
            cout<< "Negative Cycle";
            fl = 1;
            break;
        }
    }

    if(!fl){
        for(int i = 0; i<N; i++){
            cout<<i<<" "<<dist[i]<<endl;
        }
    }

    return 0;
}


