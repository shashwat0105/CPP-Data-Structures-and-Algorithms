https://leetcode.com/problems/course-schedule-ii/

This is generally follow up of course schedule.
Here I have to return the order of courses as well.

// Ques based on topological sort.

// Topo sort is possible for DAG only (Directed Acyclic Graph)

// Topo sort starts with nodes having indegree values as zero and ends with nodes having outdegree values as 0.

CODE:   

1) Toposort BFS
TopoSort BFS code mein automatically cycle check hoti hai coz Kahns algorithm is also cycle detection algorithm.    

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        // Make graph and form indegree array
        for(auto &vec: prerequisites){
            int a = vec[0];
            int b = vec[1];
            // b--->a
            adj[b].push_back(a); // Directed graph
            indegree[a]++;
        }
        
        queue<int> q;
        for(int i=0; i<numCourses; ++i){
            if(indegree[i]==0){
                q.push(i);   // push nodes with indegree = 0 // coz yeh toh sbse pehle ayengi hi
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node); 
            for(auto &it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()==numCourses) return topo;
        return {};
    }
};

2) Toposort DFS

We know,
* Directed graph DFS cycle : inRecursion
* Topo sort DFS of a DAG : stack pehle mere baccho ko daalo fr mujhe daalo.
We will use both here.

class Solution {
public:
    bool hasCycle;
    void topoDfsCycle(int u, unordered_map<int, vector<int>> &adj, vector<bool> &vis, vector<int> &inRecursion, stack<int> &st){
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

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<bool> vis(numCourses, false);
        vector<int> inRecursion(numCourses, false);

        // Make graph and form indegree array
        for(auto &vec: prerequisites){
            int a = vec[0];
            int b = vec[1];
            // b--->a
            adj[b].push_back(a); // Directed graph
        }
        
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
