// After learning binary lifing, one can solve LCA queries in logn time.

https://cses.fi/problemset/task/1687

// Brute force
parent(i) = parent of node i

(node, k) = (parent(node), k-1)..... k reduces to 0 or reaches root node and still some jumps are left ie -1.

// TC = O(NQ), for every query, I have to traverse the entire tree again.

// Optimized using binary uplifting

// For every node 'u' calculate: up(u, i) : Then we can do queries in logn time.
// means the node that is 2^i levels above the current node.
// 2^i are node that are 1, 2, 4, 8, 16 ... levels above.

// Write k in its binary representation. 
// k = (010110) = 2^4 + 2^2 + 2^1  : ie writing k as sum of powers of 2.

UP TABLE:
up[root][x] = -1  // as I cannot make a jump above root
up[u, 0] = par[u] // 2^0 node above u.

up(u, x) = up(up(u, x-1), x-1)

coz: 2^x = 2^(x-1) + 2^(x-1) ie first I will make a jump of x-1 then again x-1

*************************************
// CODE:
#include<bits/stdc++.h>
using namespace std;

vector<int> tree[200001];
int up[200001][20];

void binary_lifting(int src, int par){
    up[src][0] = par;
    for(int i=1; i<20; ++i){
        if(up[src][i-1]!= -1){  // ie I can find value for 2^i-1
            up[src][i] = up[up[src][i-1]][i-1];
        }
        else up[src][i] = -1;
    }

    for(int child: tree[src]){
        if(child!=par){
            binary_lifting(child, src);
        }
    }
}

int ans_query(int node, int jump_required){
    if(node == -1 || jump_required==0){
        return node;
    }

    for(int i=19; i>=0; --i){
        if(jump_required >= (1<<i)){  // finding rightmost set bit
            return ans_query(up[node][i], jump_required - (1<<i));
        }
    }
}


int main(){
    int n, q, x;
    cin>>n>>q;
    for(int i=2; i<n+1; ++i){
        cin>>x;
        tree[x].push_back(i);
        tree[i].push_back(x);
    }
    binary_lifting(1, -1);    // actually the root of the tree has no parent. So I have used an invalid value for parent to represent this fact.
    while(q--){
        int node, k;
        cin>>node>>k;
        cout<<ans_query(node, k)<<'\n';
    }
}
