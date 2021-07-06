// 1---2               3---5---6---7
//     |                   |       |
//     4                  10---9---8
//                                 |
//                                 11

// Adjacency list for this graph
// 1 - 2
// 2 - 1 4
// 3 - 5
// 4 - 2
// 5 - 3 10 6
// 6 - 5 7 
// 7 - 6 8
// 8 - 7 9 11
// 9 - 8 10
// 10 - 5 9
// 11 - 8
                            
// visiting array of size 11 will be created and initialised to 0
// then for loop and calls bfs for every unvisited node
// pseudo code
// for(i = 1 to N)
// {
//     if(!vis[i])
//     if(cyclebfs(i))
//         return T;
// }

// Any of the components has a cycle then graph is cyclic

class Solution{

public:
    bool checkForCycle(int s, int V, vector<int>adj[], vector<int>& visited){  // takes the starting node for which bfs will start, no of nodes(not required tho), graph stored in adjacency list and visited array

        // create queue for bfs
        queue<pair<int, int>> q;         // create a queue which stores the node as well as previous/parent

        visited[s] = true;               // marking the node which is visited now
        q.push({s, -1});                 // initial starting node with previous as -1

        while(!q.empty()){               // when queue is not empty
            int node = q.front().first;  // topmost element of the queue we get node as well as parent
            int par = q.front().second;
            q.pop();

            for(auto it : adj[node]){    // we traverse for all its adjacent nodes
                if(!visited[it]){        // if its not been visited yet
                    visited[it] = true;  // mark it as visited
                    q.push({it, node});  // put it in the pair queue
                }
                else if(par!=it){        // if the adjacent node is already visited and is not equal to parent that means there is a cycle, vis is true, hence we check if its a node which is the forward node, hence checking if not parent
                    return true;
                }
            }
        }
        return false;                    // queue became empty and doesn't has a cycle
    }
    

public: 
    bool isCycle(int V, vector<int>adj[]){        // V = total no of nodes, adjacency list
        vector<int>vis(V+1, 0);                   // will declare a visited array which will be initially marked as 0
        for(int i=1; i<=V; i++){
            if(!vis[i]){                          // for every unvisited node we will call the checkForCycle function
                if(checkForCycle(i, V, adj, vis)) // i = starting node for which bfs is called, no of nodes, adjacency list and visited array
                    return true;                  // will return true when checkForCycle will return true
            }
        }

        return false;
    }
};



