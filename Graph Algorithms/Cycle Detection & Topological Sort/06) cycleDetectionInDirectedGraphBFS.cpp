 // Kahn's algorithm

// Topological sort is possible for only DAG (Directed Acyclic Graph)
// Hence, if a graph has a cycle then its topological sort is not possible (reverse thinking)


// making few changes in topological sort code

class Solution{
public:
    bool isCyclic(int N, vector<int> adj[]){  // function name is changed obviously
        queue<int>q;
        vector<int> indegree(N, 0);
        for(int i = 0; i < N; i++){
            for(auto it : adj[node]){
                indegree[it]++;
            }
        }

        for(int i = 0; i < N; i++){
            if(indegree[i]==0){
                q.push();
            }
        }

        int cnt = 0;
        while(!q.empty()){
            int node = q.front;
            q.pop();
            cnt++;                      // we are incrementing cnt 
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push();
                }
            }
        }
        if(cnt == N) return false;      // if it equals to N(no of nodes) ie topological sort has been generated and hence it is not cyclic
        return true;                    // count is not equal to N
    }

};


