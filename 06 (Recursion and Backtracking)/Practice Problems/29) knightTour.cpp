https://www.geeksforgeeks.org/the-knights-tour-problem/

https://leetcode.com/problems/check-knight-tour-configuration/description/

class Solution {
public:
// If I can visit all the cells, also keep checking the cell I visit is a value more
     void rec(int i, int j, int n, int m, vector<vector<int>>&grid, vector<vector<int>>&vis, int c){
        if(i<0||i>=n||j<0||j>=m || grid[i][j]!=c || vis[i][j]==1) return;
        
        vis[i][j]=1;
        c++;
        
        int dr[8]={2, 2,-2, -2,-1, 1, -1, 1};
        int dc[8]={1, -1, 1, -1, 2, -2, -2, 2};
        
        for(int l=0; l<8; l++){
            int nr= i+ dr[l];
            int nc= j+ dc[l];
            rec(nr, nc, n, m, grid, vis, c);
        }
    }
    
    
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0) return false;
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        rec(0, 0, n, m, grid, vis, c);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j]==0){
                    return false;
                }
            }
        }
        return true;
    }
};
