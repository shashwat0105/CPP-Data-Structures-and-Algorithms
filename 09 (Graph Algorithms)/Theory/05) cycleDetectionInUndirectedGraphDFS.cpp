https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// 1---3           2---5---6
//     |               |   |
//     4               8---7


// dfs:- 5->6->7->8->5 (hence cycle)

//adj list = {{3}, {5}, {1,4}, {3}, {2,6,8}, {5,7}, {6,8}, {7,5}}
// 1 - 3
// 2 - 5 
// 3 - 1 4
// 4 - 3
// 5 - 2 6 8
// 6 - 5 7
// 7 - 6 8
// 8 - 7 5

// pseudo code
// for(i - 1 to 8){
//     if(vis[i]==0){
//         if(cycleDFS(i))
//             true;
//     }
// }

// dfs(node, previousnode) calls:- dfs(1,-1)-> dfs(3,1) -> dfs(4,3) return false No adjacent nodes hence no further recursion calls
// dfs(2, -1) (2 didnt had any prev node) -> dfs(5,2) -> dfs(6,5) -> dfs(7,6) -> dfs(8, this thing 7 is previous node and 5 is already visited) 
// ***** Any adjacent node other than previous node(parent node) is visited already means its a cycle *****
// Matlab mai vo node pe ja raha hu jo already visited hai ar meri wo previous node bhi nahi hai, hence cycle hai!
// Hence, We aditionally pass parent in the argument as well.

    
class Solution{
public:
    bool isCycleDFS(int node, int parent, vector<int>& vis, vector<int>adj[]){
        vis[node]=1;
        for(auto &v : adj[node]){
            if(!vis[v]){                                        // It it is not visited I call DFS
                if(isCycleDFS(v, node, vis, adj)) return true;  // You make a dfs call to this child and setting the current node as parent, & if it returns true we return true and exit // ie parent will be the node which we came from hence parent = node
            }
            else if(v!=parent) return true;
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int>adj[]){
        vector<int>vis(V+1, 0);
        for(int i = 0; i<V; i++){
            if(!vis[i] && isCycleDFS(i, -1, vis, adj)){
                return true;
            }
        }
        return false;
    }
};


// JUST AN ALTERNATE THOUGHT USING BACK EDGE // Same code as above.
         
//          1
//         / 
//        2
//      /   \
//     3 --- 4
//            \
//             5

// 1 - 2
// 2 - 1 3 4 
// 3 - 2 4
// 4 - 3 2 5
// 5 - 4

// dfs(1) calls node 2 and parent of node 2 will be 1.
// ...dfs(3) is called sees that 2 is already visited and checks if 2 is parent of 3, Yes, so it's not a back edge not cycle yet
// dfs(4) calls 3, sees already visited and its parent too, calls 2 & sees it is not parent also already visited(yahi gadbad hai) hence a back edge and a cycle
