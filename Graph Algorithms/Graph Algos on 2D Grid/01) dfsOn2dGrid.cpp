// Graph algos on 2D Grid is totally different from adjacency matrix.

// The cells in a grid are considered as nodes as in graphs
// Two cells are said to be connected if they share a same side or side and corner

// 1. Cell = Node
// 2. Sides = Edges
// 3. Sides + Corner = Edges


// dfs on normal graph

void dfs(int node){
    vis[node]=1;

    for(int child: adj[node])
        if(vis[node]==0)
            dfs(child);
}

// dfs on 2D Grid, pseudo code

void dfs(int x, int y){  // (row, column) is to be passed for a cell
    vis[x][y]=1;         // marking the cell as visitedj

    // there are 4 directions in which we can go if sides are defined as edges.
    if(isValid(x-1,y))   // isValid function will return T/F based on (i) whether the cell you want to go exists or not. (ii) Whether that node is already visited or not
        dfs(x-1,y);      // up
    
    if(isValid(x,y+1))
        dfs(x,y+1);      // right
    
    if(isValid(x+1,y))
        dfs(x+1,y);      // down
    
    if(isValid(x,y-1))
        dfs(x,y-1);      // left
}

//***************COMPLETE CODE*********//

#include<bits/stdc++.h>
using namespace std;

int N,M;                          // We assume rows are 1 to N, columns are 1 to M
bool vis[1001][1001];

bool isValid(int x, int y){
    if(x<1 || x>N || y<1 || y>M)
        return false;
    
    if(vis[x][y]==true)
        return false;
    
    return true;
}

void dfs(int x, int y){
    vis[x][y]=1;

    cout<<x<<" "<<y<<endl;

    if(isValid(x-1,y))
        dfs(x-1,y);
    
    if(isValid(x,y+1))
        dfs(x,y+1);      

    if(isValid(x+1,y))
        dfs(x+1,y);      
    
    if(isValid(x,y-1))
        dfs(x,y-1);      
}


int main(){
    cin>>N>>M;

    dfs(1,1);     // dfs of starting point cell 1,1
    return 0;
}

 
// ****** Reducing the repitition from above code. ***********

#include<bits/stdc++.h>
using namespace std;

int N,M;                          // We assume rows are 1 to N, columns are 1 to M
bool vis[1001][1001];

bool isValid(int x, int y){
    if(x<1 || x>N || y<1 || y>M)
        return false;
    
    if(vis[x][y]==true)
        return false;
    
    return true;
}

int dx[] = {-1,0,1,0};    // An array containing change in value of x while moving 
int dy[] = {0,1,0,-1};    // An array containing change in value of y while moving 

void dfs(int x, int y){
    vis[x][y]=1;

    cout<<x<<" "<<y<<endl;

    for(int i=0;i<4;i++){
       if(isValid(x+dx[i],y+dx[y])){
          dfs(x+dx[i],y+dy[i]); 
       } 
    }  
}

int main(){
    cin>>N>>M;
                  // All grid values are 1, so we dont need to take grid input 
    dfs(1,1);     // dfs of starting point cell 1,1
    return 0;
}
