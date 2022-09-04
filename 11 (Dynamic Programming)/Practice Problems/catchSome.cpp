https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050ff2/0000000000150a0d

https://youtu.be/ljLIrNKLANE

// Observations:
1) Never repeat the same t-shirt.
2) Except last trip, all trips are round trips.
3) Wearing the shirt Ci if right extreme position you go to is R, then at position R, there is a dog of color Ci.

// C1, C2, C3, C4.... Cs
// Using the color C1 to observe 0 or 1 or 2 or... last dog.

p[i][j] means jth dog having color i.


last fix bool 0 means I havent used my one way tshirt yet.
last fix bool 1 means now all the tshirts have to be round trips.

// recurrence
dp(i, x, bool) means To observe x dogs using Ci to Cs tshirts and one way tshirt is not used or used depending on above definition.
dp(i, x, 1) = 2*p[i][j] + dp(i+1, x-j, 1)  // among all j we will take min
dp(i, x, 0) = 2*p[i][j] + dp(i+1, x-j, 0)  // if the ith color is round trip, then bool value will not change
        or  = p[i][j] + dp(i+1, x-j, 1)    // ith trip is the last trip, no other color can be last trip hence bool value will change.


// TC = O(N^2)

// CODE:

#include<bits/stdc++.h>
#define fr(a,b) for(int i = a; i < b; i++)
using namespace std;
 
vector<int> dogs[1001];
int dp[1001][1001][2];
 
void whatsWithThisOPFormat(){
    static int tno = 1;
    cout << "Case #" <<tno++ <<": ";
}
 
int solve(int i, int x, bool last_fix)
{
    if(x <= 0)return 0;
    if(i == 1001)return 1e9;  // unable to visit the required dogs using all the colors.
 
    if(dp[i][x][last_fix] != -1)
        return dp[i][x][last_fix];
 
    int ans = solve(i + 1, x, last_fix);      // I have planned simply to not take the ith color.
    for(int j = 0; j < dogs[i].size(); j++) {
        if(!last_fix)
            ans = min(ans, dogs[i][j] + solve(i+1, x-(j+1), 1));       // If it is possible to have a one way trip
        ans = min(ans, 2*dogs[i][j] + solve(i+1, x-(j+1), last_fix));  // You observe j dogs using ith tshirt, the time will be twice
    }
 
    return dp[i][x][last_fix] = ans;
}
 
int main() {
   int t,n,k;
   cin >> t;
   while(t--)
   {
        cin >> n >> k;
        vector<int> pos(n), colors(n);
        memset(dp, -1 ,sizeof dp);
        fr(0,1001) dogs[i].clear();
 
        fr(0,n) cin >> pos[i];
        fr(0,n) cin >> colors[i];
 
        fr(0,n) dogs[colors[i]].push_back(pos[i]);
        fr(0,1001) sort(dogs[i].begin(), dogs[i].end());
 
        whatsWithThisOPFormat();
        cout << solve(1,k,0) << '\n';
   }
   return 0;
}

