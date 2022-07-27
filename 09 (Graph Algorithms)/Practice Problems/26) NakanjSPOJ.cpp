https://www.spoj.com/problems/NAKANJ/

// Ek particular position se mai jaha jaha ja skta hu, that will be an edge

/*
     ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् |
     उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात् ||
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
// const int INF = 1e9+10;
vector<int> adj[N];

int vis[8][8];
int level[8][8];

int getX(string s){                     // To get x coordinate from the given notation ie string
    //cout<<s<<"\n";
	return s[0]-'a';
}

int getY(string s){                     // To get y coordinate from the given notation ie string
    //cout<<"y: "<<s[1]-'1'<<"\n";
        //cout<<s<<"\n";
	return s[1]-'1';
}

bool isValid(int x, int y){              // The coordinate should lie within the chessboard
	return x>=0 && y>=0 && x<8 && y<8;
}

vector<pair<int, int>> movements = {
	{-1, 2}, {1, 2},
	{-1, -2}, {1, -2},
	{2, -1}, {2, 1},
	{-2, -1}, {-2, 1},
};

int bfs(string source, string dest){
	int sourceX = getX(source);
	int sourceY = getY(source);
	int destX = getX(dest);
	int destY = getY(dest);

	queue<pair<int, int>> q;   // as bfs will run in a matrix
	q.push({sourceX, sourceY});
	vis[sourceX][sourceY] = 1;
// 	level[sourceX][sourceY] = 0;
	while(!q.empty()){
		pair<int, int> v = q.front();
		int x = v.first, y = v.second;
		if(x==dest[0]-'a' && y==dest[1]-'1') return level[x][y];    // This line is not needed though

		q.pop();
		for(auto movement : movements){
			int childX = movement.first + x;
			int childY = movement.second + y;
			if(!isValid(childX, childY)) continue;  // If it is not valid
			if(!vis[childX][childY]){               // If it is not visited
				q.push({childX, childY});
				level[childX][childY] = level[x][y] + 1;
				vis[childX][childY] = 1;
			}
		}
// 		if(level[destX][destY] != INF) break;    // ie a value has been given to destination no need to further run dfs (This is an optimisation u may or maynot perform)
	}
	return level[destX][destY];
}

void reset(){   // since there are multiple test cases we need to reset out matrices
	for(int i=0; i<8; ++i){
		for(int j=0; j<8; ++j){
			level[i][j]=0;
			vis[i][j]=0;
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin>>t;
	while(t--){
		reset();
		string s1, s2;
		cin>>s1>>s2; 
		cout<<bfs(s1, s2)<<"\n";
	}
	return 0;
}
