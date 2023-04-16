// Topological Sort:- Linear ordering of vertices such that if there is an edge u->v, 
// then u appears before v in that ordering.

https://www.geeksforgeeks.org/topological-sorting/
https://practice.geeksforgeeks.org/problems/topological-sort/1

// There can be multiple topo sort for a given graph
// **Possible only for DAG(Directed Acyclic Graph).**
// Coz in unidirected 1-2 cant say 1 to 2 or 2 to 1
// also in a cyclic graph it is not possibel 2->3->4->2 not possible

// 5 → 0 ← 4
// ↓       ↓
// 2 → 3 → 1

// 5 4 2 3 1 0  ; 4 5 2 3 1 0 are some ways of sorting in topological order for this DAG
// there is an edge 4 → 0, also in the order 4 comes before 0

// We use a STACK here to output and store the toposort order
** Note: A vertex is pushed to stack only when all of its adjacent vertices (and their adjacent vertices and so on) are already in the stack **
// Jiska DFS ho jae usko stack m daal do.
// Mtlb meri saari adjacent vertices stack m chali jae, uske baad mai stack m jaunga coz mujhe hamesha order m unse pehle aana hai.

// You can also use a vector(instead of stack) and further reverse it to get our ans.

// Here it is given that it is a DAG, else we also had to check for a cycle.

// CODE 1 (That works for only printing Topological sort when given it is a DAG ie a cycle is not present) // Hence, works for GFG

// Because in this code the logic to detect a cycle has not been implemented.

class Solution{
    void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int>adj[]){   // passing the required parameters
        vis[node] = 1;                            // marking the node as 1 once visited

        // pehle mere baccho ko stack m daal do
        for(auto &it: adj[node]){                 // traversing all its adjacent nodes
            if(!vis[it]){                         // if the adjacent node is not visited
                findTopoSort(it, vis, st, adj);   // recursive calling the findTopoSort func
            }
        }
        // ab mujhe stack m daalo
        st.push(node);                            // only difference apart from dfs calls is here that whenever dfs call is over we store it in stack
    }

    public:
    vector<int> topoSort(int N, vector<int> adj[]){   // no of nodes, adjacency list
        stack<int> st;                                // stack data structure
        vector<int> vis(N, 0);                        // visited array initially marked as zero
        for(int i = 0; i < N; i++){                   // traverse for every node from start to end
            if(!vis[i]){                              // whichever node is not visited
                findTopoSort(i, vis, st, adj);        // we call the findTopoSort DFS function
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

// 
But there is a problem with above solution.
We are pushing every node to stack. At the end, stack will contain all nodes irrespective of we found a cycle or not. 
If there is a cycle in a directed graph, we should return false. Above code doesnot check for cycle. 
If we remember, for checking cycle in Directed Graph using DFS, we used the concept of inRecursion vector.

// CODE 2 (Also detects whether a cycle is present or not, if cycle not present prints the topo sort)
ie Topological sort using DFS with cycle detection.
Course Schedule 2 (Leetcode)

We know,
* Directed graph DFS cycle : inRecursion
* Topo sort DFS of a DAG : stack pehle mere baccho ko daalo fr mujhe daalo.
We will use both here.

class Solution {
public:
    bool hasCycle;
    void topoDfsCycle(int u, vector<int> adj[], vector<bool> &vis, vector<int> &inRecursion, stack<int> &st){
        vis[u]=true;
        inRecursion[u]=true;

        // pehele mere baccho ko daalo stack mein
        for(int &v: adj[u]){
            if(!vis[v]){
                topoDfsCycle(v, adj, vis, inRecursion, st);
            }
            else if(inRecursion[v]){ // it is already visited and also in current recursion
                hasCycle = true; // mark that there is cycle
                return;  // No need to further make calls
            }
        }

        inRecursion[u]=false; // unmark  // cycle bhi check kr rhe
        st.push(u);  // fr mujhe daalo stack mein // topological sort bhi sath m nikal rhe
    }

    vector<int> topoSort(int N, vector<int> adj[]) {
        vector<bool> vis(numCourses, false);
        vector<int> inRecursion(numCourses, false);

       
        stack<int> st;
        for(int i=0; i<numCourses; ++i){
            if(!vis[i]){
                topoDfsCycle(i, adj, vis, inRecursion, st);
            }
        }
        if(hasCycle){  
            return {};
        }
        // cycle nahi hai
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};

//*****************************************************
// USES:
// In OS to find a deadlock (If there exist a cycle among the process then there is a deadlock)

