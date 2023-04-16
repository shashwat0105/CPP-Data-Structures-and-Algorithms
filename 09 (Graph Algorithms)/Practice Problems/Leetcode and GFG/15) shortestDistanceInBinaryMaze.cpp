https://youtu.be/U5Mw4eyUmw4 (STRIVER)

Ques based on Dijasktra Algo ie BFS
We used priority queue, and a distance array(here we will take 2D distance array)
Since the cost is same, we can take just a queue instead of pq. // first the level cost will be 1 1 1 1 then 2 2 2 then 3 3 3

https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?

When not given cell to cell cost is taken 1.
You can move in 4-directions, path consist of 1;s

CODE:
int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
    if (source.first == destination.first && source.second == destination.second) return 0;

    queue<pair<int, pair<int, int>>> q; // {dist, {cell coordinates pair}}.
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[source.first][source.second] = 0;
    q.push({0, {source.first, source.second}});

    vector<pair<int,int>> directions {{0,1},{1,0},{0,-1},{-1,0}};


    // Iterate through the maze by popping the elements out of the queue and pushing whenever a shorter distance to a cell is found.
    while (!q.empty()){
        auto it = q.front();
        q.pop();
        int d = it.first;
        int r = it.second.first;
        int c = it.second.second;

        // Through this loop, we check the 4 direction adjacent nodes for a shorter path to destination.
        for(auto &dir: directions){
            int newr = r + dir.first;
            int newc = c + dir.second;

            if (r == destination.first && c == destination.second) return d; // Return the distance until the point when we encounter the destination cell.

            // Checking the validity of the cell and updating if dist is shorter.
            if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && d + 1 < dist[newr][newc]){
                dist[newr][newc] = 1 + d;
                q.push({1 + d, {newr, newc}});
            }
        }
    }
    // If no path is found from source to destination.
    return -1;
}


https://leetcode.com/problems/shortest-path-in-binary-matrix/

Source is (0, 0)
Destination is (n-1, n-1)

Can move in 8 directions, path consists of 0 s

CODE:
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

        if (n==1) return 1;                 // If source and destination are same
        queue<pair<int, pair<int, int>>> q; // {dist, {cell coordinates pair}}.

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;                     // I mark 1 // coz ek path m cells kitne hai wo batana hai
        q.push({1, {0, 0}});

        vector<pair<int,int>> directions {{0,1},{1,0},{0,-1},{-1,0}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};

        while (!q.empty()){
            auto it = q.front();
            q.pop();
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if(r==n-1 && c==n-1) return d;

            for(auto &dir: directions){  // traverse in 8 directions
                int newr = r + dir.first;
                int newc = c + dir.second;

                if (newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 0 && d + 1 < dist[newr][newc]){
                    dist[newr][newc] = 1 + d;
                    q.push({1 + d, {newr, newc}});
                }
            }
        }
        return -1;
    }
};

// You can also chose to directly return at the end as well instead of early return.

//
DP wont work as the value on any cell is path-dependent, so it wont work.
It works in the maze which has two direction movements in the right and bottom, and the future cells would never be visited. 
Think about it by taking some examples. 
