https://leetcode.com/problems/number-of-enclaves/

// Nodes that are connected to boundary will not be our ans.

DFS
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<pair<int,int>> &directions){
        int n = grid.size();                        
        int m = grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0) return;
        
        grid[i][j] = 0;
        
        for(auto &dir: directions){
            int newI = i + dir.first;
            int newJ = j + dir.second;
            dfs(newI, newJ, grid, directions);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> directions {{0,1},{1,0},{0,-1},{-1,0}};

        // I run DFS on nodes that are on the boundary (boundary dfs)
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(i*j==0 || i==n-1 || j==m-1){     
                    if(grid[i][j]==1){
                        dfs(i, j, grid, directions);
                    } 
                }
            }
        }
        // After that I can count the 1s that remain untouched
        int ans = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==1) ans++;
            }
        }
        return ans;
    }
};

BFS 1: (Same as above just traversing using BFS instead of DFS)
class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>& grid){
        queue <pair<int, int>> q;
        vector<pair<int,int>> directions {{0,1},{1,0},{0,-1},{-1,0}};

        int n = grid.size();                        
        int m = grid[0].size();

        grid[i][j]=0;
        q.push({i, j});

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(auto &dir: directions){
                int newI = i + dir.first;
                int newJ = j + dir.second;
                if(newI<0 || newJ<0 || newI>=n || newJ>=m || grid[newI][newJ]==0) continue;
                q.push({newI, newJ});
                grid[newI][newJ]=0;
            }
        }

    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // (boundary bfs)
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(i*j==0 || i==n-1 || j==m-1){     
                    if(grid[i][j]==1){
                        bfs(i, j, grid);
                    } 
                }
            }
        }
        // After that I can count the 1s that remain untouched
        int ans = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==1) ans++;
            }
        }
        return ans;
    }
};

BFS 2: (Multi Source) // Striver
Adding all the boundary nodes(sources) at once in the queue. (Kuch fark ni padega)

class Solution {
public:
    
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>> q; 
        int n = grid.size(); 
        int m = grid[0].size();
        vector<vector<int>>vis(n ,vector<int>(m,0)); 
        // traverse boundary elements
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                // first row, first col, last row, last col 
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    // if it is a land then store it in queue (adding all the sources(multisource))
                    if(grid[i][j] == 1) {
                        q.push({i, j});     
                        vis[i][j] = 1; 
                    }
                }
            }
        }
        
        vector<pair<int,int>> directions {{0,1},{1,0},{0,-1},{-1,0}};

        while(!q.empty()) {
            int i = q.front().first; 
            int j = q.front().second; 
            q.pop(); 

            // traverses all 4 directions
            for(auto &dir: directions){
                int newI = i + dir.first;
                int newJ = j + dir.second;
                if(newI<0 || newJ<0 || newI>=n || newJ>=m || grid[newI][newJ]==0) continue;
                q.push({newI, newJ});
                grid[newI][newJ] = 0;
                vis[newI][newJ] = 1;
            }
        }
        
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                // check for unvisited land cell
                if(grid[i][j] == 1 & vis[i][j] == 0) 
                    cnt++; 
            }
        }
        return cnt; 
    }
};


