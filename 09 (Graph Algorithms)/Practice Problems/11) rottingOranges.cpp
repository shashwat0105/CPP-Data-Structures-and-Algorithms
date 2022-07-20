https://leetcode.com/problems/rotting-oranges/

TC = O(N*N)*4
SC = O(N*N)


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;                     // if the 2D vector is empty
        int m = grid.size();                           // no of rows
        int n = grid[0].size();                        // no of columns
        int days=0, tot=0, cnt=0;                      // days is total no of days ie my ans, total is number of given oranges, cnt is how many have been rottened by me
        queue<pair<int, int>> rotten;                  // store all the rotten oranges
        
        for(int i=0; i<m;++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j]!=0) tot++;               // calculating total no of oranges from given input
                if(grid[i][j]==2) rotten.push({i, j}); // inserting in queue rotten oranges
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!rotten.empty()){                        // till there are no rotten oranges
            int k = rotten.size(); 
            cnt+=k;                                    // count how many are rotten
            while(k--){                                // for every currently present rotten orange I move in all the directions
                int x=rotten.front().first;
                int y=rotten.front().second;
                rotten.pop();
                for(int i=0; i<4; ++i){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny] !=1) continue;  // these check whether the coordinates are out of boundary then skip or it is already rotten or empty
                    grid[nx][ny] = 2;                  // if it is fresh I mark it as rotten 
                    rotten.push({nx, ny});             // and push it in my queue
                }
            }
            if(!rotten.empty()) days++;                // if the queue is still not empty means I have added more oranges this day ie day increases
        }
        return tot==cnt?days:-1;                       // If initial and current are same I return days else I return -1
    }
};