#include <bits/stdc++.h>
#include <list>
#include <stack>
using namespace std;
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
#define rep(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define ini(a, i) memset(a, i, sizeof(a))
#define sortall(x) sort(all(x))
#define rev(x) reverse(all(x))
#define PI 3.1415926535897932384626
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pl; 
typedef vector<ll> vi;
typedef vector<ll>  vl;
typedef vector<pii> vpii;
typedef vector<pl>  vpl;
typedef vector<vi>  vvi;
typedef vector<vl>  vvl;
const int INF = 1000000007;
const long long INFLL = (ll)INF * (ll)INF;
#define ld long double
const ld EPS = 10e-9;
const unsigned int M = 1000000007; 
#define int long long 
long double pi = 2*acos(0.0);
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
//s.substr(start index,length)
//lower_bound
//upper_bound
//*max_element
//*min_element
//continue
// vector<vector<int>> vec( n , vector<int> (m, 0));
// in a matrix if i select cell a(i,j) then the parity of (i+j) all the adjacent cells is opposite
//check cube root
// double b=cbrt(x-a*a*a);
// if(floor(b)==b)
// {
//   yes;return;
// }
//const bool is_in = container.find(element) != container.end();
int chalao=10000000;
// x has cbrt(x) divisors
// pass string by reference
// PREFER DP[MIN_SIZE][MAX_SIZE] OVER DP[MAX_SIZE][MIN_SIZE]
int N=1000007;
int primes[1000007];
int pref[1000007]={0};
void make()
{
  for (int i = 0; i < N; ++i)
  {
  // cout<<"hi";
    primes[i]=1ll;
  }
  primes[0]=0;
  primes[1]=0;
  for (int i = 2; i < N; ++i)
  {
    if(primes[i])
    {
      for (int j = i*i; j < N; j+=i)
      {
        primes[j]=0;
      }
    }
  }
  for(int i=2;i<N;i++){pref[i]=pref[i-1]+primes[i];}
}

void solve()  
{    
  int n;
  cin>>n;
  cout<<pref[n]-pref[(int)sqrt(n)]+1<<endl;
}


   int32_t main()
   {
       clock_t start, end;
       start = clock();
         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
           #ifndef ONLINE_JUDGE
           freopen("input.txt", "r", stdin);
           freopen("output.txt", "w", stdout);
           #endif // ONLINE_JUDGE
       // sieve();
         // initalize();
       int t=1;
       make();
        cin>>t;
       while(t--)
        solve();
      // cout<<primes.size();

       //cout<<t1;
       end = clock(); 


      //  // Calculating total time taken by the program. 
      // double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
      // cout << "\nTime taken by program is : " << fixed << time_taken << setprecision(5); 
      // cout << " sec " << endl; 

       return 0;
   }