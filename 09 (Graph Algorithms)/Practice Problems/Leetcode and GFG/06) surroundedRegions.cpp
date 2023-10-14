https://leetcode.com/problems/surrounded-regions/

We use DFS for this as we want to just traverse in the nodes.

// Any 'O' connected to boundary will never get converted to 'X'
// Start from boundary O's and mark the corresponding locations that they can not be converted and convert the remaining zeroes to X.

class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<char>>& board, vector<vector<int>>&vis, vector<pair<int,int>> &directions){
         if(i<0 || j<0 || i>=n || j>=m || vis[i][j]==1 || board[i][j]=='X'){
             return;
         }
        vis[i][j]=1;       // this will mark all the nodes that cannot be converted to X
        
        for(auto &dir: directions){
            int newI = i + dir.first;
            int newJ = j + dir.second;
            dfs(newI, newJ, n, m, board, vis, directions);
        }
    }

    void solve(vector<vector<char>>& board) {
        //convert all those zeroes to x which are not a part of boundary region

        int n=board.size(),m=board[0].size();
        vector<vector<int>> vis(n+1,vector<int>(m+1,0));    // syntax to make 2D vis vector initilise with 0
        vector<pair<int,int>> directions {{0,1},{1,0},{0,-1},{-1,0}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || j==m-1 || i==n-1){  // DFS call for boundary nodes only
                    if(vis[i][j]==0 && board[i][j]=='O'){
                        dfs(i,j,n,m,board,vis, directions);
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
