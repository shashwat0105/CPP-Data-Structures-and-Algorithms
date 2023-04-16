https://leetcode.com/problems/making-a-large-island/

HARDDD
https://youtu.be/lgiz0Oup6gM (Striver)
https://takeuforward.org/data-structure/making-a-large-island-dsu-g-52/ 

I cannot represent two numbers row, col in my DSU so I need to convert cell to a single number.

n*m cells => [0, n*m-1] range.

Formula: (row, col) = row*m + col

How will u count the number of nodes in a connected component, you may think.

But for your realisation, if u do union by size.
size[ultimateParent] stores the size of the component. NICE.


Next step is try converting every 0 to 1 and see how much can u increase the size of the island.

Edge case: 
Note that the same island can connect to 0 more than once, you would count it more than once, but that will be wrong.
We keep a track of it using a set.

// Template code of DSU just ctrl c + v
class DisjointSet {
public:
    vector<int> rank, parent, size;
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
    bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        vector<pair<int, int>> directions {{0,1},{1,0},{0,-1},{-1,0}};

        // step - 1: form the DSU
        for (int row = 0; row < n ; row++) {
            for (int col = 0; col < n ; col++) {
                if (grid[row][col] == 0) continue;

                for(auto &dir: directions){
                    int newr = row + dir.first;
                    int newc = col + dir.second;
                    if (isValid(newr, newc, n) && grid[newr][newc]) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        // step 2  : Read theory from article to revise this step.
        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
               
                set<int> components;
                for (auto &dir: directions) {
                    int newr = row + dir.first;
                    int newc = col + dir.second;
                    if (isValid(newr, newc, n) && gird[newr][newc]) {
                        components.insert(ds.findUPar(newr * n + newc));
                    }
                }
                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1);  // +1 for the current cell being included
            }
        }

        // we wrote this extra if the matrix didn't contain any 0, then I need to compare between already present size of the components. By first finding ulitimate parent then finding size of those parents
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
        }
        return mx;
    }
};
