// 1---3           2---5---6
//     |               |   |
//     4               8---7


// dfs:- 5->6->7->8->5 (hence cycle)

//adj list
// 1 - 3
// 2 - 5 
// 3 - 1 4
// 4 - 3
// 5 - 2 6 8
// 6 - 5 7
// 7 - 6 8
// 8 - 7 5

// pseudo code
// for(i - 1 to 8)
// {
//     if(vis[i]==0)
//     {
//         if(cycleDFS(i))
//             true;
//     }
// }

// dfs(node, previousnode) calls:- dfs(1,-1)-> dfs(3,1) -> dfs(4,3) return false No adjacent nodes hence no further recursion calls
// dfs(2, -1) (2 didnt had any prev node) -> dfs(5,2) -> dfs(6,5) -> dfs(7,6) -> dfs(8, this thing 7 is previous node and 5 is already visited) 
// ***** Any adjacent node other than previous node is visited already means its a cycle *****

class Solution{
public:
    bool checkForCycle(int node, int parent, vector<int>& vis, vector<int>adj[]){
        vis[node]=1;
        for(auto it : adj[node]){
            if(vis[it] == 0){                        // if the node is unvisited
                if(checkForCycle(it, node, vis, adj)) return true;  // parent will be the node which we came from hence parent = node
            }
            else if(it!=parent){  // it is visited already also it is not equal to parent hence marks the presence of cycle
                return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int>adj[]){
        vector<int>vis(V+1, 0);
        for(int i = 1; i<=V; i++){
            if(!vis[i]){
                if(checkForCycle(i, -1, vis, adj))
                    return true;
            }
        }
        return false;
    }
};
