// https://www.codechef.com/problems/FIRESC

// 1st test case: 1---2---3      4
// No of components(no of escape routes for this problem) = 2 and 3*1=3 no of ways a capatin can be selected


// 2nd test case: 1---2          4      5   
//                 \ /
//                  3
// No of components(no of escape routes for this problem) = 3 and 3*1*1=3 no of ways a capatin can be selected


// 3rd test case: 1---2        3---4      5---6              
// No of components(no of escape routes for this problem) = 3 and 2*2*2=8 no of ways a capatin can be selected

// Hence,we need to return no of connected components and product of count of elements in a connected component.


#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int vis[100001];          // 10^5 constraint is given
vector<int> adj[100001];  

int cc_size;              // size(no of nodes) of a connected component

void dfs(int node){
    vis[node] = 1;
    cc_size++;           // each time we reach a new node we increment the no of nodes in the component

    for(int child: adj[node]){
        if(vis[child] == 0){
            dfs(child); 
        }
    }
}

int main(){
    int t,n,m,u,v;
    cin>>t;
    while(t--){
        cin>>n>>m;

        for(int i=1; i<=n; i++) vis[i]=0, adj[i].clear();  // clearing the list and array after every test case.

        for(int i=1; i<=m; i++) cin>>u>>v, adj[u].push_back(v), adj[v].push_back(u);

        int cc = 0;            // count of no of connected components.
        long long int res = 1; // different no of ways in which we can chose group caption

        for(int i=1; i<=n; i++){
            cc_size = 0;
            dfs(i), cc++;

            res = (res * cc_size) % mod;    
        }

        cout<<cc<<" "<<res<<endl;
    }
    return 0;
}













//ALTERNATE CODE
#include<bits/stdc++.h>
 
using namespace std;
 
const int mod = 1e9 + 7;
 
void dfs(vector<vector<int>>& adj, vector<bool>& vis, int s, int& size) {
	vis[s] = 1;
	++size;
	for (int& v : adj[s]) {
		if (!vis[v]) {
			dfs(adj, vis, v, size);
		}
	}
	return;
}
 
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
  	int n, m;
  	cin >> n >> m;
  	vector<vector<int>> adj(n);
  	vector<bool> vis(n, 0);         
  	while (m--) {
  		int u, v;
  		cin >> u >> v;
  		adj[u - 1].emplace_back(v - 1);
  		adj[v - 1].emplace_back(u - 1);
  	}
  	int cc = 0;
  	long long ans = 1LL;
  	for (int i = 0; i < n; ++i) {
  		if (!vis[i]) {
  			int size = 0;
  			++cc;
  			dfs(adj, vis, i, size);
  			ans = ans * size % mod;
  		}
  	}
  	cout << cc << ' ' << ans << '\n';                      	
  }
  return 0;
}
