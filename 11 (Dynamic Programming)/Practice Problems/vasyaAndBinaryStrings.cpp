https://codeforces.com/problemset/problem/1107/E

Observations:
// G1G2G3... groups of same elements.
// Claim: Either do not touch a group, or delete it entirely.

/*
*   author: kartik8800
*/

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

ll bestLen[102];
ll dp[102][102][102];

ll solve(vector<int>& groups, int i, int j, int extra){
    if(i > j)return 0;
    if(dp[i][j][extra] != -1)return dp[i][j][extra];


    ll answer = bestLen[groups[i] + extra] + solve(groups, i+1, j, 0);
    for(int group = i + 2; group <= j; group += 2){
        answer = max(answer,
                solve(groups, i + 1, group - 1, 0) + solve(groups, group, j, extra + groups[i]));
    }

    return dp[i][j][extra] = answer;
}

void prepareBestLen(vector<int>& cost){
    memset(bestLen, 0, sizeof bestLen);
    memset(dp, -1, sizeof dp);
    for(int len = 1; len < cost.size(); len++){
        for(int cut = 1; cut <= len; cut++){
            bestLen[len] = max(bestLen[len], cost[cut] + bestLen[len - cut]);
        }
    }
}

int main() {
   fast_io;
   int t = 1; //cin >> t;
   while(t--){
        int n; cin >> n;
        string s; cin >> s;
        vector<int> cost(n + 1); fr(1, n + 1)cin >> cost[i];

        prepareBestLen(cost);
        vector<int> groups;

        int consec = 0;
        rep(i, 0, s.length()){
            if(i == 0)
                consec++;
            else{
                if(s[i] == s[i-1])
                    consec++;
                else{
                    groups.push_back(consec);
                    consec = 1;
                }
            }
        }
        groups.push_back(consec);
        //for(int sz: groups)cout << sz << ' ';
        cout << solve(groups, 0, (int)groups.size() - 1, 0);
   }
   return 0;
}
