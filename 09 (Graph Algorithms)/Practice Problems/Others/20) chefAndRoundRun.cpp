// https://www.codechef.com/problems/CHEFRRUN

// https://youtu.be/s1pYDKbYtmo

// We can solve by many methods
// Here we will use Kosaraju's algorithm 

// CRUX: All the nodes in a single strongly connected component(no of nodes in the component >=2) will act as a magic box.
//     : If a SCC of 1 node is a self loop then it is a magic box.

#include<bits/stdc++.h>
using namespace std;

using namespace std;
vector<int> adj[1000001];    // can use a simple array as well coz each element will contain only 1 child 
vector<int> trans[1000001];
vector<int> scc , order;

int vis[1000001];
int val[1000001];           //  Ai (value of the nodes)

int dfs(int node)
{
	vis[node] = 1;
	
	for(int child : adj[node])
	if(vis[child] == 0)
	dfs(child);
	
	order.push_back(node);     // to find order of the execution
}

int dfs1(int node)
{
	vis[node] = 1;
	
	for(int child : trans[node])
	if(vis[child] == 0)
	dfs1(child);
	
	scc.push_back(node);        // to find the actual strongly connected component.
}


int main()
{
	int t , n , res;
	cin>>t;
	while(t--)
	{
		
		//input and reset section
		cin>>n;
		order.clear() , res = 0;
        for(int i=1; i<= n; i++){
            adj[i-1].clear() , trans[i-1].clear() , vis[i-1] = 0;  // we are using 0 based indexing system
            cin>>val[i-1];        // reading the Ai  (values)
        }

		//graph construction section
        for(int i=1; i<= n; i++){
            int a = i - 1;
			int b = (i - 1 + val[i-1] + 1) % n;
			
			adj[a].push_back(b);
			trans[b].push_back(a);
        }
		
		//SCC section (Standard Kosaraju's Algorithm)
        for(int i=1; i<= n; i++){
            if(vis[i-1] == 0)
		    dfs(i-1);
        }
		
        for(int i=1; i <= n; i++){
            vis[i-1] = 0;
        }
				
		reverse(order.begin() , order.end());
		for(int i : order)
		if(vis[i] == 0)
		{
			scc.clear();
			dfs1(i);
			
			if(scc.size() == 1 && (scc[0] != adj[scc[0]][0])) continue;
			
			res += scc.size();
		}
		
		cout<<res<<endl;
	}
}





