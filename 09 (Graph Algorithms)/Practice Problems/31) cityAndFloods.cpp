https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/

// Using DSU to find connected components
// Can use rank or size for union

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int size[N];
int parent[N];

void make(int v){
	parent[v] = v;
	size[v] = 1;	
}

int find(int v){
	if(v==parent[v]) return v;
	return parent[v] = find(parent[v]);
}

void Union(int a, int b){
	a = find(a);
	b = find(b);

	if(a!=b){
		if(size[a] < size[b]) swap(a, b);  // If a is smaller I swap to make it bigger tree
		parent[b] = a;       // I always want to attach b below a
		size[a] += size[b];
	}
}

int main() {
	int n, k;
	cin>>n>>k;
	for(int i=1; i<=n; ++i){
		make(i);
	}

	while(k--){
		int u, v;
		cin>>u>>v;
		Union(u, v);
	}
	
	int ct = 0;
	for(int i=1; i<=n; ++i){
		if(find(i)==i) ct++;
	}
	cout<<ct<<endl;
}