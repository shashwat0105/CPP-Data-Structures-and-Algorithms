// 5 → 0 ← 4
// ↓       ↓
// 2 → 3 → 1

// 5 4 0 2 3 1 is one of the toposort

// Indegree of a node is no of edges directed towards it.
// Indegree for 0 is 2, 1 is 2, 3 is 1, 4 is 0, 5 is 0

// We will use queue(FIFO) data structure here  

// 4 and 5 have indegree as 0, so we push them firs in our queue data structure

// Also known as KAHN's Algorithm

class Solution{
    public:
    vector<int> topoSort(int N, vector<int> adj[]){ // a function toposort which will return a vector, passing no of nodes and graph stored in adjacency list
        queue<int>q;                      // define queue
        vector<int> indegree(N, 0);       // indegree array of size N and all values as 0
        for(int i=0; i<N; i++){           // graph has 0 based indexing so we run a loop from 0 to N
            for(auto it : adj[node]){     // for every adjacent node
                indegree[it]++;           // why it is adjacent node coz there is a node incoming to that adjacent node, so for every adjacent node we increase the indegree count
            }
        }
        for(int i=0; i<N; i++){
            if(indegree[i]==0){          // basically insert all the nodes to the queue having indegree = 0 
                q.push(i);
            }
        }

        vector<int> topo;                // declare topo vector
        while(!q.empty()){               // run the bfs algo till the queue is not empty
            int node = q.front();        // whatever is in the front of the queue assign it node  
            q.pop();                     // then delete that element from the queue
            topo.push_back(node);        // and add that element/node to topo sort
            for(auto it : adj[node]){    // traverse for all its adjacent nodes
                indegree[it]--;         
                if(indegree[it]==0){     // on reducing indegree if reaches 0, push it to queue
                    q.push(it);
                }
            }
        }
    return topo;
    }
    
};



