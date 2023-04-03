https://leetcode.com/problems/diameter-of-binary-tree/

Diameter of binary tree
1) Longest path between two nodes.
2) Path need not pass through the root.


// We can find lH and rH at every node, and add them up and compare. The max will be the ans.
// We know to calculate height of tree in O(N) time. (Is the crux of optimisation)

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root, diameter);
        return diameter;
    }
    
    int height(TreeNode *root, int &diameter){  // diameter is changing has to be passed by reference
        if(root==NULL){
            return 0;
        }
        
        int lH = height(root->left, diameter);
        int rH = height(root->right, diameter);
        diameter = max(diameter, lH+rH);         // diameter kya hoga? har instance pe leftHeight + rightHeight mein maximum
        
        return 1+max(lH, rH);  // lH akela calculate karne mein bhi toh 1+ karna hi padta hai ie chahe left height nikalna ho ya right height
    }
};


// Diameter of a tree(acyclic graph) (which is an undirected graph basically, ie we can go to parent too)
// Here root is unknown too, hence we cannot do one dfs and find the two largest values and add them
// Also 1 is generally the root of the such trees, can see from sample test cases.

https://youtu.be/m8qXEz1Xe8w (LUV)
https://www.quora.com/How-do-I-find-the-diameter-of-a-tree
https://www.geeksforgeeks.org/dynamic-programming-trees-set-2/
http://courses.csail.mit.edu/6.046/fall01/handouts/ps9sol.pdf (CLRS mein hai yeh ques)

// The diameter of a Tree is basically the longest path between any two nodes.

// Brute Force:
// Find max distance from every node ie har node ko root maan k max depth calculate kar lo
// O(n^2)

// Optimised using 2 DFS
//  Step 1: From any arbitrary vertex x of a tree find the farthest vertex u, ie x ko root maan k max depth nikalo (This u has to be one of the end of diameter)
//  Step 2: From vertex u find the farthest vertex v, ie u ko root maan k max depth nikalo ie dist(u,v)  (This v will be the other end of the diameter) (As we go directly on parent nodes)
//  dist(u,v) gives you the diameter. 

#include<bits/stdc++.h>
using namespace std;

const int n = 1e5+10;
vector<int> g[N];
int depth[N];

// Tree mein dfs parent pass karke lagana so that we dont visit that again
void  dfs(int v, int par=-1){
    for(int child: g[v]){
        if(child == par)continue;
        depth[child] = depth[v]+1;  // coz depth neeche jaate jaate calculate hoti hai 
        dfs(child, v);
    }
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
    dfs(1);  // Calling dfs, taking any node as root // Isme do arguments pass karne ki jaroorat nahi padi
    int max_depth = -1;
    int max_d_node;
    
    for(int i=1; i<=n; i++){
        if(max_depth < depth[i]){
            max_depth = depth[i];
            max_d_node = i;
        }
        depth[i] = 0;  // reset the array as we want to run dfs again
    }

    dfs(max_d_node);
    max_depth = -1;
    for(int i=1; i<=n; i++){
        if(max_depth < depth[i]){
            max_depth = depth[i];
        }
    }
    cout<<max_depth<<endl;
}

// solve this ques later
https://leetcode.com/problems/minimum-height-trees/description/

