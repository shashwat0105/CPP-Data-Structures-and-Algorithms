https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

   2       3       6
0 ----> 1 ----> 2 ----> 3 
 \             ↗        ↑
1 \       2  /          |
   \       /          1 |
     ↘   /              |
       4 -------------> 5
               4

// The numbers in the edge shows the weight.

// Adjacency List
0 -> (1,2)  (4,1)  // 0 is connected to 1 with weight of 2, and with 4 with weight of 1
1 -> (2,3)
2 -> (3,6) 
3 -> 
4 -> (2,2) (5,4)
5 -> (3,1)

Points:
1. In order to store a weighted graph we will use a pair of integers
2. https://takeuforward.org/data-structure/shortest-path-in-directed-acyclic-graph-topological-sort-g-27/
3. You can see that in this particular question, all the test cases are designed such that 0 is the source node.
   ie 0 has indegree = 0. 
4. This ques can also be solved using Dijasktra algo(will take more time)
5. I can optimise it using toposort, why and how?
   Why?
   0 6 5 4 2 1 3
   Means 4 can be reached by 0, 6 and 5 so, I will try to minimise the distance using 0, 5 and 6.
   0 will always come on the top of the stack after writing toposort.
   https://stackoverflow.com/questions/68449275/why-do-we-need-to-perform-topological-ordering-first-to-find-shortest-path-in-a

   How?
   Step 1: Find the toposort Using DFS, stack
   Step 2: Take the nodes out of the stack and relax the edges.

6. 1e9 is lesser than INT_MAX and wouldnot overflow while calculating the distance

class Solution {
    private:
    void topoSort(int node, unordered_map<int, vector<pair<int, int>>> &adj, vector<int> &vis, stack<int> &st){   
        vis[node] = 1;                            

        for(auto &it: adj[node]){ 
            int v = it.first;
            if(!vis[v]){                         
                topoSort(v, adj, vis, st);   
            }
        }
        st.push(node);                            
    }
    
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // Step 1 :- Convert the given adj list into this form 
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto &edge: edges) {
          int u = edge[0];
          int v = edge[1];
          int wt = edge[2];
    
          adj[u].push_back({v,wt});
        }
        
        // Perform the topological Sort

        vector <int> vis(N, 0);
        stack <int> st;
        for (int i = 0; i < N; i++){
            if (!vis[i]) topoSort(i, adj, vis, st);
        }
        
        // Step 3:- Relax all the edges one by one from the stack

        vector <int> dist(N, 1e9);
        dist[0] = 0;           // dist[source] = 0; // We mark the distance of source node first to be 0.
    
        while (!st.empty()) {  // Iterating on the stack created by TOPOsort
          int node = st.top();
          st.pop();
    
          for (auto it : adj[node]) {
            int v = it.first;
            int wt = it.second;
            if (dist[node] + wt < dist[v]){
                dist[v] = dist[node] + wt;
            }
          }
        }
    
        for (int i = 0; i<N; i++){
            if (dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};

Follow up:
// Here it is given that source is zero 
// but there can be any source.
// Shortest path from any src :
// 1.Perform toposort and store the order in a stack
// 2.Once the source node is given, pop the elements in the stack until the stack's top is the source 
// 3.Rest is the same .
