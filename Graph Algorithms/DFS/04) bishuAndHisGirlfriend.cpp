// https://assessment.hackerearth.com/challenges/college/nits-local-10/algorithm/84888e824aa04fc793c3beefca02b5a7/

//     1  
//    /  \  \
//   2   3   4
//  / \ 
// 5   6

// Girls live in city 3,4,5,6 so we chose 3 and 4 as min and 3 as ans as min country numbering.

// This problem can be done by bfs and dfs both.

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];     // adjacency list , according to constraints
int vis[1001], dist[1001]; // visited and distance array

void dfs(int node, int d){
    vis[node] = 1;
    dist[node] = d;
    for(auto it: adj[node]){
        if(vis[it]==0){
            dfs(it, dist[node]+1);
        }
    }
}

int main(){
    int n, q, u, v;  // n = no of nodes(countries), q = no of girls, u and v denotes the edges

    cin>>n;
    for(int i=0; i<n-1; i++){
        cin>>u>>v, adj[u].push_back(v), adj[v].push_back(u);
    }

    dfs(1, 0);  // coz we want to find distance from 1

    int ans = -1, min_dist = INT_MAX;
    cin>>q;
    while(q--){
        int girl_city;
        cin>>girl_city;

        if(dist[girl_city]< min_dist)
            min_dist = dist[girl_city], ans = girl_city;

        else if(dist[girl_city] == min_dist && girl_city<ans)  // ie if any two cities have same distance and the now found index is lesser
            ans = girl_city;
    }

    cout<<ans;
    return 0;
}



// TO UNDERSTAND BELOW LATER BY BFS METHOD
#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
vector<vector<int>>v(n+1);
vector<int>l(n+1,0);
vector<bool>b(n+1,false);
for(int i=0;i<n-1;i++){
int a,b;
cin>>a>>b;
v[a].push_back(b);
v[b].push_back(a);
}
queue<int>d;
d.push(1);
l[1]=0;
b[1]=true;
while(!d.empty()){
int s=d.front();
d.pop();
for(int j=0;j<v[s].size();j++)
{if(b[v[s][j]]==false){l[v[s][j]]=l[s]+1;b[v[s][j]]=true;
d.push(v[s][j]);}}
}
int q,m=1000;
cin>>q;map<int,int>mp;
for(int i=0;i<q;i++)
{ int c;cin>>c;
mp[c]=l[c];
m=min(m,l[c]);
}int p=19999;
for(auto k:mp)
if(k.second==m)p=min(p,k.first);
cout<<p;
return 0;

}

