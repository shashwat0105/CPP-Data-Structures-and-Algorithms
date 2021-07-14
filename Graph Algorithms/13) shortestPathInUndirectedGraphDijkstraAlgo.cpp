// DIJKSTRA'S ALGORITH
        2                5
1-----------------2-------------5
|                 |             |
| 1               | 4           |  1
|                 |             |
4-----------------3------------/  
        3
 
// Adjcency list
1 -> (2,2) (4,1)
2 -> (1,2) (3,4) (5,5)
3 -> (2,4) (4,3) (5,1) 
4 -> (1,1) (3,3)
5 -> (2,5) (3,1)

// Source node is 1
// To find shortest distance between 1 and every other node
// We will have priority queue which will store (ditance,node)

// Priority queue should be a min heap, ie the guy with the lower distance should be on top of the priority queue.

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, source;
    cin>>n>>m;
    vector<pair<int, int>> g[n+1];         // 1-indexed adjacency list 

    int a,b,wt;
    for(int i=0; i<m; i++){
        cin>>a>>b>>wt;
        g[a].push_back(make_pair(b,wt));   // storing weighted graphs
        g[b].push_back(make_pair(a,wt));
    }

    cin>>source;
    
    // Dijkstra begins: 
    priority_queue<int, int>, vector<pair<int, int>>, greater<pair<int, int>> pq; // min heap priority queue, In pair -> (dist, from)
    vector<int> dist(n+1, INT_MAX);        // distance array, 1 based index and marked with infinity

    dist[source] = 0;                      // distance from source to source is 0
    pq.push(make_pair(0,source));          // (distance, from)

    while(!pq.empty()){                    // traverse till the queue is not empty
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        vector<pair<int, int>> :: iterator it;
        for(it = g[prev].begin(); it!=g[prev].end(); it++){  // can use this as well -> auto it: g[prev] then we would do it.first and it.second ; iterator way or for each loop. 
            int next = it->first;
            int nextDist = it->second;
            if(dist[next] > dist[prev] + nextDist){
                dist[next] = dist[prev] + nextDist;
                pq.push(make_pair(dist[next], next));       // (distance, node)
            }
        }
    }

    cout<<"The distance from the source, "<<source<<", are: \n";
    for(int i=1; i<=n; i++) cout<< dist[i]<<" "<<endl;

    return 0;   

}







