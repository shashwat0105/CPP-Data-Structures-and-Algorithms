https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

Root node, one of the two nodes can also be LCA

// Brute force:
// LCA(4, 7)
// We write the path from 4 to root
// and path from 7 to root.
// we will compare the paths and first where they match first is our ans.
// In this approach they is extra space as we have to store both the paths.

// Optimised: (Dry run karke dekh lo samajh aa jaega)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {   // dfsTraversal
        // base case
        if(root==NULL || root==p || root==q){                         // if current root == p or root == q ie we found p or q in the tree ar wo return kar denge
            return root;
        }
        TreeNode *left  = lowestCommonAncestor(root->left, p, q);     // because the return function is TreeNode type
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        // (Jab har subtree ki left ar right calls complete ho jaengi tab aage yeh chalega)
        if(left==NULL)       return right;   // if left is NULL, return right whatever it is, be it NULL too(ie neither p nor q was in that subtree)    
        else if(right==NULL) return left;  
        else return root;                    // both left and right are not, we found our ans. (ie under this root both p and q lie)
    }
};

// If the current (sub)tree contains both p and q, then the function result is their LCA. 
// If only one of them is in that subtree, then the result is that one of them. 
// If neither are in that subtree, the result is null/None/nil.

//*********************8
// Lowest common ancestor of a general tree(A general tree is basically a graph).
// Har node ka tree k root se path likh lo, with the help of parent
// Parent we can store by running a dfs 
// 1 2 3 4 5 6 7
// 1 2 3 4 8 9 
// So, LCA is 4 

// TC = O(N)

#include<bits/stdc++.h>
using namespace std;

const int n = 1e5+10;
vector<int> g[N];
int parent[N];

void dfs(int v, int par=-1){
    parent[v] = par;
    for(int child: g[v]){
        if(child==par) continue;
        dfs(child, v);
    }
}

// We will give a node it will return us the path vector
// v ek node hogi uske parent pe jaenge fr uske parent pe jaenge...until we get -1
vector<int> path(int v){
    vector<int> ans;
    while(v!=-1){
        ans.push_back(v);
        v = par[v];
    }
    // we want root first then the node at the last so we reverse
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);   // We know that root is 1
    int u, v; // two nodes whose LCA we want to find
    vector<int> path_u = path(u);
    vector<int> path_v = path(v);

    int min_ln = min(path_u.size(), path_v.size());  // The vector which has smaller length I will run loop till there

    int lca = -1;
    for(int i=0; i<min_ln; i++){
        if(path_u[i] == path_v[i]){
            lca = path_u[i];
        }
        else break;
    }
    cout<<lca<<endl;

    return 0;
}

// Advanced Algorithm
// Binary uplifting which finds LCA in O(logn) time. (Can be used in CP but not in interviews)
