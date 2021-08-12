// https://www.spoj.com/problems/TOPOSORT/

// If there are more than 1 orders, we have to print in lexicographically smaller order.
// For ex: 1,8,7 have 0 in degree, normal kahn will take any random among these. 
// But here we have to chose min ie 1, so instead of having a simple queue we will use a priority min queue.
// In Min heap, top of the heap will contain min element.

// If there is no node which has 0 indegree then toposort is not possible.
// ie the size of the result array should be equal to total no of nodes ie n


#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10001];
vector<int> res;
int in[10001];

bool kahns(int n){
    // priority_queue<int>Q; // this will create a max priority queue(top element will be max)
    // So, instead we declare a priority queue with 3 parameters
    priority_queue<int, vector<int>, greater<int>> pq;   // 1st = type of value we want to store, 2nd = vector of the value, 3rd = greater of the value, will create a min heap(top will contain min element)

    // Rest code will be same as normal Kahn's algo
    for(int i=1; i<=n; i++){
        if(in[i]==0)
            pq.push(i);
    }

    while(!pq.empty()){
        int curr = pq.top();
        res.push_back(curr);
        pq.pop();

        for(int child: adj[curr]){
            in[child]--;
            if(in[child]==0){
                pq.push(child);
            }
        }
    }
    return res.size() == n;                              // if topo sort is possible it will return true

}

int main(){
    int n,m,u,v;
    cin>>n>>m;

    while(m--){
        cin>>u>>v;
        adj[u].push_back(v);
        in[v]++;
    }

    if(!kahns(n)){
        cout<<"Sandro fails.";
    }
    else{
        for(int node: res)
            cout<<node<<" ";
    }
    
    return 0;
}
