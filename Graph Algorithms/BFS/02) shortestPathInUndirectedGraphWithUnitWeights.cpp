// SINGLE SOURCE SHORTEST PATH (SSSP) For Unweighted Graph we use BFS
// BFS is level order traversal.
// For SSSP in a tree we use DFS because of the property of a tree that ,1.) only one connected component, 2.) n-1 edges if n nodes are there. 
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

// We have to find shortest distance from start node 0 to all other nodes

// We will use BFS algo and do some modifications(greedy)

// Distance array 0 to 8, initialise every element by Infinity
// Queue used to store nodes
// Put source node ie in queue and mark the distance as 0

void BFS(vector<int>adj[], int N, int src){    // we have adjacency list, no of nodes and source
    int dist[N];
    for(int i=0; i<N; i++) dist[i] = INT_MAX;   // mark every element of distance array as infinity
    queue<int>q;

    dist[src] = 0;                              // mark the distance of the source as 0
    q.push(src);                                // and added the source to our queue

    while(!q.empty()){
        int node = q.front();                   // get the node from the queue
        q.pop();                                // and take it out of the queue

        for(auto it : adj[node]){               // traverse for all its adjacent nodes
            if(dist[node]+1<dis[it]){           // ditance of the node + 1(edge length bw node and adjacent node) is less than the current distance of a adjacent node
                dis[it] = dist[node] + 1;       // basically choosing the min
                q.push(it);                     // put the adjacent node in the queue
            }
        }
    }
    for(int i=0; i<N; i++) cout<< dist[i]<<" "; // print out the distance array
}


// To practice later
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
