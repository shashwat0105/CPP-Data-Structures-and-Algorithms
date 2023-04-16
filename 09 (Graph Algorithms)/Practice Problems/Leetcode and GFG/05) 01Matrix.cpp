https://leetcode.com/problems/01-matrix/

Multi Source BFS

// Striver method (More intuitive)

We run BFS from values that are 0.

TC and SC = O(n*m)

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(mat[i][j]==0){
                    q.push({{i, j}, 0});  // I do BFS from values 0
                    vis[i][j]=1;
                }else{
                    vis[i][j]=0;
                }
            }
        }

        vector<pair<int,int>> directions {{0,1},{1,0},{0,-1},{-1,0}};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col] = steps;

            for(auto &dir: directions){
                int nrow = row + dir.first;
                int ncol = col + dir.second;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1; // mark as visited
                    q.push({{nrow, ncol}, steps+1});
                }
            }
        }
        return dist;
    }
};

Others
https://leetcode.com/problems/01-matrix/solutions/1260286/simple-c-solution-with-complete-explanation/
https://leetcode.com/problems/01-matrix/solutions/1369741/c-java-python-bfs-dp-solutions-with-picture-clean-concise-o-1-space/
