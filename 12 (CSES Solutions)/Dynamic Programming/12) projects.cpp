https://cses.fi/problemset/task/1140

// If the rewards were same, then it would become activity selection problem(Greedy)

// Brute force method is by trying all the valid subsets.

// Optimising:
// Sorting the intervals according to end point.
// Then from the last interval thinking whether to pick or to not pick into our subset.

// p1 p2 p3...pj... pn
// I have to find the largest j such that end point of j < start point of current nth or ith project.

// DP State
dp(i) = Largest possible reward for [p1, p2, p3..pi]
dp(n) is our ans

dp(i) = max{ dp(i-1), ri + dp(j) }  // not take, take

// For finding this j we will use some kind of binary search. (Lower bound then one iterator back)

// Overall there are N states and for every state we will take logn time to find the correct j.
// So, TC = O(nlogn)

// Two projects cannot have same endpoint that will be included in the subset


#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct project{
    int st, ed, rwd;
};

bool cmp(project &p1, project &p2){
    return p1.ed < p2.ed;
}

int findBestj(vector<int> &endPts, int val){
    auto it = lower_bound(endPts.begin(), endPts.end(), val);
    if(it == endPts.begin()) return 0;
    else{
        it--;  // we move one step back, that will definitely be smaller.
        return 1+distance(endPts.begin(), it); // distance function returns: The number of elements between first argument and second argument.
    }
}


ll solve(vector<project> &v){
    int n = v.size();
    ll dp[n+1];
    dp[0] = 0;

    vector<int> endPts;
    for(int i = 1; i < v.size(); i++){
        endPts.push_back(v[i].ed);      // creating a vector that will store the end points.
    }

    for(int i=1; i<n; ++i){
        ll op1 = dp[i-1];
        ll op2 = v[i].rwd;
        // find largest j such that end point of j < start pt of i
        int j = findBestj(endPts, v[i].st);  // samajh nahi aa rhaa kaise nikalunga function bana lia
        op2 += dp[j];
        dp[i] = max(op1, op2); 
    }
    return dp[n-1];
}


int main(){
    ll n;
    cin>>n;
    vector<project> v(n+1);

    for(int i=1; i<n+1; ++i){                  // making 1 based indexing
        cin>> v[i].st >> v[i].ed >> v[i].rwd;
    }   
    sort(v.begin(), v.end(), cmp);

    cout<<solve(v);
}
