// https://www.geeksforgeeks.org/connected-components-in-an-undirected-graph/
// https://www.geeksforgeeks.org/program-to-count-number-of-connected-components-in-an-undirected-graph/
// https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/

// Connected components: If u chose any two nodes then exist a path from one node to another.

// Whenever we make a dfs call of a node whole connected component gets visited

// 1---3            2---9         5---7
//     |                              |
// 6---4                              10
// |
// 8

// Count of connected components is 3 here.

// For example when dfs(1) is called 1,3,4,6,8 are visited then we increase the count by 1
// Then dfs(2) is called and 2, 9 are visited count ++, dfs(3) is not called as it is already visited.
// ..... dfs(5) is called and 5,7, 10 are visited and count ++
// Hence, jitni baar dfs chala after checking visited, that is the no. of connected components.


// int main(){

//     ...
//     int cc_count = 0;

//     for(int i = 0; i <=node; i++){
//         if(vis[i]==0){
//             dfs(i);
//             cc_count++;
//         }  
//     }
//     cout<< "Count of connected components is"<<cc_count;
// }

#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100001];          // if u pass 'n' here then it will be out of scope. Coz we know adjacency list will be of size n
int vis[100001];                  // when u declare an integer array globally in c++ then all elements are initialised to 0
 
void dfs(int node)
{
	vis[node] = 1;
 
	for(int child : adj[node])
	if(!vis[child])
	dfs(child);
 
}
 
int main()
{
	int n , m , u , v;
	cin>>n>>m;
 
	for(int i=0;i<m;i++)          // there are 'm' edges
	cin>>u>>v , adj[u].push_back(v) , adj[v].push_back(u);
 
	int cc = 0;
 
	for(int i=1;i<=n;i++)         // 1 to n isliye lia hai coz vertices are from 1 to n (yeh ques m dia rahega)
	if(!vis[i])
	dfs(i) , cc++;
 
	cout<<cc;
}


// If you also want to print the connected components.

#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int visited[100001];

vector<vector<int>> cc;
vector<int> current_cc;

void dfs(int vertex){
	visited[vertex] = 1;
	current_cc.push_back(vertex);
	for(auto child : adj[vertex]){
		if(!visited[child]){
			dfs(child);
		}
	}
}

int main(){
	int n, m;
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[u].push_back(u);
	}

	int count=0;
	for(int i=1; i<=n; ++i){
		if(!visited[i]){
			current_cc.clear();
			dfs(i);
			cc.push_back(current_cc);
			count++;
		}
	}
	cout<<cc.size()<<endl;
	for(auto it : cc){
		for(int vertex: it){
			cout<<vertex<<" ";
		}
		cout<<endl;
	}
}
