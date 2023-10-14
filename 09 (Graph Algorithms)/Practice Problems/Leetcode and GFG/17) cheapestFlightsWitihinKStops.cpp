https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

Either you store the level or steps of a node in the DS itself(Striver) or do a level order traversal(by finding size of the queue)(MIK)
STRIVER:
https://youtu.be/9XybHVqTHcQ

Someone can take smaller cost but cannot further move ahead, simple dijakstra wont allow to update it.
Whereas, other path tho takes larger cost can reach the destination. So, I will not just compare distance but also stops.
The stops are increasing by +1 hence you dont need a pq(adds extra log thing), a simple queue will suffice.
Whenever we reach the destination, we dont stop as we can get same destination at better cost thro a diff path.

CODE:

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // making the graph
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto &vec: flights){
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];
            adj[u].push_back({v, cost});
        }
          
        queue<pair<int, pair<int, int>>> q; // {stops, node, cost}
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while(!q.empty()){
            auto it = q.front();
            int stops = it.first;
            int node = it.second.first;
            int d = it.second.second;
            q.pop();
            if(stops>k) continue;
            for(auto &iter: adj[node]){
                int adjNode = iter.first;
                int cost = iter.second;
                if(d+cost < dist[adjNode] && stops <= k){  
                    dist[adjNode] = d+cost;
                    q.push({stops+1, {adjNode, d+cost}});
                }
            }
        }
        return dist[dst]==1e9? -1 : dist[dst];
    }
};

*********************
MIK:

// For other approaches
// https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Cheapest%20Flights%20Within%20K%20Stops.cpp
// https://youtu.be/VmUpydhNmuw (Code story with MIK)

// We have to explore all the paths and won't return even if we reach the target once.
// Visited nahi use karenge coz for better path we will visit it again.
// BFS | BellmanFord | Dijasktra

"Dijakstra Algo"

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n, 1e9);
        // making the graph
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto &vec: flights){
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];
            adj[u].push_back({v, cost});
        }

        // BFS
        queue<pair<int, int>> q;
        q.push({src, 0});  // source se source tak ka cost is 0
        distance[src]=0;
        int steps = 0;
        while(!q.empty() && steps<=k){
            int N = q.size();   // to process all the nodes of current level
            
            while(N--){
                int u = q.front().first;
                int d = q.front().second;
                q.pop();

                for(pair<int, int> &P: adj[u]){
                    int v = P.first;
                    int cost = P.second;
                    // is v mein apan u se aye hai
                    if(distance[v] > d+cost){
                        distance[v] = d+cost;
                        q.push({v, d+cost}); // I want to explore this path qki yeh mujhe sasta lag raha hai
                    }     
                }
            }
            steps++;
        }
        return distance[dst]==1e9 ? -1 : distance[dst];
    }
};

