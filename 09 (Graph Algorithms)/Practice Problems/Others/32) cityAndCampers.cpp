https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers/

https://youtu.be/L8SuKrpNc2Q

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int size[N];
int parent[N];
multiset<int> sizes;

void make(int v){
	parent[v] = v;
	size[v] = 1;	
	sizes.insert(1);
}

int find(int v){
	if(v==parent[v]) return v;
	return parent[v] = find(parent[v]);
}

void merge(int a, int b){
	sizes.erase(sizes.find(size[a]));  // Basic concept :we should use sizes.erase(sizes.find(size[a])) ie using iterator to delete, since sizes.erase(size[a]) using value to delete will erase all the occurences
	sizes.erase(sizes.find(size[b]));

	sizes.insert(size[a] + size[b]);
}
void Union(int a, int b){
	a = find(a);
	b = find(b);

	if(a!=b){
		if(size[a] < size[b]) swap(a, b);  // If a is smaller I swap to make it bigger tree
		parent[b] = a;       // I always want to attach b below a
		merge(a, b);
		size[a] += size[b];
	}
}

int main() {
	int n, q;
	cin>>n>>q;
	for(int i=1; i<=n; ++i){
		make(i);
	}

	while(q--){
		int u, v;
		cin>>u>>v;
		Union(u, v);
		if(sizes.size()==1){   // there is only one element in the multiset
			cout<<"0"<<endl;
		}
		else{
			int mn = *(sizes.begin());
			int mx = *(--sizes.end());
			cout<<mx-mn<<endl;
		}
	}
}