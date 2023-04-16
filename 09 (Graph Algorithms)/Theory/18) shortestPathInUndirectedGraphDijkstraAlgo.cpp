https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

https://www.youtube.com/watch?v=EFg3u_E6eHU   (Dijakstra Working Animation)

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

// DIJKSTRA'S ALGORITH
Task: Given a source node find shortest distance between source and every other node

// Dijakstra is similar to BFS only. 
// We will use a priority queue that will store (ditance, node)
// Priority queue should be a min heap, ie the guy with the lower distance will be on top of the priority queue.
// I want to relax further distance with current distances so it will be beneficial to relax using lower distances so I use a PQ.

// The code is for undirected graphs, the same Dijkstra function can be used for directed graphs also.

// In simple BFS agar ek baar visit ho gaya use dobara queue mein nahi dalenge
// But in dijakstra we can put it again in queue or our DS if we can further reduce the distance.


CODE:

vector <int> dijkstra(int V, vector<vector<int>> adj[], int src){
    // Code here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    vector<int> dist(V, 1e9);
    
    dist[src] = 0;
    pq.push({0, src});  // {distance, node that is to be reached from source}
    
    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto &vec: adj[node]){
            int adjNode = vec[0];
            int wt = vec[1];
            
            if(d + wt < dist[adjNode]){  // If I get a better distance for current adjacent node update the distance and store in pq
                dist[adjNode] = d + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

NOTE:
Dijasktra is not applicable for graph with negative weight(fall in an infinite loop), cylce.

TC = ElogV

// Practice Problem
https://leetcode.com/problems/network-delay-time/

Further Points:
Using Queue:
// If the edge weights are same then it is obvious that you can use a queue instead.
// Hence matrix questions where edge weight is constant you can use a queue.
// If you try to submit above code using a queue, it will also get accepted. Just that it will be more in time complexity.

Using Set
// We can also use multiset or set as well which is even faster.
// We used PQ because we wanted minimum distance first.
// Set stores everything in ascending order. 
// Another advantage to set is that it can erase already existing paths which a heap cannot hence saving calculations.
// But erase will take extra logn, while saving some calculations, so it basically depends on the graph what to be used.

// Another imp facility that a set/priorityqueue provides over queue is that, if the destination node reaches on the top, we can early return from there itself.
// Coz that is a minimum value, yeh value ar kam nahi ho skti with the help of other larger values in the queue. See problem 16.

Code using set DS.

vector <int> dijkstra(int V, vector<vector<int>> adj[], int src){
    // Code here
    set<pair<int, int>> st;  

    vector<int> dist(V, 1e9);
    
    dist[src] = 0;
    st.insert({0, src});  // {distance, node that is reached from source}
    
        while(!st.empty()){
        auto it = *(st.begin());
        int d = it.first;
        int node = it.second;
        st.erase(it);
        
        for(auto &vec: adj[node]){
            int adjNode = vec[0];
            int wt = vec[1];
            
            if(d + wt < dist[adjNode]){  // If I get a better distance for current adjacent node
                // erase if it already existed
                if(dist[adjNode]!=1e9){                   // only this is extra from above code.
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = d + wt;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}


Follow Up Question:

Print Shortest Path - Dijkstra's Algorithm

https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?

https://youtu.be/rp1SMw7HSO8  (Striver)

Indexing is 1-based.
I dont need value, I need path.
I will try to remember where I am coming from.
This can be done by using an extra parent array.

So, while traversing I will the parent of a node ie where I came from.
Now traverse from destination go to its parent go to its parent till you reach source (here 1)

CODE:

 vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    // making graph first
    unordered_map<int, vector<pair<int, int>>> adj;
    for(auto &edge: edges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1, 1e9);  // 1-based
    vector<int> par(n+1, 1e9);
    
    for(int i=1; i<=n; ++i){
        par[i]=i;               // Initially mark the parents as indices
    }
    dist[1] = 0;               // mark the distance of the source
    pq.push({0, 1});           // push the source node in the pq {distance, node}
    while(!pq.empty()){
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        for(auto &it: adj[node]){
            int adjNode = it.first;
            int edW = it.second;
            if(d + edW < dist[adjNode]){
                dist[adjNode] = d + edW;
                pq.push({d + edW, adjNode});
                par[adjNode] = node;
            }
        }
    }
    if(dist[n]==1e9) return {-1}; // not able to reach
    vector<int> ans;
    int node = n;
    while(par[node]!=node){
        ans.push_back(node);
        node = par[node];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    return ans;
} 

// TC = E log V , same as dijasktra algo
