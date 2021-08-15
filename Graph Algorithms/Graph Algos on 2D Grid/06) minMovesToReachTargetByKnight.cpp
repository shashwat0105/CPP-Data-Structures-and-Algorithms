// There are max 8 moves for a knight from a certain cell.

// If there are x rows & y columns
// Knight is at positon x, y
// Possible moves for the knight (A knight moves 2 & half)
// (x-2,y+1)
// (x-1,y+2)
// (x+1,y+2)
// (x+2,y+1)
// (x+2,y-1)
// (x+1,y-2)
// (x-1,y-2)
// (x-2,y-1)

// dx[] = {-2,-1,1,2,2,1,-1,-2}
// dy[] = {1,2,2,1,-1,-2,-2,-1}

// These will affect the direction arrays dx[] & dy[]
// Finding the direction is most imp while applying dfs, bfs on 2D grid.

// We want to find min moves and each cell is weighted equally so we use BFS
// If it is weighted then we go for Dijakstra.



// https://www.codechef.com/problems/PRGCUP01

// Columns 1 - 8
// Rows a - h   (Will convert to 1 - 8)

// We will read the input in form of characters & convert them into integers


#include <bits/stdc++.h>
using namespace std;

int vis[10][10];
int dist[10][10];
int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};

bool isValid(int x, int y){
    if(x<1 || x>8 || y<1 || y>8) return false;

    if(vis[x][y]==1) return false;

    return true;
}

void bfs(int srcX, int srcY){
    queue<pair<int, int>> q;
    q.push({srcX, srcY});
    dist[srcX][srcY]=0;
    vis[srcX][srcY]=1;

    while(!q.empty()){
       int currX = q.front().first;
       int currY = q.front().second;
       q.pop();

       for(int i=0;i<8;i++){                                  // 8 different directions to move.
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

int getA(char alpha){                                         // can also write by if else conditions
    return alpha - 'a' + 1;                                   // say alpha = b, then b - 'a' will be 1 and 1+1 = 2 which is now its integer representation
}

int main(){

    int a,b;                                                  // to store coordinates of start
    int u,v;                                                  // to store coordinates of end
    int t;                                                    // no of test cases
    cin>>t;

    while(t--){
        char p,q;

        for(int i=1; i<=8;i++){
            for(int j=1;j<=8;j++){
                vis[i][j] = 0;                                // IMP: clearing the visiting matrix for every test case
            }
        }

        // Taking source input
        cin>>p>>q;                                           // Say source is g8 then p is g & q is 8
        a = getA(p);                                         // getA function to change 'g' to integer bw 1-8
        b = q - '0';                                         // since q is a integer looking but a character we subtract ASCII values 

        // Taking target input
        cin>>p>>q;
        u = getA(p);
        v = q - '0';

        bfs(a,b);

        cout<<dist[u][v]<<endl;
    }

    return 0;
}
