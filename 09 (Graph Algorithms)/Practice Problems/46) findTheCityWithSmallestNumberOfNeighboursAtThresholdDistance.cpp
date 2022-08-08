https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

Read the hints:
1) Use Floyd-Warshalls algorithm to compute any-point to any-point distances. (Or can also do Dijkstra from every node due to the weights are non-negative).
2) For each city calculate the number of reachable cities within the threshold, then search for the optimal city.

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));  // Initilising all matrix values with infinity
        
        for(int i=0; i<n; ++i) dist[i][i] = 0;  // Diagonal elements value is 0 (Distance of a city from the same city is 0)
        
        // Inputing the given weights in our distance matrix
        for(auto v: edges){
            dist[v[0]][v[1]] = v[2];
            dist[v[1]][v[0]] = v[2];
        }
        
        // Floyd warshal algo
        // TC = O(N^3)
        for(int k=0; k<n; ++k){           // pivot
            for(int i=0; i<n; ++i){
                for(int j=0; j<n; ++j){
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][k]+dist[k][j]<dist[i][j]){
                        dist[i][j] = dist[i][k]+dist[k][j];
                    }
                }
            }
        }
        
        // Ab bas jo matrix bani usse esi cities nikal li jo threshold se kam ar hai uski index kya hai
        int cityLessThresholdCount;
        int ans;
        for(int i=0; i<n; ++i){
            int count = 0; // current count in the row
            for(int j=0; j<n; ++j){
                if(i!=j && dist[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count<=cityLessThresholdCount){
                ans = i;
                cityLessThresholdCount = count;  // esi city mil gyi jisme usse bhi kam cities thi jo threshold se kam thi
            }
            
        }
        return ans;
    }
};
