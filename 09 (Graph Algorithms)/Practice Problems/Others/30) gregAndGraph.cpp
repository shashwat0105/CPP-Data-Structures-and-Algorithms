https://codeforces.com/problemset/problem/295/B

// A question based on concept of floyd warshall algorithm.
// In floyd warshall:
// First we include 1 vertex
// Then we include 1 and 2 vertex
// Then we include 1, 2 and 3 vertices and so on... 

// In the ques we have to delete the edges
// CRUX CRACK:
// So, we can apply floyd warshall in the "reverse order" of the given deletion order.

https://youtu.be/aZ9-frzila0

// Isko dry run krna bacha hai!!

#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int INF  = 1e9+10;
 
long long dist[N][N];

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif	
	
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin>>dist[i][j];
		}
	}
	vector<int> del_order(n);
	for(int i=0; i<n; ++i){
		cin>>del_order[i];
	}
	reverse(del_order.begin(), del_order.end());
	vector<long long> ans;
	for(int k=0; k<n; ++k){
		int k_v = del_order[k];
		// Now we will minimise the distance
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				long long new_dist = dist[i][k_v] + dist[k_v][j];
				dist[i][j] = min(dist[i][j], new_dist);
			}
		}
		long long sum = 0;
		for(int i=0; i<=k; ++i){
			for(int j=0; j<=k; ++j){
				sum += dist[del_order[i]][del_order[j]];
			}
		}
		ans.push_back(sum);
	}
	reverse(ans.begin(), ans.end());
	for(auto val : ans){
		cout<<val<<endl;
	}	
	return 0;
}