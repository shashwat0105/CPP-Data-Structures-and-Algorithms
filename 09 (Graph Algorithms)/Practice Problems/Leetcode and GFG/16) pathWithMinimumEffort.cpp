https://leetcode.com/problems/path-with-minimum-effort/

https://youtu.be/0ytpZyiZFhA

Algorithm that comes to mind source to destination: minimum...
"Dijasktra Algorithm"

Initial configuration of Dijakstra is Priority queue(can use set DS as well) and Distance array.
In distance 2D we will store the effor to reach there.

CODE 1 (Faster, accepted):
With early return. 
Priority queue/set(cannot use just queue) gives smallest value on top, if that smallest value is destination then that has to be the ans because, 
you cannot further reduce the value by using other bigger values present in the DS.

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        int n = heights.size();
        int m = heights[0].size();

        // Create a distance matrix with initially all the cells marked as // unvisited and the dist for source cell (0,0) as 0.
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});  // {diff, {coordinate}}  // diff is effort

        vector<pair<int,int>> directions {{0,1},{1,0},{0,-1},{-1,0}};

        // Iterate through the matrix by popping the elements out of the queue and pushing whenever a shorter distance to a cell is found.
        while (!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // Early return, ie if the top of the pq is destination then this has to be minimum guy.
            
            if (r == n - 1 && c == m - 1) return diff;
           
            for (auto &dir: directions){
                
                int newr = r + dir.first;
                int newc = c + dir.second;

                // Checking validity of the cell.
                if (newr >= 0 && newc >= 0 && newr < n && newc < m){
                    // Effort can be calculated as the max value of differences  // between the heights of the node and its adjacent nodes.
                    int newEffort = max(abs(heights[r][c] - heights[newr][newc]), diff);

                    // If the calculated effort is less than the prev value // we update as we need the min effort.
                    if (newEffort < dist[newr][newc]){
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }
        return 0; 
    }
};

// CODE 2 (Slower, accepted):
Without early return, ie compute till the DS is not empty, and return the value from the distance matrix.
In above code, since early return facility is possible with PQ/set cannot use queue, in below code, you can replace pq with a queue as well(tho it will be even slower)

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});  // {diff, {coordinate}}  // diff is effort

        vector<pair<int,int>> directions {{0,1},{1,0},{0,-1},{-1,0}};

        while (!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
           
            for (auto &dir: directions){
                
                int newr = r + dir.first;
                int newc = c + dir.second;

                // Checking validity of the cell.
                if (newr >= 0 && newc >= 0 && newr < n && newc < m){
                    int newEffort = max(abs(heights[r][c] - heights[newr][newc]), diff);

                    if (newEffort < dist[newr][newc]){
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }   
        return dist[n-1][m-1];     // directly returing at the end.
    }
};
