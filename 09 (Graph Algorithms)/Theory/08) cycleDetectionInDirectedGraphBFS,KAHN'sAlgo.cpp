 // Kahn's algorithm

// Topological sort is possible for only DAG (Directed Acyclic Graph)
// Hence, if a graph has a cycle then its topological sort is not possible (reverse thinking)


// making few changes in topological sort code:
// Taking count instead of topo array.

class Solution{
public:
    bool isCyclic(int N, vector<int> adj[]){  // function name is changed obviously
       queue<int>q;
        vector<int> indegree(N, 0);
        // Step 1: Find indegree
        for(int i = 0; i < N; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        // Step 2: Fill queue
        for(int i = 0; i < N; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        // Step 3: Simple BFS
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;                      // we are incrementing cnt  
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return cnt!=N;                 // If cnt and N are unequal means topo sort is not generated hence it is cyclic.
    }
};


