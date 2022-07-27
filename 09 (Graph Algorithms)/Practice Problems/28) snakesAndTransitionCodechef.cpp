https://www.codechef.com/SNCKPB17/problems/SNSOCIAL/

// We will find all the locations of the highest value in the grid and run BFS from all those sources at the same time

// Here we can move in 8 directions.

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;               // Can't use 1e5+10; will exceed the memory
const int INF = 1e9+10;

int val[N][N];   // matrix values
int vis[N][N];
int lev[N][N];
int n, m;

bool isValid(int i, int j){
	return i>=0 && i<n && j>=0 && j<m;
}

vector<pair<int, int>> movements = {    // will store where all we can move // Writing this way is a good practice, helps in debugging and avoid repeting if conditions
	{0,1}, {0,-1}, {1,0}, {-1,0}, 
	{1,1}, {1,-1}, {-1,1}, {-1,-1}
};

int bfs(){  // min number of hours in which our whole graph will get covered
	int mx = 0; // maximum value in the matrix
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			mx = max(mx, val[i][j]);
		}
	}

	queue<pair<int, int>> q;      // because the bfs will be in a matrix ie [i][j] will be a node
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(mx==val[i][j]){
				q.push({i, j});
				lev[i][j] = 0;   // all these source nodes are of level zero
				vis[i][j] = 1;
			}
		}
	}

	int ans = 0;                   // The max value of level is our ans

	while(!q.empty()){
		auto v = q.front();
		int v_x = v.first;
		int v_y = v.second;
		q.pop();
		for(auto movement : movements){
			int child_x = movement.first + v_x;
			int child_y = movement.second + v_y;
			if(!isValid(child_x, child_y)) continue;   // child is out of the matrix
			if(vis[child_x][child_y]) continue;        // child is already visited
			q.push({child_x, child_y});
			lev[child_x][child_y] = lev[v_x][v_y]+1;
			vis[child_x][child_y] = 1;

			ans = max(ans, lev[child_x][child_y]);
		}
	}
	return ans;
}

void reset() {
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			vis[i][j] = 0;
			lev[i][j] = INF;    // generally infinity rakhna better rehta hai
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--){
		cin>>n>>m;
		reset();
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				cin>>val[i][j];
			}
		}
		cout<<bfs()<<endl;
	}

	return 0;
}

