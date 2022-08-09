https://leetcode.com/problems/course-schedule-ii/

// Ques based on topological sort.

// Topo sort is possible for DAG only (Directed Acyclic Graph)
// It is a linear ordering of vertices such that for every directed edge uv (u->v), 
// vertex u comes before vertex v in the ordering.

// Topo sort starts with nodes having indegree values as zero and ends with nodes having outdegree values as 0.

// Topo sort using DFS+stack

https://youtu.be/qe_pQCh09yU

// From the prerequisites array we make a graph
// Then we check for a cycle.
// IF not a cycle it is DAG return toposort.

CODE:   

class Solution {
public:
    // Here extra we have to check for cycle too. Using graph coloring technique
    bool detectCycle_util(vector<vector<int>> &adj, vector<int> &vis, int node){
        if(vis[node] == 1) return true;
        if(vis[node] == 2) return false;
        
        vis[node] = 1;  // mark current as visited
        for(auto child: adj[node]){
            if(detectCycle_util(adj, vis, child)) return true;
        }
        vis[node] = 2;  // mark node as processed
        return false;
    }
    
    bool detectCycle(vector<vector<int>> &adj, int n){
        vector<int> vis(n, 0);
        for(int i=0; i<n; ++i){
            if(vis[i]==0){
                if(detectCycle_util(adj, vis, i)) // there can be multiple components
                    return true;
            }
        }
        return false;
    }
    
    //
    void dfsTopo(vector<vector<int>> &adj, int node, vector<int> &vis, stack<int> &s){
        vis[node] = 1;
        for(auto child: adj[node]){
            if(vis[child]==0){
                dfsTopo(adj, child, vis, s);
            }
        }
        s.push(node);                        // when we are required to backtrack ie reached an end, then we push it into our stack
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        // making the graph
        for(auto pre: prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }
        
        // Detect cycle
        vector<int> ans;
        if(detectCycle(adj, numCourses)) return ans;  // ie empty vector if there is a cycle
        
        // Apply dfs and find topo sort
        stack<int> s;
        vector<int> vis(numCourses, 0);
        for(int i=0; i<numCourses; ++i){
            if(vis[i]==0) dfsTopo(adj, i, vis, s);
        }
        
        // Now the stack is created that is our ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};


