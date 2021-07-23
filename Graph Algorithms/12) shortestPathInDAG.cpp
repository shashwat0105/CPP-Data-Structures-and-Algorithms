// In order to store a weighted graph we will use a pair of integers

   2       3       6
0 ----> 1 ----> 2 ----> 3 
 \             ↗        ↑
1 \       2  /          |
   \       /          1 |
     ↘   /              |
       4 -------------> 5
               4

// The numbers in the edge shows the weight.

// Adjacency List
0 -> (1,2)  (4,1)  // 0 is connected to 1 with weight of 2, and with 4 with weight of 1
1 -> (2,3)
2 -> (3,6) 
3 -> 
4 -> (2,2) (5,4)
5 -> (3,1)

// In order to find shortest path we need to first find topological sort.
// Using DFS, stack

void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int,int>> &adj[]){
    vis[node] = 1;                           // whenever we reach the dfs mark it as 1
    for(auto it : adj[node]){                // for all its adjacent nodes
        if(!vis[it.first]){
            findTopoSort(it, first, vism st, adj);
        }
    }
    st.push(node);                           // dfs gets over, put it into the stack
}

void shortestPath(int src, int N, vector<pair<int,int>> adj[]){
    int vis[N]=0;                            // first step is to generate toposort for that we need a visited array
    stack<int> st;
    for(int i=0; i<N; i++){
        if(!vis[i]){
            findTopoSort(i, vis, st, adj);   // calling toposort for every non visited element
        }
    }

    int dist[N];
    for(int i=0; i<N; i++){
        dist[i]=1e9;                         // assigning infinity(very large value) to every element of the distance array
    }
    dist[src]=0;                             // distance of source is 0

    while(!st.empty()){                      // iterating on the stack(created by toposort)
        int node = st.top();
        st.pop();

        if(dist[node]!=INF){                 // ie if the node has been reached previously
            for(auto it : adj[node]){        // traversing for its adjacent nodes
                if(dist[node]+it.second<dist[it.first]){
                    dist[it.first]=dist[node]+it.second;
                }
            }
        }
    }

    for(int i = 0; i < N; i++){
        (dist[i]==1e9)? cout<<"INF": cout<< dist[i]<<" ";  // if the distance is unreachable print infinity, else print the distance
    }
}

int main(){
    int n, m;    
    cin>>n>>m;
    vector<pair<int, int>> adj[n];  // to store the adjacent node as well as edge weight

    for(int i=0; i< m; i++){        // taking input of the graph 
        int u, v, wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v, wt});
    }

    shortestPath(0, n, adj);        // source node is 0

    return 0;
}


