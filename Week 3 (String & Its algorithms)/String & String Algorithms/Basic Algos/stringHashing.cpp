// Comparing two strings
// (a==b) is O(n) TC

// With hashing comparison TC is O(1) (Hence, Independent of the size of the string)

// String -> Hash Function -> Hash Value/Key (These keys are then compared)

// Hash Function here: Polynomial rolling hash

// 1) Same string must have same hash value
// 2) Same hash value means the string may be same (In case of collision(2 different string have same hash), we try to reduce collisons to 0)

// Polynomial rolling hash
// https://youtu.be/zURFD55lGBI

/// Hash Value = (s[0]*p^0 + s[1]*p^1 + s[2]*p^2 + ... s[n-1]*p^n)mod

// C++ code

#include<bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define mod 1000000007
using namespace std;

lli getHash(string key)
{
	lli value = 0;
	lli p = 31;
	lli p_power = 1;
	
	for(char ch : key){
		value = (value + (ch - 'a' + 1)*p_power) % mod;
		p_power = (p_power * p) % mod;
	}
	
	return value;
}

int main(){
	bool flag = 1;
	
	while(flag){
		string key;
		
		cout<<"enter key\n";
		cin>>key;
		
		if(key == "."){
			flag = false;
		}
		else{
			cout<<"Key : "<<key<<" Hash : "<<getHash(key)<<endl;
		}
	}
}


// SUBSTRING HASHING
// We will utilize prefix array for saving hash values of given string.
// dp[i] = hash value of substring (0, i)

// hash substing (L, R) = (dp[R] - dp[L-1])/p^L      for L>=1
//                      = (dp[R] - dp[L-1])*(modulo inverse of p^L)     

#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
lli dp[1000001];
lli inv[1000001];

lli power(lli a , lli n)
{
	lli result = 1;
	
	while(n)
	{
		if(n & 1) result = (result * a) % mod;
		
		n >>= 1;
		a = (a * a) % mod;
	}
	
	return result;
}


void init(string input_string)
{
	lli p = 31;
	lli p_power = 1;
	inv[0] = 1;
	dp[0] = (input_string[0] - 'a' + 1);
	
	
	for(int i=1;i<input_string.size();i++)
	{
		char ch = input_string[i];
		
		p_power = (p_power * p) % mod;
		inv[i] = power(p_power , mod - 2);
		
		dp[i] = (dp[i-1] + (ch - 'a' + 1)*p_power) % mod;
	}
}

lli substringHash(int L , int R)
{
	int result = dp[R];
	
	if(L > 0) result -= dp[L-1];
	
	result = (result * inv[L]) % mod;
	
	return result;
}

int main()
{
	string input_string;
	int tc , L , R;
	
	cin>>input_string;
	init(input_string);
	
	cin>>tc;
	
	REP(i , tc)
	{
		cin>>L>>R;
		cout<<substringHash(L , R)<<endl;
	}
}

