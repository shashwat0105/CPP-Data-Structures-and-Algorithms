// BFS is more difficult to implement than DFS.
// We can also calculate the shortest distance from the starting node to all other nodes using breadth-first search

// Algo uses queue data structure
// queue<int> q;  will be used normally
// queue<pair<int, int>> q; is used in case of weighted graph and bfs in a 2D grid/matrix.

class Solution{
public:
    vector<int>bfsOfGraph(int V, vector<int> adj[]){ // no of nodes in entire graph is V
        vector<int> bfs;                             // vector of integers name it bfs
        vector<int> vis(V+1, 0);                     // visted array of size n+1

        for(int i = 1; i<=V; i++){                   // 1 based indexing  (This I am running BFS on every node for disconnected graph can cause runtime error when using for graphs that are given connected)
            if(!vis[i]){                             // if the node is not visited 
                queue<int>q;
                q.push(i);                           // we push the node we are visting right now in a queue
                vis[i] = 1;                          // we mark the node visited

                while(!q.empty()){                   // iterating till the queue is not empty
                    int node = q.front();            // we took out the first element of the queue
                    q.pop();                         // also made sure it was deleted from the queue
                    bfs.push_back(node);             // our bfs has traversed that node so we push it in bfs vector 

                    for(auto it : adj[node]){        // all the adjacent nodes were put into the queue
                        if(!vis[it]){                // adjacency node has not been visited ie marked as zero
                            q.push(it);              // take that node and push it into queue 
                            vis[it] = 1;             // marking it as visited
                        }
                    }
                }
            }
        }
        return bfs;
    }
};


// CODE for a connected graph

queue<int> q;
bool visited[N];
int distance[N];

visited[x] = true;
distance[x] = 0;
q.push(x);
while (!q.empty()) {
    int s = q.front(); q.pop();
    // process node s
    for (auto u : adj[s]) {
        if (visited[u]) continue;
        visited[u] = true;
        distance[u] = distance[s]+1;           // this distance is also level
        q.push(u);
    }
}

// For this ques (Graph is connected is given)
https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1/#

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    vector<int> bfs;                             // vector of integers name it bfs
    vector<int> vis(V+1, 0);                     // visted array of size n+1
    queue<int> q;
     
    q.push(0);                           // we push the node we are visting right now in a queue here the first node
    vis[0] = 1;                          // we mark the node visited

    while(!q.empty()){                   // iterating till the queue is not empty
        int node = q.front();            // we took out the first element of the queue
        q.pop();                         // also made sure it was deleted from the queue
        bfs.push_back(node);             // our bfs has traversed that node so we push it in bfs vector 

        for(auto it : adj[node]){        // all the adjacent nodes were put into the queue
            if(!vis[it]){                // adjacency node has not been visited ie marked as zero
                q.push(it);              // take that node and push it into queue 
                vis[it] = 1;             // marking it as visited
            }
        }
    }
    return bfs; 
}

// Whether a destination is reachable from a source or not using BFS:
class Solution {
public:
    bool solveBFS(int n, unordered_map<int, vector<int>> &ump, int s, int d){
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(s);
        vis[s] = 1;

        while(!q.empty()){
            int temp = q.front();
            q.pop();
            vis[temp] = 1;
            for(auto it: ump[temp]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return vis[d];
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> ump;

        for(auto &edge: edges){
            ump[edge[0]].push_back(edge[1]);
            ump[edge[1]].push_back(edge[0]);
        }

        return solveBFS(n, ump, source, destination);

        // source se bfs chala do jo bhi visited ho jae use mark kar do, destination ka return kr do
    }
};

//
At a particular time there are atmost two consecutive levels inside the queue DS in BFS.

// O-1 BFS 
// The weights of the edges are either 0 or 1
https://youtu.be/SQOQ99stCas

// If the weight is 0, I want to process it first, hence I put it in front of the queue
// If the weight is 1, as usual I will put it into the queue back

// Similar Ques
https://www.codechef.com/problems/REVERSE
// Refer practice section


// Multi Source BFS
// We run normal bfs after adding all the sources simultaneously.

https://www.codechef.com/SNCKPB17/problems/SNSOCIAL/  (refer practice section)
