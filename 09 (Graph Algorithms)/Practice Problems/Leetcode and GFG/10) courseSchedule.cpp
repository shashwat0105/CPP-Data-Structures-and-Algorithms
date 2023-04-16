https://leetcode.com/problems/course-schedule/

Question of topological sort.
"Something before something hence topo sort must come to your mind"

Here I have to return whether or not i can complete all the courses.

Mai kyu kabhi koi course nahi kar paya coz mai ek cycle m fas gaya.
Return true if not a cycle. Return false if a cycle present.

Cycle Detection in Directed Graph.

Can do by DFS (Using 2 arrays one of visited and other of isInRecursion)

Or by Topological sort

Now Topological sort can by done by
1) DFS (Using a stack or vector(later reverse) after calling DFS and we need to check for cycle as well so we use inRecursion) 
2) BFS (Kahns algorithm indegree wali) Below code:

Cycle Detection directed graph BFS (kahns):
Code:
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        int cnt = 0; // count of elements in topological sort
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto &it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return cnt==numCourses;    // I am able to write topo sort means cycle is not present.
    }
};


Cycle Detection directed graph DFS:
Code:
class Solution {
public:
// Using topoDfs(alone not enough) along with cycle detection
    bool isCycleDFS(int u, unordered_map<int, vector<int>> &adj,  vector<bool> &vis, vector<bool> &inRecursion){
        vis[u] = true;
        inRecursion[u] = true;

        for(int &v: adj[u]){
            if(!vis[v] && isCycleDFS(v, adj, vis, inRecursion))
                return true;
            else if(inRecursion[v])
                return true;
        }
        inRecursion[u] = false; // backtrack as new recursion call will start
        return false;  // no cycle
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<bool> vis(numCourses, false);
        vector<bool> inRecursion(numCourses, false);

        // Make graph 
        for(auto &vec: prerequisites){
            int a = vec[0];
            int b = vec[1];
            // b--->a
            adj[b].push_back(a); // Directed graph
        }

        for(int i=0; i<numCourses; ++i){
            if(!vis[i] && isCycleDFS(i, adj, vis, inRecursion))
                return false;  // cycle existed course cannot be completed
        } 
        return true; // course can be completed
    }
};
