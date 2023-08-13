// https://www.hackerrank.com/challenges/and-product/problem

// To find bitwise & of all long integers from a to b
// Say 12 to 15
// 12: 1100
// 13: 1101 
// 14: 1110
// 15: 1111
// Res = 1100 = 12  // if all the bits are set then ith bit of res is set

// Observation
// 00 : 0000
// 01 : 0001
// 02 : 0010
// 03 : 0011
// 04 : 0100
// 05 : 0101
// 06 : 0110
// 07 : 0111

// ith bit have 2^i consecutive 1's and 0's (alternate 0, 2 chhod k, then 4 chhod k etc the way we make truth table)
// Now, d = no of elements in the range ie b-a+1
// Claim:- If d > 2^i, then ith bit will be zero (coz beech m kahi 0 aa jaega, hence & will be 0)
// Claim2:- If d<= 2^i, then ith bit of result is set when ith bit of both a and b is set (ie 1 se shuru and 1 pe khatam beech mein no 0 came)

// ll is long long 
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
lli res;
int main()
{
    lli a , b , t , res , x;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        lli d = b - a;
 
        lli res = 0;
        lli f   = 1;
 
        for(int i=0;i<32;i++)
        {
            if(d > (f << i)) continue; // do nothing when d is > 2^i
            else
            {
                if((a & (f << i)) && (b & (f << i))) // both ith bit of a and b is set
                res += f << i;  // make the ith bit of res as a set bit
            }
        }
 
        cout<<res<<endl;
    }
}
