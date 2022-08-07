https://leetcode.com/problems/regions-cut-by-slashes/

https://youtu.be/Wafu5vOxPRE   (Dots method explanation courtesy)
// Think in terms of dots.
// Everytime you make a cycle there is a new region created.
// DSU was used in Kruskal algorithm to detect a cycle.
// Boundary dots are already connected.

// (i, j) block has "/" then it connects (i+1, j) and (i, j+1) dots
// (i, j) block has "\" then it connects (i, j) and (i+1 j+1) dots

// Here Used rank for DSU

class Solution {
public:
    int findRoot(int node, vector<int> &par){
        if(par[node]==node) return node;
        return par[node] = findRoot(par[node], par);
    }
    
    void connect(int a, int b, int &cnt, vector<int> &rank, vector<int> &par){
        a = findRoot(a, par);                       // uniting the dots, UNION function
        b = findRoot(b, par);
        
        if(a!=b){
            if(rank[a]>rank[b]) par[b] = a;
            else if(rank[b]>rank[a]) par[a] = b;
            else{
                par[b] = a;
                rank[a]++;
            }
        }
        else{
            cnt++;            // ie a==b ie the dots are already in the same set, ie it is forming a cycle and thus increases the count!!
        }
    }
    
    
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();  // Size of an edge
        int dot = n+1;        // A particular edge will have n+1 dots
        int cnt = 1;          // intial count is 1 because the grid without any partitions is also a component.
        
        vector<int> par(dot*dot);
        vector<int> rank(dot*dot);
        
        for(int i=0; i<dot*dot; ++i) par[i] = i;  // initialising the parent and rank of all dots (3 side square will have 0 to 15 ie 16 dots)
        for(int i=0; i<dot*dot; ++i) rank[i] = 1;
        
        // Initially there is a boundary square so connecting all boundary dots to 0
        for(int i=0; i<dot; ++i){
            for(int j=0; j<dot; ++j){
                if(i==0 || j==0 || i==dot-1 || j==dot-1){  // that dot lies in the boundary
                    int dotno = (i*dot)+j;                 // Giving dot a number say any bw 0-15
                    if(dotno!=0) connect(0, dotno, cnt, rank, par);
                }
            }
        }
        
        // Moving in the given vector
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j]=='/'){
                    int dot1 = (i*dot) + (j+1);  // calculating the corresponding dots that will get connected now
                    int dot2 = ((i+1)*dot)+j;
                    connect(dot1, dot2, cnt, rank, par); // connecting ie Union of them
                }
                else if(grid[i][j]=='\\'){
                    int dot1 = (i*dot)+j;
                    int dot2 = ((i+1)*dot)+(j+1);
                    connect(dot1, dot2, cnt, rank, par);
                }
            }
        }
        return cnt;
    }
};



// Same DSU using size
https://leetcode.com/problems/regions-cut-by-slashes/discuss/2114205/Making-dots-Matrix-and-then-joining-them-oror-C%2B%2B


// Some other methods from LC discuss by splitting the cells.
(Isko abhi ar samjhna hai tagda sawal hai)
https://leetcode.com/problems/regions-cut-by-slashes/discuss/?currentPage=1&orderBy=most_votes&query=

