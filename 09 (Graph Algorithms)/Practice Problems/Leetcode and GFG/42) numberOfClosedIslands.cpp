https://leetcode.com/problems/number-of-closed-islands/

// The boundary 0's are of no use we have to not consider islands formed with them.
// How will be do that?
// BOUNDARY DFS CONCEPT!!
// By making boundary and all connecting cells = 1 using DFS call on boundary elements only(CRUX)
// Using 2nd DFS call on whole grid to calculate connected components.

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid){
        int n = grid.size();                        // you can also pass n and m (int n, int m) if you don't want to calculate again.
        int m = grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m) return;
        if(grid[i][j]==1) return;
        
        grid[i][j] = 1;
        
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // boundary dfs 
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(i==0 || j==0 || i==n-1 || j==m-1){     // can also write i*j==0 
                    if(grid[i][j]==0){
                        dfs(i, j, grid);
                    } 
                }
            }
        }
        int cc = 0;
        // second dfs on whole grid
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==0){
                    cc++;
                    dfs(i, j, grid);
                } 
            }
        }
        return cc;
    }
};


// writing dfs using dx and dy
bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid){
    return (i>=0 && j>=0 && i<n && j<m && grid[i][j]==0);            // jaha apan ja rahe hai wo land hona chahiye ie grid[i][j] = 0   
}

void dfs(int i, int j, int n, int m, vector<vector<int>>& grid){
    grid[i][j] = 1;

    int dx[4] = {1. -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for(int k = 0; k<4; ++k){   // Beginners mistakenly use i here and that gets mixed up hence error
        int nx = i + dx[k];
        int ny = j + dy[k];

        if(isValid(nx, ny, n, m, grid)){
            dfs(nx, ny, n, m, grid);
        }
    }
}


// Ques involving just boundary dfs
https://leetcode.com/problems/number-of-enclaves/submissions/

//  
https://leetcode.com/problems/surrounded-regions/
//
One method:
// Mark all boundary connected 'O' as something else letter say 'B' using BFS
// Then convert the matrix:
// All the 'O' to 'X' and then all the 'B' back to 'O'

// Another similar way
// Saare boundary connected ko visited mark kar dia.
// Other 'O' and not visited ko convert kar dia EZ.
// Use of 2D vis array
class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<char>>& board,vector<vector<int>>&vis){
         if(i<0 || j<0 || i>=n || j>=m || vis[i][j]==1 || board[i][j]=='X'){
             return;
         }
        vis[i][j]=1;
        dfs(i+1,j,n,m,board,vis);
        dfs(i,j+1,n,m,board,vis);
        dfs(i-1,j,n,m,board,vis);
        dfs(i,j-1,n,m,board,vis);
    }

    void solve(vector<vector<char>>& board) {
        //convert all those zeroes to x which are not a part of boundary region
        int n=board.size(),m=board[0].size();
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));   // syntax to make 2D vis vector initilise with 0
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || j==m-1 || i==n-1){
                    if(vis[i][j]==0 && board[i][j]=='O'){
                        dfs(i,j,n,m,board,vis);
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }

};

