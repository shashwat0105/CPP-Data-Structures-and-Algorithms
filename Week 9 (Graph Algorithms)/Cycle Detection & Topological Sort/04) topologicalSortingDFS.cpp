// Topological Sort:- Linear ordering of vertices such that if there is an edge u->v, 
// then u appears before v in that ordering.

// There can be multiple topo sort for a given graph
// Possible for DAG(Directed Acyclic Graph) only
// Coz in unidirected 1-2 cant say 1 to 2 or 2 to 1
// also in a cyclic graph it is not possibel 2->3->4->2 not possible

// 5 → 0 ← 4
// ↓       ↓
// 2 → 3 → 1

// 5 4 2 3 1 0  ; 4 5 2 3 1 0 are some ways of sorting in topological order for this DAG
// there is an edge 4 → 0, also in the order 4 comes before 0

// we use STACK here to output and store the toposort order

class Solution{
    void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int>adj[]){   // passing the required parameters
        vis[node] = 1;                            // marking the node as 1 once visited

        for(auto it: adj[node]){                  // traversing all its adjacent nodes
            if(!vis[it]){                         // if the adjacent node is not visited
                findTopoSort(it, vis, st, adj);   // recursive calling the findTopoSort func
            }
        }
        st.push(node);                            // only difference apart from dfs calls is here that whenever dfs call is over we store it in stack
    }

    public:
    vector<int> topoSort(int N, vector<int> adj[]){   // no of nodes, adjacency list
        stack<int> st;                                // stack data structure
        vector<int> vis(N, 0);                        // visited array initially marked as zero
        for(int i = 0; i < N; i++){                   // traverse for every node from start to end
            if(vis[i]== 0){                           // whichever node is not visited
                findTopoSort(i, vis, st, adj);        // we call the findTopoSort function
            }
        }
        vector<int> topo;
        while(!st.empty()){                           // until the stack is empty  
            topo.push_back(st.top());                 // take all the stack elements and put it into a vector
            st.pop();
        }
        return topo;                                  // finally returning that vector which will be having one of the topo sorts
    }
};


//*****************************************************
// USES:
// 
// In OS to find a deadlock (If there exist a cycle among the process then there is a deadlock)
