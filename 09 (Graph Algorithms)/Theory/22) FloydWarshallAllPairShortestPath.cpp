// In dijkstra: There is a single source from where we find shortest path to all other nodes.
// What if we want shortest distance of 7 from 2 as well as 3 ie there are multiple sources.
// Ie finding shortest path between any two pairs.

https://youtu.be/5MEZXOyaRmk

https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html#practice-problems

Dynamic programming ie storing of values is used.

// We allow 1, 2, 3, ... k nodes or levels at a time in finding the distance.

// This algorithm
// 1) Handles negative weights
// 2) DOESNOT handles negative weighted cycle

#include <bits/stdc++.h>
using namespace std;

const int N = 510;
const int INF = 1e9+10;

int dist[N][N];

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif

	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			if(i==j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
	int n, m;
	cin>>n>>m;
	for(int i=0; i<m; ++i){
		int x, y, wt;
		cin>>x>>y>>wt;
		dist[x][y] = wt; 
	}

	// Floyd warshall
	for(int k=1; k<=n; ++k){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
                if(dist[i][k]!=INF && dist[k][j]!=INF)   // helps u handle negative weights
				    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}	
	}
    // TC = O(N^3) of a floyd warshall algorithm

	// Printing results
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(dist[i][j]==INF) cout<<"I ";
			else cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// Sample Input
6 9
1 2 1
1 3 5
2 3 2
3 5 2
2 5 1
2 4 2
4 5 3
4 6 1
5 6 2

// Sample Output
0 1 3 3 2 4 
I 0 2 2 1 3 
I I 0 I 2 4 
I I I 0 3 1 
I I I I 0 2 
I I I I I 0 


// Refer https://codeforces.com/problemset/problem/295/B (Greg and Graph) from practice section
