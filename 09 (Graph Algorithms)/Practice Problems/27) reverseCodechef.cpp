https://www.codechef.com/problems/REVERSE

// Problem is of shortest path
https://youtu.be/SQOQ99stCas

// Concept of 0-1 bfs is used
At a particular time there are atmost two consecutive levels inside the queue DS in BFS.

// O-1 BFS 
// The weights of the edges are either 0 or 1
// In this BFS visited array is not required
https://youtu.be/SQOQ99stCas

// If the weight is 0, I want to process it first, hence I put it in front of the queue
// If the weight is 1, as usual I will put it into the queue back
// Hence we use DEQUE

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;         // A vector can have this size
const int INF = 1e9+10;

vector<pair<int, int>> g[N];  // we want to store weight as well
vector<int> lev(N, INF);

int n, m;

int bfs() {   // Will return the distance from start to end 
	deque<int> q;
	q.push_back(1); // Adding source node
	lev[1] = 0;
	while(!q.empty()){
		int cur_v = q.front();
		q.pop_front();

		for(auto child: g[cur_v]){
			int child_v = child.first;
			int wt = child.second;
			// Instead of using visited here we will do the following
			if(lev[cur_v] + wt < lev[child_v]){    // Jo naya level ayega kya wo current stored level se chota hai, starting wale INF se chota ho skta hai ya 0 wali edge ayegi usse chota ho skta hai
				lev[child_v] = lev[cur_v] + wt;
				if(wt==1){
					q.push_back(child_v);
				}
				else{                        // ie wt is 0
					q.push_front(child_v);
				}
			}
		}
	}
	return lev[n] ==INF ? -1 : lev[n];
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin>>n>>m;
	for(int i=0; i<m; ++i){
		int x, y;
		cin>>x>>y;
		if(x==y) continue;        // self loop, daalne na daalne se fark ni padega
		g[x].push_back({y, 0});   // Directed edge given in ques, we add with 0 weight
		g[y].push_back({x, 1});   // We add a reverse edge by ourselves with a weight of 1
	}
	cout<<bfs()<<endl;

	return 0;
}


// This can also be solved using Dijkstra algorithm
// But extra logn complexity will be involved in it.

