// PRIMS ALGORITM | MINIMUM SPANNING TREE
// It picks up a node & takes the minimal edge connected to it. works greedily.

https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?
https://youtu.be/mJcZjjKzeqk (Striver)

Striver method:
Required data structures
1. Min heap
2. Visited array
3. Mst list that will store all the edges that are a part of MST

Datatypes of our data structures
Visited array => int
Mst list =>  (weight,node name, node parent)  // If u want to print MST

Steps
1. Mark the visited array as 0 for all the nodes
2. Start with 0th node and push
(0,0,-1)
here -1 means 0 is the genesis node
Mark 0 as visited
3. Push all the neighbours of 0 in pq Do not mark them visited
Since its a min heap the edge with minimum weight will be at the top
4. Pick up that edge , insert it in the mst , mark the picked node as visited , insert all neighbours of picked node into pq

TC = ElogE
// If only sum is asked then no need to store the parent, else if asks to print MST then need to store the parent.

** CODE for only sum asked: **

int spanningTree(int V, vector<vector<int>> adj[]){
    // code here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);
    pq.push({0, 0});
    int sum = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        
        if(vis[node]==1) continue;
        // add it to MST only then I mark it as visited, sbse choti edge weight wale ko hi nikal k visited mark. BRIENS
        vis[node]=1;
        sum+=wt;
        for(auto &it: adj[node]){
            int adjNode = it[0];
            int edW = it[1];
            if(!vis[adjNode]){
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;
}

** CODE for sum and also asked to print **

int spanningTree(int V, vector<vector<int>> adj[]){
        // code here
    vector<int> vis(V,0);
    vector<pair<int,int>> mst;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{0,-1}});  // { wt, node, parent}
    
    int sum=0;
    while(pq.size()){
        int dis = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();
        
        if(vis[node])continue;            
        if(parent!= -1) mst.push_back({node,parent});
        vis[node] = 1;
        sum += dis;
        for(auto it : adj[node]){
            int adjNode = it[0];
            int edgeW = it[1];
            
            if(!vis[adjNode]){
                pq.push({edgeW,{adjNode,node}});
            }
        }
    }
    // printing mst
    // for(auto it : mst){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }

    return sum;
}
