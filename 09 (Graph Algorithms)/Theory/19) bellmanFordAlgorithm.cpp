// To find shortest distance from any source to all other nodes.

https://youtu.be/0vVofAhAYjc (Bellman)

We already had dijasktra for above? Why a new algo?
// Dijakstra's algorithm didn't worked for 
//1) negative edge weights.
//    -2
// O------O  when we move from O to O again and again -2-2-2-2... = -8 and so on it will keep becoming lesser and dijakstra fails.
//2) negative cycle leads to TLE.
//   Bellman ford can detect negative cycle. (COOL)

// Bellman ford works for only for a "directed graph" whether positive or negative edges
// If there is given a undirected graph convert it into directed by making bi-directional edges.

// Relax all the edges n-1 times sequentially.
// if(dist[u] + wt < dist[v])
//      dist[v] = dist[u] + wt;
Why n-1?
In one iteration in the worst only one node can update, and there are n-1 nodes apart from source hence we require n-1 iterations.

How can it detect negative cycle?
I am sure that after n-1 iteration I will be able to relax all edges.
If I do one more iteration(in nth iteration) and again I am able to relax means there is a negative cycle.

https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1?

CODE:

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    // Code here
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    for(int i=0; i<V; ++i){
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            if(dist[u]!=1e8 && dist[u]+wt < dist[v]){
                dist[v] = dist[u]+wt;
            }
        }
    }
    
    // Nth relaxation to check negative cycle.
    for(auto &edge: edges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        
        if(dist[u]!=1e8 && dist[u]+wt < dist[v]){  // more relaxation and distance should not reduce but it is still reducing hence we declare it as negative cycle 
            return {-1};
        }
    }
    
    return dist;
}

TC = O(V*E) // helpful for negative
Dijasktra had ElogV
Most ques are solved using dijasktra, above is used for discussion.
