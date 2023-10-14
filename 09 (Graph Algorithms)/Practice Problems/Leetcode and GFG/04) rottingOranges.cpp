https://leetcode.com/problems/rotting-oranges/

Good 

TC = O(N*N)*4
SC = O(N*N)

There can be more than 1 rotten oranges in the beginning itself.
Multi Source BFS (Aage chal k bhi kai source hote hi hai, yaha starting m hi hai)
We'll start the BFS at all rotten oranges(i.e. push all the (i , j) pairs of rotten oranges initially in the Queue).

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
                if(grid[i][j]==2) rotten.push({i, j}); // inserting in queue all the rotten oranges in the beginning.
            }
        }
        
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while(!rotten.empty()){                         // till there are no rotten oranges
            int sz = rotten.size();                     // because we want to cover all neighbours of a node at once which are affected in a particular time frame 
            cnt+=sz;                                    // count how many are rotten
            while(sz--){                                // for every currently present rotten orange I move in all the directions // for(int i=0; i<sz; ++i)
                int x=rotten.front().first;
                int y=rotten.front().second;
                rotten.pop();
                for(auto &dir: directions){
                    int nx = x + dir.first;
                    int ny = y + dir.second;
                    if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny] !=1) continue;  // these check whether the coordinates are out of boundary then skip or it is already rotten or empty
                    grid[nx][ny] = 2;                  // if it is fresh I mark it as rotten 
                    rotten.push({nx, ny});             // and push it in my queue
                }
            }
            if(!rotten.empty()) days++;                // if the queue is still not empty means I have added more oranges this day ie day increases
        }                                              // First level 1 nodes will be processed then level 2 and so on.
        return tot==cnt?days:-1;                       // If initial and current are same I return days else I return -1
    }
};

By striver:
He stored time along with row, col in queue.
https://takeuforward.org/data-structure/rotten-oranges/
