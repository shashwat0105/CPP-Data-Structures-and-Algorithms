// https://cses.fi/problemset/task/1192

// Mistakes I made:
// floor means "jameen" in this ques
// I was storing character in int array :(

// Problem is to count the no of connected components
#include<bits/stdc++.h>
using namespace std;

int N,M;                                      // We assume rows are 1 to N, columns are 1 to M
char ar[1001][1001];                         // now we need to store the whole grid, also the elements of grid are characters so we make char array
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

