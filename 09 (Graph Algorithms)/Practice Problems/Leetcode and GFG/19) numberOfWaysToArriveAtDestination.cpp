https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

Incorrect intuition: No of times I can reach destination with the shortest path.
Because a path reaching can be composed of two different past paths.
If I get to a node with same cost again, then it is one more path, so I dont insert into PQ, I just increase its ways counter.
https://youtu.be/_-0mx0SmYxA?t=300  (Striver)
  
CODE:

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        unordered_map<long long, vector<pair<long long, long long>>> adj;        
        // make graph
        for(auto edge: roads){
            long long u = edge[0];
            long long v = edge[1];
            long long wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<long long> ways(n, 0);
        vector<long long> dist(n, LLONG_MAX);
        ways[0] = 1;
        dist[0] = 0;

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;        
        pq.push({0, 0}); // {dist, node}

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long d = it.first;
            long long node = it.second;
            for(auto &iter: adj[node]){
                long long adjNode = iter.first;
                long long edW = iter.second;
                if(edW > dist[adjNode]) continue;  // Just an extra optimisation
                if(d+edW < dist[adjNode]){   // This is the first time we’re coming with this particular shorter distance, so we push in PQ and keep the no. of ways the same.
                    dist[adjNode] = d + edW;
                    pq.push({d+edW, adjNode});
                    ways[adjNode] = ways[node]%mod;
                }
                else if(d+edW == dist[adjNode]){   // If we again encounter a node with the same short distance as before, we simply increment the no. of ways.
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};
