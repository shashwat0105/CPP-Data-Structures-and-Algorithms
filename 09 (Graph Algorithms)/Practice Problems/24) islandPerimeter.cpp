https://leetcode.com/problems/island-perimeter/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[i].size(); ++j){
                if(grid[i][j]==1){                 // start se chalna start kia jaha 1 mila waha se DFS call kar dia
                    dfs(grid, i, j, perimeter);
                    break;                         // because there is only 1 connected component
                }
            }
        }
        return perimeter;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int &perimeter){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size() || grid[i][j]==0){   // will touch water in these condition ie grid k bahar aa jae ya 0 mil jae
            perimeter++;
            return;
        }
        if(grid[i][j]==-1) return;
        
        grid[i][j] = -1;                // making the cell as visited
        
        dfs(grid, i+1, j, perimeter);
        dfs(grid, i-1, j, perimeter);
        dfs(grid, i, j+1, perimeter);
        dfs(grid, i, j-1, perimeter);
    }
};


// Method 2: Without DFS
// Adding 4 to the result and eliminating the sides having neighbours as land one by one.
// Simple traversing in the matrix 
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();    // row
        int m = grid[0].size(); // column
        int ans = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==1){
                    ans+=4;
                    if(i+1<n && grid[i+1][j]==1) ans--;  // down neighbour exists
                    if(i-1>=0 && grid[i-1][j]==1) ans--; // up neighbour exists
                    if(j+1<m && grid[i][j+1]==1) ans--;  // right neighbour exists
                    if(j-1>=0 && grid[i][j-1]==1) ans--; // left neighbour exists
                }
            }
        }
        return ans;
    }
};
