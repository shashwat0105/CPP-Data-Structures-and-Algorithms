// Given a tree. construct an array subSize[], 
// where subSize[V] stores size of subtree rooted at node V

//         1
//         |
//         2
//       /   \
//      3     4 
//     /     /  \
//    7     5    6  

// subsize[1] = 7
// subsize[2] = 6
// subsize[3] = 2
// subsize[4] = 3
// subsize[5] = 1
// subsize[6] = 1
// subsize[7] = 1

// subtree size of a node can be calculated from subtree size of its children
// ie subtree size of 2 = subtree size of 3 + subtree size of 4 + current(which is 1)

#include <bits/stdc++.h>
using namespace std;
vector<int> ar[100001];
int vis[100001] , subSize[100001];

int dfs(int node)                     // returns the size of the subtree rooted at node 'node'
{
	vis[node] = 1;
	int curr = 1;
	
	for(int child : ar[node])
	if(vis[child] == 0)
	{
		curr += dfs(child);
	}
	
	return subSize[node] = curr;
}

int main() {
	int n , a , b; // n = number of nodes
	
	cin>>n;
	for(int i=1;i<n;i++)	//for tree edges = n-1
	cin>>a>>b , ar[a].push_back(b) , ar[b].push_back(a);
	
	//call dfs(1) when 1 is root , if another node is root than pass that node, coz it will be the main parent
	dfs(1);
	
	for(int i=1;i<=n;i++)
	cout<<"sub tree size of node "<<i<<" is "<<subSize[i]<<endl;
	return 0;
}



// CHECK FOR THIS BELOW
// ( Outtime(node) - Intime(node) )/2 + 1 
