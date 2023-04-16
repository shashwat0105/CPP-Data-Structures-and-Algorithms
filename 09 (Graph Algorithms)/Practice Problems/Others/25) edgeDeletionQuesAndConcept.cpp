https://youtu.be/NzEzJ6Rmv2Q

https://www.interviewbit.com/problems/delete-edge/

// We will use precomputation
// Ie we will precompute the subtree sum

// Now, if we delete an edge, we know sum of one subtree from that cut node and other subtree sum we can get from
// total tree sum stored in root 1 and this subtree sum ka difference


const int M = 1e9+7;

void dfs(int vertex, int par, vector<int> g[], vector<int> &subtree_sum, vector<int> &val){
    // Take action on vertex ofter entering the vertex
    subtree_sum[vertex] += val[vertex-1]; // 1 node ki value 0 index pe hai 
    
    for(int child: g[vertex]){
        if(child==par) continue;
        dfs(child, vertex, g, subtree_sum, val);
        // Take action on child node after exiting the child node
        subtree_sum[vertex] += subtree_sum[child];
    }
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    vector<int> g[A.size()+1];
    vector<int> subtree_sum(A.size()+1, 0);
    
    for(auto edge: B){
        g[edge[0]].push_back(edge[1]);   // say, edge = [1,2], edge[0] = 1, edge[1] = 2, g[1].push_back(2);
        g[edge[1]].push_back(edge[0]);
    }
    
    dfs(1, 0, g, subtree_sum, A);        // calling dfs from root node 1
    long long ans=0;
    for(int i=2; i<=A.size(); ++i){      // we will break the edge apart from edge above root node as there is no such edge
        int part1 = subtree_sum[i];
        int part2 = subtree_sum[1] - part1;  // ie total sum of tree - sum of one part
        ans = max(ans, (part1 * 1LL * part2) % M);
    }
    return ans;
}


// 
// Logic is of precomputation to obtain ans of 1 part
// Ques can be modified to find the product of prime numbers etc
