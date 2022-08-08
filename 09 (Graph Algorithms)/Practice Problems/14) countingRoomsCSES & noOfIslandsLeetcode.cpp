V V V V IMPORTANT QUES AND CONCEPT:

// https://cses.fi/problemset/task/1192

// Mistakes I made:
// floor means "jameen" in this ques
// I was storing character in int array :(

// Problem is to count the no of connected components (In a 2D Grid)

#include<bits/stdc++.h>
using namespace std;

int N,M;                                      // We assume rows are 1 to N, columns are 1 to M
char ar[1001][1001];                          // now we need to store the whole grid, also the elements of grid are characters so we make char array
bool vis[1001][1001];

bool isValid(int x, int y){
    if(x<1 || x>N || y<1 || y>M)
        return false;
    
    if(vis[x][y]==true || ar[x][y]=='#')        
        return false;
    
    return true;
}

int dx[] = {-1,0,1,0};                        // An array containing change in value of x while moving 
int dy[] = {0,1,0,-1};                        // An array containing change in value of y while moving 

void dfs(int x, int y){
    vis[x][y]=1;

    for(int i=0;i<4;i++){
       if(isValid(x+dx[i],y+dy[i])){
          dfs(x+dx[i],y+dy[i]); 
       } 
    }  
}

int main(){
    cin>>N>>M;

    for(int i=1;i<=N;i++){                    // taking grid input
        for(int j=1;j<=M;j++){
            cin>>ar[i][j];
        }
    }

    int cc=0;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(ar[i][j]=='.' && vis[i][j]==false){  
                cc++;
                dfs(i,j);
            }
        }
    }

    cout<<cc<<endl;

    return 0;
}


https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid){
  
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m) return;
        if(grid[i][j]=='0') return;
        
        grid[i][j] = '0';                        //  I can erase all the connected '1's using DFS and make them '0' or any other number, hence eliminating the use of visited array
        
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
    }

    int numIslands(vector<vector<char>>& grid) 
        int cc=0;
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]=='1'){              // agar 1 hoga then only I will call dfs
                    cc++;
                    dfs(i, j, grid);
                }
            }
        }
        return cc;
    }
};

//
// follow-up for this task: "what if the input data is too big (and sparse)" (Can be asked in interview)
https://leetcode.com/problems/number-of-islands/discuss/640295/Optimized-by-memory-(follow-up-question-what-if-matrix-is-too-big)

//
Similar problem 
https://leetcode.com/problems/max-area-of-island/
// Counting how many nodes are there in a component or which component has highest number of nodes.

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m, int &area){
        if(i<0 || j<0 || i>=n || j>=m) return;   // isValid condition
        if(grid[i][j] == 0) return;
        
        area++;
        grid[i][j] = 0;
        
        dfs(grid, i+1, j, n, m, area);
        dfs(grid, i-1, j, n, m, area);
        dfs(grid, i, j+1, n, m, area);
        dfs(grid, i, j-1, n, m, area);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==1){
                    int area = 0;      // everytime a dfs will be called, we will start from a new area
                    dfs(grid, i, j, n, m, area);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};
