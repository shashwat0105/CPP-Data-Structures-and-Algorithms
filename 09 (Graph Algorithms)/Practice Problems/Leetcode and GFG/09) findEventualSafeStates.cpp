https://leetcode.com/problems/find-eventual-safe-states/

// My failed first attempt, I didn't checked nodes pointing to safe nodes will also become safe.

Ques based on detect a cycle in a directed graph.

Soln:
// The graph data is given in the form of adjacency list.
https://youtu.be/4ymVOCiQBtw  (Hello world)

// Implementation ques of cycle detection in a directed graph
// The nodes which are a part of a cycle or connected to a cycle are not our ans. Rest nodes will be in our ans.

DFS:

class Solution {
public:
    bool dfs(int s, vector<bool> &visited, vector<bool> &dfsVisited, vector<vector<int>>&graph, vector<bool> &nodesNotInCycle){
        visited[s] = true;
        dfsVisited[s] = true;
        nodesNotInCycle[s] = false;  // Extra line not necessary already all are false.

        for(auto x: graph[s]){
            if(!visited[x]){
                if(dfs(x, visited, dfsVisited, graph, nodesInCycle)){
                    return true;    
                }
            }
            else if(dfsVisited[x]){     // It is visited and also part of cycle
                return true;        
            }  
        }
        // we didnt got in a loop
        nodesNotInCycle[s] = true;  // this particular node was not part of cycle hence mark it true.
        dfsVisited[s] = false;      // backtrack
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        vector<bool> visited(n, false); 
        vector<bool> dfsVisited(n, false);                        // inRecursion array
        vector<bool> nodesNotInCycle(n, false);                   // represents which elements are safe nodes
        for(int i=0; i<n; ++i){
            if(!visited[i]){
                dfs(i, visited, dfsVisited, graph, nodesNotInCycle);
            }
        }
        
        for(int i=0; i<n; ++i){
            if(nodesNotInCycle[i]) ans.push_back(i);
        }
        return ans;
    }
};

// Dusra yeh bhi hai ki wo nodes nikal lo jo cycle ka part hai ie jaha cycle mil jae un nodes ko 1 kr do.
// for(auto x: graph[s]){
//     if(!visited[x]){
//         if(dfs(x, visited, dfsVisited, graph, presentCycle)){
//             presentCycle[s] = true;
//             return true;    
//             // return presentCycle[s]=true // instead of just return true(similar to path compression done in DSu)
//         }
//     }
//     else if(dfsVisited[x]){
//         presentCycle[s]=true;
//         return true;        // instead of just return true
//     } 
// }

BFS : 
Toposort Kahns
Refer my submission for code.
https://youtu.be/2gtg3VsDGyc  (Striver)

We reverse the edge directions here and then solve to make terminal nodes have indegree = 0.
https://takeuforward.org/data-structure/find-eventual-safe-states-bfs-topological-sort-g-25/
