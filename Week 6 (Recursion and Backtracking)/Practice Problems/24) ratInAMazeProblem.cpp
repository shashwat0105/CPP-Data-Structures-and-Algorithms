https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

https://youtu.be/bLGZhJlt4y0

// We start at the source and try to go at every possible path.
// Since we want ans in lexicographical order we will recur in lexicographical order ie DLRU

// We will keep a visited array so that we dont revisit the coordinates.

// TC = 4^(m*n) // on every cell I am going 4 directions nearabout
// Sc = Depth of the dfs ie auxiliary space = O(m*n)

// Code 1: Using 4 if statements
class Solution{
    void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis){
        if(i==n-1 && j==n-1){        // reached the destination 
            ans.push_back(move);
            return;
        }
        
        // downward (we chose down first to maintain the order)
        if(i+1<n && !vis[i+1][j] && a[i+1][j] == 1){  // that cell is inside the boundary && is not visited && its a valid path
            vis[i][j] = 1;
            solve(i+1, j, a, n, ans, move+'D', vis);
            vis[i][j] = 0;
        }
        
        // left
        if(j-1>=0 && !vis[i][j-1] && a[i][j-1] == 1){
            vis[i][j] = 1;
            solve(i, j-1, a, n, ans, move+'L', vis);
            vis[i][j] = 0;
        }
        
        // right
        if(j+1>=0 && !vis[i][j+1] && a[i][j+1] == 1){
            vis[i][j] = 1;
            solve(i, j+1, a, n, ans, move+'R', vis);
            vis[i][j] = 0;
        }
        
        // upward
        if(i-1>=0 && !vis[i-1][j] && a[i-1][j] == 1){
            vis[i][j] = 1;
            solve(i-1, j, a, n, ans, move+'U', vis);
            vis[i][j] = 0;
        }
        
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n,0));   // n*n vector
        if(m[0][0]==1) solve(0, 0, m, n, ans, "", vis); // if the source is 1 or not
        return ans;
    }
};


// Code 2:
// Using single for loop (THis way should do in interviews)
// Coz down is nothing but i+1 and j+0 and so are others

class Solution{
    void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis,
    int di[], int dj[]){
        if(i==n-1 && j==n-1){        // reached the destination 
            ans.push_back(move);
            return;
        }
        
        string dir = "DLRU";
        for(int ind = 0; ind<4; ind++){
            int nexti = i+ di[ind];
            int nextj = j+ dj[ind];
            if(nexti >=0 && nextj >=0 && nexti <n && nextj<n && !vis[nexti][nextj] && a[nexti][nextj]==1){
                vis[i][j]=1;
                solve(nexti, nextj, a, n, ans, move+dir[ind], vis, di, dj);
                vis[i][j] = 0;
            }
        }
        
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n,0));   // n*n vector
        int di[] = {+1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        if(m[0][0]==1) solve(0, 0, m, n, ans, "", vis, di, dj); // if the source is 1 or not
        return ans;
    }
};


