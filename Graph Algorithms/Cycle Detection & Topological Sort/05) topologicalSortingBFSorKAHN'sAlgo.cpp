// 5 → 0 ← 4
// ↓       ↓
// 2 → 3 → 1

// 5 4 0 2 3 1 is one of the toposort

// Indegree of a node is no of edges directed towards it.
// Indegree for 0 is 2, 1 is 2, 3 is 1, 4 is 0, 5 is 0

// We will use queue(FIFO) data structure here  

// 4 and 5 have indegree as 0, so we push them firs in our queue data structure

// Also known as KAHN's Algorithm

class Solution{
    public:
    vector<int> topoSort(int N, vector<int> adj[]){ // a function toposort which will return a vector, passing no of nodes and graph stored in adjacency list
        queue<int>q;                      // define queue
        vector<int> indegree(N, 0);       // indegree array of size N and all values as 0
        for(int i=0; i<N; i++){           // graph has 0 based indexing so we run a loop from 0 to N
            for(auto it : adj[node]){     // for every adjacent node
                indegree[it]++;           // why it is adjacent node coz there is a node incoming to that adjacent node, so for every adjacent node we increase the indegree count
            }
        }
        for(int i=0; i<N; i++){
            if(indegree[i]==0){          // basically insert all the nodes to the queue having indegree = 0 
                q.push(i);
            }
        }

        vector<int> topo;                // declare topo vector
        while(!q.empty()){               // run the bfs algo till the queue is not empty
            int node = q.front();        // whatever is in the front of the queue assign it node  
            q.pop();                     // then delete that element from the queue
            topo.push_back(node);        // and add that element/node to topo sort
            for(auto it : adj[node]){    // traverse for all its adjacent nodes
                indegree[it]--;         
                if(indegree[it]==0){     // on reducing indegree if reaches 0, push it to queue
                    q.push(it);
                }
            }
        }
    return topo;
    }
    
};


//***********************************************************************
// https://youtu.be/7CTpoVNIc8o
// In each iteration we chose a node which has 0 in degree(no of edges towards a node)
// ie the nodes which have all its dependencies already traversed or have no dependencies.
 
// Topological sort is possible for only DAG (Directed Acyclic Graph) doesn;t contain any cycle
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];     
vector<int> res;                   // array to store the resultant order of toposort
int in[100];                       // array to keep the in degree of each node

void kahn(int n){
    queue<int> q;                  // create a queue to store all the nodes having in degree 0
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);             // now the queue contains the nodes having indegree 0
        }
    }

    while(!q.empty()){
        int curr = q.front();
        res.push_back(curr);       // we also push it into our result

        q.pop();                   // and we remove this node from the queue

        for(int node: adj[curr]){  // for each node in the adjacency list of current node
            in[node]--;            // we decrease its in degree as we removed its parent (edge removal process)
            if(in[node]==0){       // and if it becomes 0 we will add it into our queue
                q.push(node);
            }
        }
    }

    cout<<"Topological Sort : ";
    for(int node : res){
        cout<<node<<" ";
    }
}

int main(){
    int n,m,u,v;
    cin>>n>>m;
    
    while(m--){
        cin>>u>>v;
        adj[u].push_back(v);       // this will be a directed graph u -> v
        in[v]++;                   // Jisko push kar rhe hai ie say 3 -> 4, we push 4 into adj[3] ie in degree of 4 will increase
    }

    kahn(n);

    return 0;
}
