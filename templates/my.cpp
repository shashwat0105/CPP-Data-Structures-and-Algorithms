#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
int inf = 1e18;
int mod= 1e9+7; 

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  

    int t=0; 
    cin>>t; 
    while(t--){
        int n=0;
        cin>>n;
        vector<int>v(n,0);  
        for(int i=0;i<n;i++)cin>>v[i];
      
    } 

    return 0;
}


// *************** another
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
int inf = 1e18;
int mod= 1e9+7; 
//  vector< vector<pair<int,int>>>vvp(n,vector<pair<int,int>>(n,{0,0}));
//vector<vector<int>>vv(n,vector<int>(n,0));    
int32_t main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
 //vector<vector<int>>v(n,0);
  int t=0; 
  cin>>t; 
  while(t--){
      int n=0;
      cin>>n;
      vector<int>v(n,0);  
      for(int i=0;i<n;i++)cin>>v[i];
      
  }
 
 // cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
  return 0;
}

//********************** another
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
  
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ll test=1;
//cin>>test;
  while(test--)
  {
    solve();
  }
  return 0;
}

//**********************************************
Other functions code GCD etc

#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <chrono>
#include <complex>
#define ll long long int
#define mod 1000000007
#define inf 1000000000000000001 
 
using namespace std; 
 
ll lcm(ll a, ll b)
{
    return a*b/__gcd(a, b);
}
ll expo(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
void extendgcd(ll a, ll b, ll*v)
{
    if (b == 0)
    {
        v[0] = 1;
        v[1] = 0;
        v[2] = a;
        return ;
    }
    extendgcd(b, a % b, v); 
    ll x = v[1];
    v[1] = v[0] - v[1] * (a / b);
    v[0] = x; 
    return;
}
ll mminv(ll a, ll b)
{
    ll arr[3];
    extendgcd(a, b, arr);
    return arr[0];
}
ll mminvprime(ll a, ll b)
{
    return expo(a, b - 2);
}
ll mod_add(ll a, ll b, ll m = mod)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m = mod)
{
    a = a % m; b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m = mod)
{
    a = a % m; b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m = mod)
{
    a = a % m; b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
ll fibonacci(ll n)
{
    ll number = n;
    if (n % 2 == 0)
    {
        number /= 2;
        while (n % 2 == 0)
        n /= 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            while (n % i == 0)n /= i;
            number = (number / i * (i - 1));
        }
    }
    if (n > 1)
    number = (number / n * (n - 1));
    return number;
}
 
 
 
void solve()
{
    
}
 
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll tc = 1;
    //cin >> tc;
 
    for (ll i = 1; i <= tc; i++)
    {
        solve();
    }
 
    return 0;
}