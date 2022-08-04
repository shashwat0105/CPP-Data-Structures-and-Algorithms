https://leetcode.com/problems/find-eventual-safe-states/

// My failed first attempt, I didn;t checked nodes pointing to safe nodes will also become safe.


Soln:
// The graph data is given in the form of adjacency list.
https://youtu.be/4ymVOCiQBtw

// Related to detect cycle in directed graph.
// Implementation ques of cycle detection in a directed graph/
// The nodes which are a part of a cycle are not our ans. Rest nodes will be in our ans.

class Solution {
public:
    bool dfs(int s, vector<bool> &visited, vector<bool> &dfsVisited, vector<vector<int>>&graph, vector<bool> &presentCycle){
        visited[s] = true;
        dfsVisited[s] = true;
        
        vector<int>data = graph[s];
        for(auto x: data){
            if(!visited[x]){
                if(dfs(x, visited, dfsVisited, graph, presentCycle)){
                    return presentCycle[s] = true;    // instead of just return true(similar to path compression done in DSu)
                }
            }
            else if(visited[x] && dfsVisited[x]){
                return presentCycle[s] = true;        // instead of just return true
            } 
        }
        
        // if we dont get the loop, we retrace
        dfsVisited[s] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        vector<bool> visited(n, false), dfsVisited(n, false);
        vector<bool> presentCycle(n, false);                   // represents which elements are comprising the cycle
        for(int i=0; i<n; ++i){
            if(!visited[i]){
                dfs(i, visited, dfsVisited, graph, presentCycle);
            }
        }
        
        for(int i=0; i<n; ++i){
            if(!presentCycle[i]) ans.push_back(i);
        }
        return ans;
    }
};
