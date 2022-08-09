https://leetcode.com/problems/number-of-provinces/

// Counting number of connected components.

// Even the node values are from 1-n
// Since we only need to count components, we can run loops of 0 to n-1

// My first approach:
class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis){
        vis[node] = 1;
        for(auto child: adj[node]){
            if(vis[child]==0){
                dfs(child, adj, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Adjacency matrix is given.
        // Making Adjacency list graph
        int n = isConnected.size();
        vector<int> adj[n];                 // creating n vectors
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> vis(n, 0);
        int cnt = 0;
        for(int i=0; i<n; ++i){
            if(vis[i]==0){
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};


// Space optimized solution:

class Solution {
public:
    
    void dfs(vector<vector<int>>& M,int i,int j){
        M[i][j]=M[j][i]=0;  
        for(int k=0;k<M.size();k++)
            if(M[j][k]) dfs(M,j,k);
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(M[i][j]){
                    dfs(M,i,j);
                    ans++;
                }
            }
        }
        return ans;        
    }
};
