https://leetcode.com/problems/satisfiability-of-equality-equations/

// First process all == signs ie by making them in a single set union.
// Then you can check for != whether they belong to same root(parent) or not.

class Solution {
public:
    vector<int> parent;                               // Wrote globally to remind you of the resize funciton.
    int find(int i){
        if(parent[i]== -1) return i;
        return parent[i] = find(parent[i]);
    }
    
    void unionNode(int a, int b){
        a = find(a);
        b = find(b);
        if(a!=b){
            parent[a]=b;
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26, -1);                              // as there are 0-25 lowercase alphabets
        
        for(auto e: equations){
            if(e[1]=='=') unionNode(e[0]-'a', e[3]-'a');
        }
        for(auto e: equations){
            if(e[1]=='!'){
                if(find(e[0]-'a') == find(e[3]-'a')) return false;
            }
        }
        return true;
    }
};


// During revision
// Can refer other gem of solutions
https://leetcode.com/problems/satisfiability-of-equality-equations/discuss/?currentPage=1&orderBy=most_votes&query=
