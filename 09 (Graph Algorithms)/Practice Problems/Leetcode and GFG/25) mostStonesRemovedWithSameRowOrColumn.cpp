https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

Google's Fav Question on DSU

// We define: connected component comprise of nodes having either same row or column.
// Then we can remove all nodes of that component except the last remaining. ie total_nodes - 1
// If there are N components we can do the above for all.
// ie No of leftover stones = no of connected components.
// Hence max no of removed stones = total stones - no of leftover stones

CRUX: Ans = Total Stones - Number of connected components.     

// First I have to join the edges.
// Then I have to calculate connected components.  // either dfs/bfs or dsu.

// Method 1: Using DSU

// Data structure used is Union Find
// Helps us to unify groups together and and very quickly find which group contains a certain element.

// Using indexes as the ids(nodes) of union find is so so brilliant, way more simplified than other solutions.
Meaning by dry run:
  0     1     2     3     4  // Indixes
[0,0],[0,2],[1,1],[2,0],[2,2]

When I am at 1, I see that peeche wala 0 mein row common hai so, I join 0 and 1.  and so on...
ie used the index of the coordinate as node for DSU

// Simple improvements:
// Using the word root or ultimate parent instead of parent
// Using connect or findUnion instead of Union // Mistakenly types union which is an inbuilt method

class Solution {
public:
    vector<int> parent;
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent = vector<int>(n);
        // making node and initilising parent
        for(int i=0; i<n; ++i){
            parent[i] = i;
        }

        for(int i=0; i<n; ++i){                                                    // n is the number of stones
            for(int j=0; j<i; ++j){                                                // this for loop is imp to observe. // current stone peeche k kisi bhi row ya column wale se match kr jae
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){  // kisi ka bhi row ya column equal ho toh union kar do
                   Union(i, j); 
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<n; ++i){
            if(parent[i]==i) cnt++;                   // jitne bhi elements ka abhi bhi parent change nahi hua hai wahi toh mere roots hai! ie wahi toh number of components hai
        }
        return n-cnt;
    }
    
    int findParent(int i){
        if(parent[i]!=i){
            parent[i] = findParent(parent[i]);       // updating the parents 
        }
        return parent[i];   // when parent[i]==i
    }
    
    void Union(int i, int j){
        parent[findParent(i)] = findParent(j);
    }
    
};

// If you don't want to declare parent globally(ie better code quality) you can pass the parent too by reference in findParent and Union.

// CODE by striver
https://takeuforward.org/data-structure/most-stones-removed-with-same-row-or-column-dsu-g-53/
This is actually faster but slight longer,
above take lot of time because
That will take a lot of time as you need to traverse each cell + the size of the disjoint set increases as the nodes are more , then for each cell you would be joining the whole row and column nodes seperately..

// For future:
// I just noticed that instead of using a map to store the nodes where stones are present, we could simply check through the parent and size/rank structure of our disjoint set class as below:

// for(int i=0;i<(maxRow+maxCol+1);i++){
//             if(ds.parent[i]==i && ds.size[i]>1)
//                 cnt+=1;
// }

// What I noticed was that if a coordinate has a stone, then it's row and column will be attached to each other in our disjoint set, only the empty rows and empty columns will remain single.


Method 2: Using DFS
https://youtu.be/ZsGTpXm966E  (MIK)
Instead of creating a separate graph, adjacent k liye directly loop laga k traverse kia hai in that matrix itself.


CODE:
class Solution {
public:
    int n ;
    void DFS(vector<vector<int>>& stones, int index, vector<int>& vis) {
        vis[index] = 1;
        for(int i = 0; i<n; i++) {
            if(!vis[i] &&
               ((stones[i][0] == stones[index][0]) || (stones[i][1] == stones[index][1]))) {
                DFS(stones, i, vis);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        vector<int> vis(n, 0);

        int c = 0;

        for(int i = 0; i<n; i++) {
            if(vis[i]) continue;
            DFS(stones, i, vis);
            c++;
        }
        return n - c;
    }
};


// Other thought processes.
https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/discuss/197668/Count-the-Number-of-Islands-O(N)


************* STRIVER TUTORIAL PROBLEMS KHATAM HUI ***********************
