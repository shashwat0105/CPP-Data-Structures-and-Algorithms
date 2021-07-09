// http://www.i2symbol.com/symbols/arrows   (copied arrow symbols from here)
// "DIRECTED GRAPH"

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

// In directed we use 2 arrays to keep track of visited nodes

class Solution{
private:
	bool checkCycle(int node, vector<int>adj[], int vis[], int dfsVis[]){
		vis[node] = 1;                                               // on visiting we mark that node as 1 in vis array
		dfsVis[node] = 1;                                            // also we mark it as 1 in dfsVis array
		for(auto it : adj[node]){                                    // then we look for the adjacent node
			if(!vis[it]){                                            // if that adjacent node has not been visited
				if(checkCycle(it, adj, vis, dfsVis)) return true;    // recursive dfs calls, return true if inner dfs call is true
			}
			else if(dfsVis[it]){                                     // adjacent node has been visited & dfsVis node is also visited then it is a cycle
				return true;
			}
		}
		dfsVis[node] = 0;                                            // any adjacent node didnt return true ie there is no cycle for this recursive call, and we mark dfsVis as 0
		return false;												 // and return false
	}

public:
	bool isCyclic(int N, vector<int>adj[]){           // taking no of nodes and adjacency list
		int vis[N], dfsVis[N];                        // declaring two arrays              
		memset(vis, 0, sizeof(vis));                  // assign 0's to both of the arrays
		memset(dfsVis, 0, sizeof(dfsVis));

		for(int i = 0; i < N; i++){                   // iterating for every node
			if(!vis[i]){                              // if it has not been visited

				if(checkCycle(i, adj, vis, dfsVis)){  // we call the check cycle func, if in any call it returns true then it is cyclic
					return true;
				}
			}
		}
		return false;
	}
};






// check for below code
#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int> > g;

void addedge(int a,int b,bool bidir=true)
{
    g[a].push_back(b);
	if(bidir)
    g[b].push_back(a);
}
bool cycle_directed(int source,vector<int> &visited,vector<int> &dfs_visited)
{
	visited[source]=1;
	dfs_visited[source]=1;
	for(auto nbr:g[source])
	{
		if(!visited[nbr])
		{
			if(cycle_directed(nbr,visited,dfs_visited))
			return true;
		}
		else if(dfs_visited[nbr])
		return true;
	}
	dfs_visited[source]=0;
	return false;
}
bool check_cycle_directed_DFS()
{
	vector<int> visited(g.size()+1,0);
	vector<int> dfs_visited(g.size()+1,0);
	for(int i=1;i<=g.size();i++)
	{	
		if(!visited[i])
		{
		if(cycle_directed(i,visited,dfs_visited))
		return true;
		}
	}
	return false;
}
};
int main()
{
    Graph g2;
	g2.addedge(1,2,false);
	g2.addedge(2,3,false);
	g2.addedge(3,4,false);
	g2.addedge(4,5,false);
	g2.addedge(5,6,false);
	g2.addedge(3,6,false);
    g2.addedge(2,7,false);
    g2.addedge(8,7,false);
    g2.addedge(8,9,false);
    g2.addedge(9,7,false);
	if(g2.check_cycle_directed_DFS())
	cout<<"\nCycle is present in this Directed Graph";
	else
	cout<<"\nCycle is not present in this Directed Graph";
    return 0;
}