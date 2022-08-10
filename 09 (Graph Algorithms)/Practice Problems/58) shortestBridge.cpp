https://leetcode.com/problems/shortest-bridge/

// Not very efficient, but gets accepted. (Uses past learnt concept)
// We will use flood fill algorithm to find all the coordinates of the two islands.
// Store them in two different vectors. 
// And find the minimum distance between any of the two coordinates.
// This will be the min number of zeroes that will be required to be flipped.

class Solution {
public:
    void flood_fill_dfs(vector<vector<int>>& A, int i, int j, vector<pair<int, int>> &r){
        if(i<0 || j<0 || i>=A.size() || j>=A[0  ].size() || A[i][j]==0) return;
        
        A[i][j] = 0;
        r.push_back({i, j});
        
        flood_fill_dfs(A, i+1, j, r);
        flood_fill_dfs(A, i-1, j, r);
        flood_fill_dfs(A, i, j+1, r);
        flood_fill_dfs(A, i, j-1, r);
        return;
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        vector<pair<int, int>> x;
        vector<pair<int, int>> y;
        
        int count=0;                 // will tell me whether I am in first Island or second Island
        for(int i=0; i<A.size(); ++i){
            for(int j=0; j<A[0].size(); ++j){
                if(A[i][j]==1){
                    count++;
                    if(count==1){
                        flood_fill_dfs(A, i, j, x);
                    }
                    else if(count==2){
                        flood_fill_dfs(A, i, j, y);
                    }
                }
            }
        }
        
        // finding the min distance
        int min_dist = INT_MAX;
        for(int i=0; i<x.size(); ++i){
            for(int j=0; j<y.size(); ++j){
                int dist = abs(x[i].first - y[j].first) + abs(x[i].second - y[j].second) - 1;
                if(dist<min_dist)
                    min_dist = dist;
            }
        }
        return min_dist;
    }
};

//
Efficient Solution
https://leetcode.com/problems/shortest-bridge/discuss/?currentPage=1&orderBy=most_votes&query=

// Maybe the concept of multisource BFS is used.

find any 1's from the first grid
traverse on the first grid to enqueue all 1's
apply multi-BFS from the first grid until reaching any 1's of the second grid
Time complexity = O(N), where N->total cells in grid

https://leetcode.com/problems/shortest-bridge/discuss/1826013/Intuitive-Approach%3A-Multi-BFS-C%2B%2B-90-faster

