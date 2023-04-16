// "DIRECTED GRAPH"

https://www.geeksforgeeks.org/detect-cycle-in-a-graph/   
https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

Take example:
0 -> 1 <- 2
// Now in this when DFS of 2 will be called, when it will reach 1, it will say that 1 is already visited and it is not my parent, hence cycle honi chahiye.
// But but, cycle nahi hai. Hence same logic of undirected graph will not work. We need to do extra.
// Along with visted, the node should be in "current recursion(2 k liye separate dfs call hui thi)" for a cycle to exist in directed graph.
// Parent m toh kabhi jaega nahi coz directed graph hai(Hence no use of parent)

CRUX: 
// We use 2 arrays: To detect a back edge, we need to keep track of the nodes visited till now and the nodes that are in the current recursion stack 

1 →  2 →  3 → 4 
	 ↑    ↓   ↓    
     7    6 → 5      
   ↙  ↖
  8  →  9

Adjacency List
1 → 2
2 → 3
3 → 4, 6
4 → 5
5 →
6 → 5
7 → 2 8
8 → 9
9 → 7

// In directed we use 2 arrays to keep track of visited nodes and the nodes in current recursion stack.

class Solution{
private:
	bool checkCycle(int node, vector<int> adj[], vector<int> &vis, vector<int> &inRecursion){
		vis[node] = 1;                                                     // on visiting we mark that node as 1 in vis array
		inRecursion[node] = 1;                                             // also we mark it as 1 in  array
		for(auto &it : adj[node]){                                         // then we look for all the adjacent nodes
			if(!vis[it]){                                                  // if that adjacent node has not been visited
				if(checkCycle(it, adj, vis, inRecursion)) return true;     // recursive dfs calls, return true if inner dfs call is true
			}
			else if(inRecursion[it]){                                      // A node that is visited and also is in current recursion then it is a cycle
				return true;
			}
		}
		inRecursion[node] = 0;                                // Backtrack // any adjacent node didnt return true ie there is no cycle for this recursive call, and we mark inRecursion as 0
		return false;								 				       // and return false
	}

public:
	bool isCyclic(int N, vector<int>adj[]){                // taking no of nodes and adjacency list
		vector<int> vis(N, 0);
        vector<int> inRecursion(N, 0);
		
		for(int i = 0; i < N; i++){                        // iterating for every node
			if(!vis[i]){                                   // if it has not been visited
				if(checkCycle(i, adj, vis, inRecursion)){  // we call the check cycle func, if in any call it returns true then it is cyclic
					return true;
				}
			}
		}
		return false;
	}
};


// You can also do both the jobs in one array
// By marking vis as 1 and inRecursion as 2
