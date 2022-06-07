Application of TRIE Data structure
1) Auto completion
2) Spell checkers
3) Longest prefix matching
4) String search in O(L) time where L is the length of the string to be searched

Trie DS is k - n ary tree
"Hence visit TRIE again after studying TREES"

https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/tutorial/

// NODE STRUCTURE
int const SIZE= 26

struct node{
    int count;
    bool endOfWord;

    node* arr[size];

}

CODE OF TRIE

#include<bits/stdc++.h>
using namespace std;

const int SIZE = 26;                            // assumed we have 26 lower case alphabets

struct node{
	bool endOfWord;
	node* ar[SIZE];
};

node* getNode(){                               // Does the initilisation part and returns the node                  
	node* n = new node;
	n->endOfWord = false;
	
	for(int i=0;i<SIZE;i++)
	n->ar[i] = NULL;
	
	return n;
}

void insert(node *root , string st){            // code to insert in a trie
	node *tempRoot = root;                      // you always make a copy of root node to avoid any direct changes to the root.
	
	for(int i=0;i<st.size();i++){
		int index = st[i] - 'a';
		
		if(tempRoot->ar[index] == NULL)
		tempRoot->ar[index] = getNode();
		
		tempRoot = tempRoot->ar[index];
	}
	
	tempRoot->endOfWord = true;
}

bool search(node *root , string st){            // code to search a string in a trie
	node *tempRoot = root;
	
	for(int i=0;i<st.size();i++){
		int index = st[i] - 'a';
		
		if(tempRoot->ar[index] == NULL)
		return false;
		
		tempRoot = tempRoot->ar[index];
	}
	
	return tempRoot->endOfWord;
}

int main(){
	node *root = getNode();
	
	int n , code;
	string st;
	
	while(1){
		cin>>code;
		
		if(code == 1){
			cout<<"Enter string to insert\n";
			cin>>st;
			insert(root , st);
		}
		else
		if(code == 2){
			cout<<"Enter string to search\n";
			cin>>st;
			cout<<search(root , st)<<endl;
		}
		else
		break;
	}
}



// Kabhi future m solve krne ka man ho toh kar lena
https://codeforces.com/problemset/problem/706/D
Solution: https://youtu.be/aOFhnhsuF0k?t=5419          (Trie tutorial containing this as a subpart)


