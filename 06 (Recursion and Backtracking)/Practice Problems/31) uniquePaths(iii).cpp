https://leetcode.com/problems/unique-paths-iii/

https://youtu.be/eagGLroZXMk

Along with counting number of ways from source to target
We have to check that we have covered all the non obstacles points ie keeping their count as well.

Find number of non obstacles points.
Find the starting point.

class Solution {
public:
    int m, n;
    int res=0;
    int nonObsCnt;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void backTrack(vector<vector<int>>& grid, int cnt, int i, int j){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]== -1) return; // out of bound, visited  na ho
        
        if(grid[i][j]==2){
            if(cnt == nonObsCnt) res++;  // found one of the way
            return;
        }

        grid[i][j] = -1; // mark as visited 

        for(vector<int> &dir: directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            backTrack(grid, cnt+1, new_i, new_j);
        }

        grid[i][j] = 0;  // unmark to 0
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        res = 0;
        nonObsCnt = 0;

        int start_x = 0, start_y = 0;

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j]==0) nonObsCnt++;
                if(grid[i][j]==1){
                    start_x = i;
                    start_y = j;
                }
            }
        }
        nonObsCnt+=1; // apart from 0, 1 is also non obstacle

        int cnt = 0;

        backTrack(grid, cnt, start_x, start_y);
        return res;
    }
};
