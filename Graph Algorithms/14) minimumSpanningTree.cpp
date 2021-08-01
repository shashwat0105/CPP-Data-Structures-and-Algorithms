// MINIMUM SPANNING TREE (MST)

    2         3
0--------1---------2
|      /  |       /
|6   / 8  |5    / 7
|  /      |   / 
|/        | /  
3         4

When you can convert a graph to a tree such that it contains exactly N nodes and N-1 edges.
And every node should be reacheable by every other node.
  2   3
O---O---O    (5 nodes and 4 edges), Total Cost(Weight) here: 2+3+6+7=18
|       /
|6     / 7
|     /
O    O


  2   3
O---O---O     (5 nodes and 4 edges), Total Cost(Weight) here: 2+3+8+5 =18
   /| 
 8/ |5 
 O  O

O    O     O  (5 nodes and 4 edges), Total Cost(Weight) here: 6+8+5+7 = 26
|   / |   /
|6 /8 |5 /7 
| /   | /
O     O

and so on... among all these spanning trees possible from the above graph, the one having minimum weight is the MST

// PRIMS ALGORITM | MINIMUM SPANNING TREE

// It picks up a node & takes the minimal edge connected to it.

// We will require 3 arrays
// i) Key array - Every index initilised to inifinity except 0th index which is initialised to 0
// ii) MST array - Every index is initialised to False
// iii) Parent array - Every index is initialised to -1

// BRUTE FORCE IMPLEMENTATION:
// TC = O(n^2)  , more than n square
#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, m;                                   // N = No of nodes, m = no of edges
  cin>>N>>m;
  vector<pair<int, int>> adj[N];

  int a,b,wt;
  for(int i=0; i<m; i++){
    cin>>a>>b>>wt;
    adj[a].push_back(make_pair(b,wt));        // taking input of graph in adjacency list
    adj[b].push_back(make_pair(a,wt));
  }

  int parent[N];
  int key[N];
  bool mstSet[N];

  for(int i = 0; i < N; i++)
    key[i] = INT_MAX, mstSet[i] = false, parent[i] = -1;   // Initially: key array marked with infinity, mst array marked with false & parent array marked with -1

  key[0] = 0;                                 // 0th index marked as 0
  parent[0] = -1;

  // We kept on finding the minimal in the key array for that iterate through its adjacent and keep on updating the key as well as parent 
  for(int count = 0; count < N-1; count++){   // we know we will have N-1 edges in our minimum spanning tree so we iterate till N-1
    int mini = INT_MAX, u;

    for(int v=0; v<N; v++){
      if(mstSet[v]==false && key[v]<mini){    // if the value is not part of mst and is less than mini  
        mini = key[v], u=v;
      }
    }
    mstSet[u] = true;                         // and mark it as true

    for(auto it : adj[u]){                    // iterate for all its adjacent nodes
      int v = it.first();
      int weight = it.second();
      if(mstSet[v]==false && weight<key[v])
        parent[v] = u, key[v] = weight;       // updating the key and parent
    }
  }

  for(int i = 0; i < N; i++){
    cout<<parent[i]<<" - "<<i<<" \n";
  }
  return 0;
}


// OPTIMISED METHOD
// To optimise it, we use a data structure which helps to find minimal : a heap data structure(priority queue in C++)

#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	
	int parent[N]; 
      
  int key[N]; 
      
  bool mstSet[N]; 
  
  for (int i = 0; i < N; i++) 
      key[i] = INT_MAX, mstSet[i] = false; 
    
  priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

  key[0] = 0; 
  parent[0] = -1; 
  pq.push({0, 0});
    // Run the loop till all the nodes have been visited
    // because in the brute code we checked for mstSet[node] == false while computing the minimum
    // but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
    // hence its better to keep running till all the nodes have been taken. 
    // try the following case: 
    // Credits: Srejan Bera
    // 6 7 
    // 0 1 5 
    // 0 2 10 
    // 0 3 100 
    // 1 3 50 
    // 1 4 200
    // 3 4 250
    // 4 5 50 
  while(!pq.empty())
  { 
      int u = pq.top().second; 
      pq.pop(); 
      
      mstSet[u] = true; 
      
      for (auto it : adj[u]) {
          int v = it.first;
          int weight = it.second;
          if (mstSet[v] == false && weight < key[v]) {
              parent[v] = u;
              key[v] = weight; 
              pq.push({key[v], v});    
          }
      }
          
  } 
    
  for (int i = 1; i < N; i++) 
      cout << parent[i] << " - " << i <<" \n";

	return 0;
}

