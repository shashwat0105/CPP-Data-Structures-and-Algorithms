// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/jungle-run/

#include <bits/stdc++.h>
using namespace std;

char ar[35][35];
int dist[35][35];
int vis[35][35];
int N;

bool isValid(int x, int y){
    if(x<1 || x>N || y<1 || y>N) return false;        // (i) the cell in inside the grid

    if(vis[x][y]==1 || ar[x][y]=='T') return false;   // (ii) the cell is visited already or not (iii) The cell is a tree or not

    return true;
}

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void bfs(int srcX, int srcY){
    queue<pair<int, int>> q;
    q.push({srcX, srcY});
    dist[srcX][srcY]=0;
    vis[srcX][srcY]=1;

    while(!q.empty()){
       int currX = q.front().first;
       int currY = q.front().second;
       q.pop();

       for(int i=0;i<4;i++){
           if(isValid(currX+dx[i], currY+dy[i])){
               int newX = currX + dx[i];
               int newY = currY + dy[i];

               dist[newX][newY] =  dist[currX][currY] + 1;
               vis[newX][newY] = 1;
               q.push({newX, newY});
           }
       }

    }
}

int main(){
    int a,b;                          // to store coordinates of the starting point
    int u,v;                          // to store coordinates of the ending point
    cin>>N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>ar[i][j];            // taking grid input 

            if(ar[i][j]=='S'){
                a=i;
                b=j;
            }

            if(ar[i][j]=='E'){
                u=i;
                v=j;
            }
        }
    }

    bfs(a,b);

    cout<<dist[u][v];
    return 0;
}

