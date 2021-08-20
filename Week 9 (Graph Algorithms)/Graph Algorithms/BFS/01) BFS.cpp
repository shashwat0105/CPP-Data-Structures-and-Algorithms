// BFS is more difficult to implement than DFS.
// We can calculate the distance from the starting node to all other nodes using breadth-first search

// Algo uses queue data structure

class Solution{
public:
    vector<int>bfsOfGraph(int V, vector<int> adj[]){ // no of nodes in entire graph is V
        vector<int> bfs;                             // vector of integers name it bfs
        vector<int> vis(V+1, 0);                     // visted array of size n+1

        for(int i = 1; i<=V; i++){  // 1 based indexing 
            if(!vis[i]){            // if the node is not visited
                queue<int>q;
                q.push(i);          // we push the node we are visting right now in a queue
                vis[i] = 1;         // we mark the node visited

                while(!q.empty()){        // iterating till the queue is not empty
                    int node = q.front(); // we took out the first element of the queue
                    q.pop();              // also made sure it was deleted from the queue
                    bfs.push_back(node);  // our bfs has traversed that node so we push it in bfs vector 

                    for(auto it : adj[node]){  // all the adjacent nodes were put into the queue
                        if(!vis[it]){          // adjacency node has not been visited ie marked as zero
                            q.push(it);        // take that node and push it into queue 
                            vis[it] = 1;       // marking it as visited
                        }
                    }

                }
            }
        }
        return bfs;
    }
};


// MINI CODE

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
        distance[u] = distance[s]+1;
        q.push(u);
    }
}
