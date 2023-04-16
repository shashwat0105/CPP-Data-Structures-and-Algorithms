https://codeforces.com/contest/1245/problem/D

// Medium-Hard
// Minimum Spanning Tree

// I want the cost of the cities ie c1, c2... also get converted into edges so that I can include this too in MST algorithm along with edge costs.

https://youtu.be/pZXatDdVELI   : There is a diagram after 8:00 , refer to that, how we made sure using atleast one ci value along with powering all.
//  It is possible the two installing two power house in 2 different villages could cost less then connecting those villages with connections
//
#include<bits/stdc++.h>
using namespace std;
const int N = 2e3+10;                    // because n is about 2000
int parent[N], sz[N];

void make(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find(int v){
    if(parent[v]==v) return parent[v];
    return parent[v] = find(parent[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(sz[a]<sz[b]){
            swap(a,b);
        }
        parent[b] = a;
        sz[a]+=sz[b];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin>>n; 
    vector<pair<int, int>> cities_coordinates(n+1);

    for(int i=1; i<=n; ++i){
        cin>>cities_coordinates[i].first>> cities_coordinates[i].second;
    }

    vector<int> c(n+1), k(n+1);
    for(int i=1; i<=n; ++i){
        cin>>c[i];
    }
    for(int i=1; i<=n; ++i){
        cin>>k[i];
    }
    
    // there can be n^2 edges, we have assumed an edge to be there from every node to every other node
    // As well as hypothetical edges from 0 node to every city of ci cost.
    vector<pair<long long, pair<int, int>>> edges;
    for(int i=1; i<=n; ++i){
        edges.push_back({c[i], {0, i}});
    }

    for(int i=1; i<=n; ++i){
        for(int j=i+1; j<=n; ++j){
            int dist = abs(cities_coordinates[i].first - cities_coordinates[j].first) + abs(cities_coordinates[i].second - cities_coordinates[j].second);
            long long cost = dist * 1LL * (k[i]+k[j]);  // total cost for this distance
            edges.push_back({cost, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());

    for(int i=1; i<=n; ++i) make(i);

    long long total_cost = 0;
    vector<int> power_stations;          // kin kin cities mein power station laga
    vector<pair<int, int> > connections; // wires kin kin cities mein finally lagi
    for(auto& edge : edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find(u)==find(v)) continue;   // ie their parent is same
        Union(u, v);                     // else we will join them 
        total_cost += wt;
        if(u==0 || v==0) power_stations.push_back(max(u, v)); // ie one of the node is 0, other non zero one is where power station has been made
        else connections.push_back({u, v});

    }
    cout<<total_cost<<endl;
    cout<<power_stations.size()<<endl;
    for(int station: power_stations){
        cout<<station<<" ";
    }
    cout<<endl;

    cout<<connections.size()<<endl;
    for(auto &connection: connections){
        cout<<connection.first<<" "<<connection.second<<endl;
    }
}

