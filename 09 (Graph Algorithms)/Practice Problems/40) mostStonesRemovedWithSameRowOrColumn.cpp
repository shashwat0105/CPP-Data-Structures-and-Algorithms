https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

Google's Fav Question on DSU

// A connected component comprise of nodes having either same i or column.
// Then we can remove all nodes of that component except the last remaining. ie total_nodes - 1
// If there are N components we can do the above for all.
// ie No of leftover stones = no of connected components.
// Hence no of removed stones = total stones - no of leftover stones

// First I have to join the edges.
// Then I have to calculate connected components.

// Data structure used is Union Find
// Helps us to unify groups together and and very quickly find which group contains a certain element.


//
// Using indexes as the ids of union find is so so brilliant, way more simplified than other solutions.

// Simple improvements:
// Using the word root instead of parent
// Using connect instead of Union // Mistakenly types union which is an inbuilt method

class Solution {
public:
    vector<int> parent;
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent = vector<int>(n);
        // making node
        for(int i=0; i<n; ++i){
            parent[i] = i;
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<i; ++j){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){  // kisi ka bhi row ya column equal ho toh union kar do
                   Union(i, j); 
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<n; ++i){
            if(parent[i]==i) cnt++;                   // jitne bhi elements ka abhi bhi parent update nahi hua hai wahi toh mere roots hai!
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

// If you don't want to declare parent globally(ie better code quality)
// Same code, just passed parent too.
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int>parent(n);
        // making node
        for(int i=0; i<n; ++i){
            parent[i] = i;
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<i; ++j){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){  // kisi ka bhi row ya column equal ho toh union kar do
                   Union(i, j, parent); 
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<n; ++i){
            if(parent[i]==i) cnt++;
        }
        return n-cnt;
    }
    
    int findParent(int i, vector<int> &parent){
        if(parent[i]!=i){
            parent[i] = findParent(parent[i], parent);
        }
        return parent[i];   // when parent[i]==i
    }
    
    void Union(int i, int j, vector<int> &parent){
        parent[findParent(i, parent)] = findParent(j, parent);
    }
    
};

// After further development of your brain cells
https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/discuss/197668/Count-the-Number-of-Islands-O(N)

