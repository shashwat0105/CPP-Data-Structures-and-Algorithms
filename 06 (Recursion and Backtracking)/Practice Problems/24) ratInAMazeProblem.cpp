https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

https://youtu.be/bLGZhJlt4y0  (Striver)

// We start at the source and try to go at every possible path.
// Since we want ans in lexicographical order we will recur in lexicographical order ie DLRU

// We will keep a visited array so that we dont revisit the coordinates.
// Instead visited we can use the same array as visited. By marking it 0 and unmarking by 1.

// TC = 4^(m*n) // on every cell I am going 4 directions nearabout
// Sc = Depth of the dfs ie auxiliary space = O(m*n)

// Code 1: Using 4 if statements
class Solution{
    void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move){
        if(i<0 || j<0 || i>=n || j>=n || a[i][j]==0) return;   // out of boundary
        if(i==n-1 && j==n-1){        // reached the destination 
            ans.push_back(move);
            return;
        }
        
        a[i][j] = 0; // mark it visited

        // downward (we chose down first to maintain the order)
        if(i+1<n ) solve(i+1, j, a, n, ans, move+'D'); // that cell is inside the boundary
    
        // left
        if(j-1>=0) solve(i, j-1, a, n, ans, move+'L');
        
        
        // right
        if(j+1>=0) solve(i, j+1, a, n, ans, move+'R');
        
        
        // upward
        if(i-1>=0) solve(i-1, j, a, n, ans, move+'U');
        
        a[i][j] = 1;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string s = "";
        if(m[0][0]==1) solve(0, 0, m, n, ans, s); // if the source is 1 or not
        return ans;
    }
};


// Code 2:
// Using single for loop (This way should do in interviews)
// Coz down is nothing but i+1 and j+0 and so are others

class Solution{
    void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move,
    int di[], int dj[]){
        if(i<0 || j<0 || i>=n || j>=n || a[i][j]==0) return;
        if(i==n-1 && j==n-1){        // reached the destination 
            ans.push_back(move);
            return;
        }
        a[i][j] = 0;
        string dir = "DLRU";
        for(int ind = 0; ind<4; ind++){
            int nexti = i + di[ind];
            int nextj = j + dj[ind];
            solve(nexti, nextj, a, n, ans, move+dir[ind], di, dj);
        }
        a[i][j] = 1;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        int di[] = {+1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        if(m[0][0]==1) solve(0, 0, m, n, ans, "", di, dj); // if the source is 1 or not
        return ans;
    }
};
