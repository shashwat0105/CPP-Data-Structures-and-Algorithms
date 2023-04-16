// Kosajaru Algorithm: Helps us to find all the strongly connected components(SCC) in a directed graph.
// In undirected graph there is no notion of SCC but simply connected components.

https://youtu.be/R6uoSjZ2imo

Types of questions:
1. No of SCC
2. Print the SCC

// SCC -> Every node is reacheable to every other node in that component.

// 1  →  2  →  4
//  ↖   ↙      ↓
//    3        5 

// Here, (1,2,3) , (4), (5)  are SCC ie no of SCC = 3
// (4,5) is not an SCC because 4 can reach 5 but 5 cannot reach 4

// If we do dfs calls from start dfs(1) -> dfs(2)... dfs(5) every node will be visited
// But if we do dfs from end node ie dfs(5) will be only visited, then dfs(4) it will end coz dfs(5) is already visited.

// 3 Steps of the algorithm:
// Step 1: Sort all the nodes in order of finishing time, when you run a basic initial DFS. (Toposort using DFS)
// Step 2: Transpose the graph. ie reverse the edge connections.
// 1  ←  2  ←  4
//  ↘   ↗      ↑
//    3        5 

// Step 3: Do DFS of the reversed graph in the order obtained in Step 1. 
// And for every DFS call increase the scc by one

https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?

class Solution{
    private:
    void dfs(int node, stack<int> &st, vector<int> &vis, vector<vector<int>>& adj){
        vis[node] = 1;
        for(auto &it : adj[node]){
            if(!vis[it]){
                dfs(it, st, vis, adj);
            }
        }
        st.push(node);
    }
    private:
    void revDFS(int node, vector<int> &vis, vector<int> transAdj[]){
        // cout<< node << " ";                  // this current node is part of the SCC
        vis[node] = 1;
        for(auto &it : transAdj[node]){
            if(!vis[it]){
                revDFS(it, vis, transAdj);
            }
        }
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<vector<int>>& adj){
        // step 1 : To find the order of finishing times of the nodes
        stack<int> st;                        // toposort dfs // to store the nodes according to the out times
        vector<int> vis(n, 0);
        for(int i=0;i<n;i++){                 // insert all the nodes in oreder of definition time in toposort
            if(!vis[i]){
                dfs(i, st, vis, adj);   
            }
        }
        
        // step 2
        vector<int> transAdj[n];
        for(int i = 0; i < n; i++){
            vis[i] = 0;                       // remark the visited as 0 so that I can reuse, coz above dfs marked it visited
            for(auto it : adj[i]){            // previously we have edge from i to it, now from it to i
                transAdj[it].push_back(i);   
            }
        }
        
        // step 3
        int scc = 0;
        while(!st.empty()){
            int node = st.top();               // go on the nodes according to the finishing time ie top of the stack // Element at the top of the stack has finished last.
            st.pop();
            if(!vis[node]){                    // for unvisited nodes call reverse dfs
                scc++;
                // cout << "SCC: ";
                revDFS(node, vis, transAdj);  
                // cout<< endl;
            }
        }
        return scc;
    }
};

// In order to print the SCC just uncomment the three cout lines. BRAVO

//******************************************************************************************************************

// Kosaraju's algo uses 2 DFS & in the 2nd DFS it runs on transpose graph
// Transpose graph has same no of SCC as the original graph

// CONDENSATION GRAPH
// A graph made with SCC of original graph
// Each SCC of original graph acts as a vertex in Condensation Graph
// & there is a edge from one vertex to other & its direction depending on edge direction in original graph
// Condensation graph does not contain any cycle.
// If there is an edge a -> b
// Then    Out time of a > Out time of b

// Here the condensation graph is a DAG
// A Directed Acyclic Graph (DAG) has at least 1 node with in-degree 0
// Proof by contradiction: https://math.stackexchange.com/questions/3232341/prove-that-a-directed-graph-with-no-cycles-has-at-least-one-node-of-indegree-zer
// If we run dfs on the component having 0 in degree then only the nodes of that strongly connected component will get traversed.

// Transpose of this graph will have out-degree 0

// We will sort the nodes in increasing order of out time & call DFS accordingly.

