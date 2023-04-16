https://leetcode.com/problems/number-of-islands-ii/ (Premium)

https://practice.geeksforgeeks.org/problems/number-of-islands/1?

https://youtu.be/Rn6B-Q4SNyA (Striver)

Online Queries Problem.

Ques based on DSU

I want to convert (row, col) index to be in range [0 , row*col-1]

0 1 2 3
4 5 6 7  ie [0, 7]

n = no of rows
m = no of columns

Formula: (row, col) => (row*m) + col

If any node doesnt have any other node to its left, right, top then alone it will add one to the ans.
Further it reduces the ans depending on number of connections it can make with neighbours.
ie first a neighbour should exist ie island(1) and also it should not be directly or indirectly connected to it.

Ar esi node se hi tabhi judo jisse directly ya indirectly nahi jude ho.

0
|
5 -- 6    // When the node 5 comes, it sees 0 on top usse connection bana lia, sees 6, isse bhi directly or indirectly nahi connected hai so connection bana lia ie 2 connections are made.
          // ie increase ans by 1(for himself) decrease ans by 2  (coz 5 k aane se net components decreased by 1)

0    1    // The node 1 comes then join it with 6, when trying to join with 0 u will see that it is already connected(indirectly(ultimate parent)) so u wont make that connection.
|    |    // ie increase ans by 1(for himself) decrease and by 1   (coz 1 k aane se net components m koi fark ni pada)
5 -- 6 

TIP:
Writing code by making a separte disjoint set class, and then making its constructor, stands u apart from the crowd in the interviews!!(Quality Code)

CODE:

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
  private:
    bool isValid(int r, int c, int n, int m){
        return r>=0 && r<n && c>=0 && c<m;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        int vis[n][m];  // So that I dont calculate query for a node again and again
        memset(vis, 0, sizeof(vis));
        
        int cnt = 0;
        vector<int> ans;
        for(auto &it: operators){
            int row = it[0];
            int col = it[1];
            if(vis[row][col]){
                ans.push_back(cnt);
                continue;
            }
            // else mark it visited
            vis[row][col]=1;
            cnt++;  // due to himself increase the component count
            vector<pair<int, int>> directions {{0,1},{1,0},{0,-1},{-1,0}};
            for(auto &dir: directions){
                int adjr = row + dir.first;
                int adjc = col + dir.second;
                
                if(isValid(adjr, adjc, n, m) && vis[adjr][adjc]){  // vis of the adjacent should be an island, ie pehle use jameen mark kia hona chaiye
                    int nodeNo = row * m + col;
                    int adjNodeNo = adjr * m + adjc;
                    if(ds.findUPar(nodeNo)!=ds.findUPar(adjNodeNo)){ // not connected directly or indirectly
                        cnt--;
                        ds.unionBySize(nodeNo, adjNodeNo); // connect them
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
