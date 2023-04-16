// SINGLE SOURCE SHORTEST PATH (SSSP) For Unweighted Graph
https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

"We use simple BFS"
// BFS is level order traversal.
// For SSSP in a tree we use DFS because of the property of a tree that 1.) only one connected component, 2.) n-1 edges if n nodes are there. 
// Meaning in a tree there is "no cycles" so for any node there is only one path from source so it has to be the smallest path. 
// While a graph can contain cycles so a node can have more than one paths from source, so to find the shortest of a number of paths we have to use BFS.

// For weighted we will have Dijasktra's algorithm.

    1 --- 2
  / |     \
0   |      \    7
  \ |       \ /  \
    3--4--5--6 --- 8


// Adjacency List
0 - 1 3
1 - 0 2 3
2 - 1 6
3 - 0 1 4
4 - 3 5
5 - 4 6
6 - 2 5 7 8
7 - 6 8
8 - 6 7

// Assume all the edges are weighted as 1

// We have to find shortest distance from source node(not necessarily 0) to all other nodes

// We will use BFS algo and do some modifications(greedy)

// Instead of visited we keep a distance array which tells me what is the shortest distance that has been previously visited for this particular node.
// Distance array 0 to 8, initialise every element by Infinity
// Queue used to store nodes
// Put source node in queue and mark its distance as 0


vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    // making graph
    unordered_map<int, vector<int>> adj;
    for(auto &edge: edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> dist(N, 1e9);                  // mark every element of distance array as infinity
    queue<int>q;

    dist[src] = 0;                              // mark the distance of the source as 0
    q.push(src);                                // and added the source to our queue

    while(!q.empty()){
        int node = q.front();                   // get the node from the queue
        q.pop();                                // and take it out of the queue

        for(auto &it : adj[node]){              // traverse for all its adjacent nodes
            if(dist[node] +1 < dist[it]){       // ditance of the node + 1(edge length bw node and adjacent node) is less than the current distance of a adjacent node
                dist[it] = dist[node] + 1;      // basically choosing the min ie update it
                q.push(it);                     // put the adjacent node in the queue
            }
        }
    }
    for(int i=0; i<N; ++i){
        if(dist[i]==1e9) dist[i]=-1;
    }
    return dist;
}
