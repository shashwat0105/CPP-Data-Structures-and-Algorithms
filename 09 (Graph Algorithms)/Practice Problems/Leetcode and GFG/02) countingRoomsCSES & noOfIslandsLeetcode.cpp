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

int dx[] = {-1,0,1,0};                        // An array containing change in value of x while moving 
int dy[] = {0,1,0,-1};                        // An array containing change in value of y while moving 

void dfs(int x, int y){
    if(x<1 || x>N || y<1 || y>M || vis[x][y] || ar[x][y]=='#') return;
    vis[x][y]=1;

    for(int i=0;i<4;i++){
        dfs(x+dx[i],y+dy[i]); 
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

LEETCODE
https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    void dfs(int x, int y, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> dir {{0,1},{1,0},{0,-1},{-1,0}};

        if(x<0 || x>=n || y<0 || y>=m || grid[x][y]=='0') return;
        grid[x][y]='0'; // mark visited kind of

        for(auto &d: dir){
            int newx = x + d.first;
            int newy = y + d.second;
            dfs(newx, newy, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) 
        int cc=0;
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0; i<n; ++i){                   // i=row, j=col
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

// If you want to see BFS implementation:
https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Number_of_Islands.cpp

In the ques the Island is 8 directional
https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

// Follow-up for this task: "what if the input data is too big (and sparse)" (Can be asked in interview)
https://leetcode.com/problems/number-of-islands/discuss/640295/Optimized-by-memory-(follow-up-question-what-if-matrix-is-too-big)

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
        
        vector<pair<int,int>> dir {{0,1},{1,0},{0,-1},{-1,0}};

        for(auto &d: dir){
            int newx = i + d.first;
            int newy = j + d.second;
            dfs(grid, newx, newy, n, m, area);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==1){
                    int area = 0;                  // everytime a dfs will be called, we will start from a new area
                    dfs(grid, i, j, n, m, area);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};

