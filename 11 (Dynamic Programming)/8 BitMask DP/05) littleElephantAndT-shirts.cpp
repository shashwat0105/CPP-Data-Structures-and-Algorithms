https://www.codechef.com/problems/TSHIRTS

https://youtu.be/Smem2tVQQXU

// dp(i, mask): either I assign ith tshirt to a guy or I ignore it. & mask represents here the number of people not assigned a tshirt yet.

// dp(i, mask) = dp(i+1, mask)  + sigma for all valid j ( dp(i+1, mask 's turn ith bit off) )

valid j means: 1) j should be available 2) j should own the ith tshirt.

SC = O(No of tshirts*2^N)

TC = O(100 * 2^N * N)

// Code

#include<bits/stdc++.h>
using namespace std;
#define FT() int t; cin>>t; while(t--)
#define ll long long
#define ull unsigned long long
const ll mod = 1e9+7;

int n;
int dp[101][1025];
// ith shirt owned by jth guy
int own[100][11];

// this function will return the ways to assign any shirt to
// a person not assigned any shirt in mask and he owns the shirt
int getCombinations(int shirt, int mask, vector<vector<int>> &shirts){
	if(mask == (1<<n)-1){
		// all persons have been assigned a shirt 
		return 1;
	}

	if(shirt >= 100){
		return 0;
	}

	if(dp[shirt][mask] != -1){
		return dp[shirt][mask];
	}

	int combinations = 0;

	//calculate total ways the current shirt can be wore by 
	// all the persons in the mask that are not assigned any shirt yet 
	// and owns the shirt

	for(int person=0; person<n; person++){
		if(!(mask&(1<<person)) and own[shirt][person]){
			combinations = (combinations%mod) + getCombinations(shirt+1, mask|(1<<person), shirts);
		}
	}

	// consider if this shirt is not owned by anyone then we need
	// to call for other shirts or if this shirt is not wore by any person
	// even if it is owned by someone (for eg. if A owns this but he wears some
	// other shirt instead of this)
	combinations = (combinations%mod) + getCombinations(shirt+1, mask, shirts);
	return dp[shirt][mask] = (combinations%mod);
}

void solve(){
	cin>>n;

	memset(dp, -1, sizeof(dp));
	memset(own, 0, sizeof(own));
	vector<vector<int>> shirts(n);
	for(int person=0; person<n; person++){
		while(true){
			int id;
			cin>>id;
			// for 0 based indexing
			id -= 1;

			shirts[person].push_back(id);
			own[id][person] = 1;
			if(cin.peek() == '\n'){
				break;
			}
		}
	}

	cout<<getCombinations(0, 0, shirts)<<endl;
}

int main(){
// 	#ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// 	#endif

	FT()
		solve();

	return 0;
}
