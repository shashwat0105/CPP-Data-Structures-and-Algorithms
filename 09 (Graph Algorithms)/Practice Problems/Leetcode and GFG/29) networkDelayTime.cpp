https://leetcode.com/problems/network-delay-time/

// Dijkstra algorithm is used

class Solution {
public:
    const int N = 1e5+10;
    const int INF = 1e9+10;
    
    int dijkstra(int source, int n, vector<pair<int, int>> g[]){
        vector<int> vis(N, 0);
        vector<int> dist(N, INF);

        set<pair<int, int>> st;   // {wt, node} // will be sorted according to the first value ie weight

        st.insert({0, source});
        dist[source] = 0;

        while(st.size()>0){                               // same as bfs codeflow
            // We will find the minimum element and will go on all its children and see if we can minimise the distance of any of its childeren.
            auto node = *st.begin();
            int v = node.second;
            int v_dist = node.first;
            st.erase(st.begin());
            if(vis[v]) continue;
            vis[v] = 1;                                   // ek baar queue se nikal gyi fr nahi daalna hai
            for(auto child: g[v]){
                int child_v = child.first;
                int wt = child.second;
                if(dist[v] + wt < dist[child_v]){
                    dist[child_v] = dist[v] + wt;
                    st.insert({dist[child_v], child_v});
                    // Yaha pe koi visited nahi kia coz if we can reduce a cost then we can again put it into queue as well in Dijkstra
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=n; ++i){
            if(dist[i]==INF) return -1; // ie distance hasnt changed ie node has not been reached
            ans = max(ans, dist[i]);
        }
        return ans;
    }
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> g[N];              // {node, wt}  // different order from set dont get confused
        for(auto vec: times){
            g[vec[0]].push_back({vec[1], vec[2]});
        }
        return dijkstra(k, n, g);
    }
};

// TC = O(V + ElogV)


// YET TO SEE OTHER YT SOLUTIONS AND LC DISCUSS