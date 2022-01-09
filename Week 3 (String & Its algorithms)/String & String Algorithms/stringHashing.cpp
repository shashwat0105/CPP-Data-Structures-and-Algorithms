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


