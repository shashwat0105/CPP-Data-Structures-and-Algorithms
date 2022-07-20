// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/feasible-relations/

// https://youtu.be/iygT1oD7C_s

// In the sample 2nd test case:
// Example: Assign 10 to 1 and 2 both, then 10 = 10
//          Assign 20 to 3           , then 10 != 20

// More example test cases
// i)
// 5   5
// 1 = 2
// 3 = 1
// 4 != 2
// 5 = 4
// 3 != 5

// 1 = 2 = 3 belong to 1 group
// 4 = 5 belong to other group
// Members of different group will be unequal, and from 1 group will be same
// YES, this is possible here

// ii)
// 5  4
// 1 = 2
// 2 != 3
// 5 = 4
// 1 = 3

// 1 = 2 = 3 belong to one group
// 5 = 4 belongs to other
// BUT, 2!=3 contradicts, so this is not possible. Hence NO

// All the variables will be considered as nodes
// All the equal signs will be considered as edges
// Unequal we will say later and check if they lie in same connected component or different
// Unequals will be in different connected components.
// Just iterate over all inequalities from the input, and if for any inequality a != b, a and b are in the same connected component, the answer is NO, otherwise, the answer is YES.

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000001];
int vis[1000001];
int cc[1000001];                             //(IMP) contains the connected component in which element belongs to, say 3 belongs to 1st cc, 4 belongs to 5th cc
int curr_cc;                                 // This is current connected component number.

void dfs(int node){
   vis[node] = 1;                            // mark it visited
   cc[node] = curr_cc;                       // for a particular node we save the number of its connected component say 3rd component is of 4th node

   for(int child: adj[node]){
       if(vis[child] == 0){
           dfs(child);
       }

   }
}

int main(){
    ios_base::sync_with_stdio(0);            // to avoid TLE
    
    int t,n,k,u,v;                           // k is not number of edges here but no of relations given
    string op;                               // op = to read the operators =, != as strings 
    cin>>t;

    while(t--){
        cin>>n>>k;
        curr_cc = 0;

        vector<pair<int, int>> edgeList;     // to save the != relations

        for(int i=1; i<=n; i++){             // clearing after every test case
            adj[i].clear(), vis[i]=0;
        }
         
        for(int i=1; i<=k; i++){
            cin>>u>>op>>v;                   // 3 != 4 , integer then string then integer

            if(op == "="){
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            else
                edgeList.push_back({u, v});  // to keep record of the unequals. Makes pair of them & inserts in edgelist.

        }

        for(int i=1; i<=n; i++){
            if(vis[i] == 0){                 // if ith node is not visited ie it belongs to a new connected component
                curr_cc++;
                dfs(i);
            }
        } 


        bool flag = true;

        for(int i=0; i<edgeList.size(); i++){
            u = edgeList[i].first;
            v = edgeList[i].second;

            if(cc[u] == cc[v]){              // u and v are not equal hence they should lie in different connected components(cc). Here it says if cc of a & b are same.
                flag = false;
                break;
            }
        }

        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;   
    }
    return 0;
}

