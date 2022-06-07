// We can visit every cell from every other cell in a connected component in a grid

// In graph
int cnt = 0;

for(int i=1;i<=n;i++){                        // inside main function, running loop for every node
    if(vis[i]==0){
        cnt++;
        dfs(i);
    }
}


// In Grid
int cnt=0;
for(int i=1;i<=N;i++){                        // we run a loop for every single cell
    for(int j=1;j<=M;j++){
        if(ar[i][j]==1 && vis[i][j]==false){  //ar[i][j] means the value of the cell must be 1 not 0  & the cell is not visited
            cnt++;
            dfs(i,j);
        }
    }
}

// Complete code
#include<bits/stdc++.h>
using namespace std;

int N,M;                                      // We assume rows are 1 to N, columns are 1 to M
int ar[1001][1001];                           // now we need to store the whole grid
bool vis[1001][1001];

bool isValid(int x, int y){
    if(x<1 || x>N || y<1 || y>M)
        return false;
    
    if(vis[x][y]==true || ar[x][y]==0)        // here some elements of the grid are 0(cant move through them) & some are 1, in dfs on grid all elements we can traverse
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
            if(ar[i][j]==1 && vis[i][j]==false){  
            cc++;
            dfs(i,j);
            }
        }
    }

    cout<<"Connected Components Count = "<<cc<<endl;

    return 0;
}

// INPUT
// 0 0 1 0 1 1
// 0 1 1 0 0 1
// 0 1 0 0 0 0
// 1 0 1 1 0 0
// 0 0 0 1 0 0 
// 0 1 1 0 1 1

// OUTPUT
// 6