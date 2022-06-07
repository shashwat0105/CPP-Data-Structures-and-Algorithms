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
// We aditionally pass parent in the argument.
// ***** Any adjacent node other than previous node(parent node) is visited already means its a cycle *****

class Solution{
public:
    bool checkForCycle(int node, int parent, vector<int>& vis, vector<int>adj[]){
        vis[node]=1;
        for(auto it : adj[node]){
            if(vis[it] == 0){                                       // if the node is unvisited
                if(checkForCycle(it, node, vis, adj)) return true;  // parent will be the node which we came from hence parent = node
            }
            else if(it!=parent){                                    // it is visited already also it is not equal to parent hence marks the presence of cycle
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


// ALTERNATE CODE
// https://youtu.be/eCG3T1m7rFY
         
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

bool isCyclicDfs(int node, int par){
    vis[node] = 1;

    for(int child: adj[node]){
        if(vis[child]==0){                       // the node is not visited yet
            if(isCyclicDfs(child, node)==true)   // You make a dfs call to this child and setting the current node as parent, & if it returns true we return true and exit
                return true;
        }                                        // the node is already visited
        else if(child!=par)                      // in above example we compared on dfs(4), child(adjacent node) as 2 and parent(previous node) as 3
            return true;                         // coz current edge was a back edge 
    }
    return false;                                // executed full and didn;t found a problem
}

