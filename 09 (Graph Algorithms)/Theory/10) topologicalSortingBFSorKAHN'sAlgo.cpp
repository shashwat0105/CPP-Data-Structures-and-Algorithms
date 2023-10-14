// Topological sorting using BFS is known as Kahn's Algorithm.

// 5 → 0 ← 4
// ↓       ↓
// 2 → 3 → 1

// 5 4 0 2 3 1 is one of the toposort

"INDEGREE concept is used"

// Indegree of a node is no of edges directed towards it.
// Node Indegree
// 0 is 2
// 1 is 2
// 3 is 1
// 4 is 0
// 5 is 0

// We will use queue(FIFO) data structure here  

// It is guaranteed that nodes with indegree = 0 will come first in our topological sort, so we push them first into our queue
// 4 and 5 have indegree as 0, so we push them first in our queue data structure
// Baaki nodes ko bhi tabhi queue m dalenge jab unki bhi indegree 0 ho jaegi reduce hote hote.

// Also known as KAHN's Algorithm
// Nothing like visited is here.

class Solution{
    public:
    vector<int> topoSort(int N, vector<int> adj[]) {
	    queue<int>q;                       // define queue
        vector<int> indegree(N, 0);       // indegree array of size N and all values as 0
        for(int u=0; u<N; u++){           // graph has 0 based indexing so we run a loop from 0 to N
            for(auto &v : adj[u]){        // for every adjacent node
                indegree[v]++;            // why it is adjacent node coz there is a node incoming to that adjacent node, so for every adjacent node we increase the indegree count
            }
        }
        // Fill queue with nodes having indegree = 0
        for(int i=0; i<N; i++){
            if(indegree[i]==0){          // basically insert all the nodes to the queue having indegree = 0 
                q.push(i);
            }
        }

        vector<int> topo;                // declare topo vector
        while(!q.empty()){               // run the bfs algo till the queue is not empty
            int u = q.front();           // whatever is in the front of the queue assign it node  
            q.pop();                     // then delete that element from the queue
            topo.push_back(u);           // and add that element/node to topo ans
            // node is in toposort so remove it from indegree.
            for(auto &v : adj[u]){       // traverse for all its adjacent nodes
                indegree[v]--;           // we decrease its in degree as we removed its parent and put it into queue and ans (edge removal process)
                if(indegree[v]==0){      // on reducing indegree if reaches 0, push it to queue
                    q.push(v);
                }
            }
        }
        return topo;
	}
};

// This is the best code to detect cycle as well as doing topo sort. Just can make simple a check of size of this ans array = no of nodes.
