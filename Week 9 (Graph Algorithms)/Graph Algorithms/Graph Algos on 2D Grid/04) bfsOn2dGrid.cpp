// BFS on normal graph

void BFS(int src){
    q.push(src);
    dist[src] = 0;
    vis[src] = 1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int node: adj[curr]){
            if(vis[node]==0){
                dist[node] = dist[curr] + 1;
                vis[node] = 1;
                q.push(node);
            }
        }
    }
}

// BFS on 2D Grid

#include <bits/stdc++.h>
using namespace std;

// It it supposed that all paths on the grid can be moved on so no need to take grid input
int dist[1001][1001];
int N, M;
int vis[1001][1001]; 

bool isValid(int x, int y){
    if(x<1 || x>N || y<1 || y>M) return false;       // cell is not inside the grid

    if(vis[x][y]==1) return false;                   // cell is visited already

    return true;
}

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void bfs(int srcX, int srcY){      // coordinate of the source cell
    queue<pair<int,int>> q;
    q.push({srcX, srcY});          // queue storing a pair of integers
    dist[srcX][srcY] = 0;
    vis[srcX][srcY] = 1;

    while(!q.empty()){
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        // considering there are 4 directions(up,down,left,right) in which movement is allowed
        for(int i=0;i<4;i++){
            if(isValid(currX + dx[i], currY + dy[i])){         // validity check based on i) if that cell exists & ii) is not visited yet
                int newX = currX + dx[i];
                int newY = currY + dy[i];

                dist[newX][newY] =  dist[currX][currY] + 1;
                vis[newX][newY] = 1;
                q.push({newX, newY});
            }
        }
    }

    // to print the distance array
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int x, y;    // dimension of source cell
    cin>>N>>M;
    cin>>x>>y;

    bfs(x,y);

    return 0;
}

