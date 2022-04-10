// https://www.spoj.com/problems/PPATH/

// https://youtu.be/eYf4NFc2s1w

// Given two 4 digit prime numbers A and B, To find min no of operations to convert A to B by changing 1 digit a time.
// And the in between numbers must also be prime.

// 1033  -> 1033  ->  8179
//          1733
//          3733
//          3739
//          3779
//          8779
//          8179

// We will find all 4 digit prime numbers and connect an edge between them if they differ by a single digit.
// Now from any prime number(ie any node) to any other prime number(ie other node) shortest distance can be found by BFS.

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
vector<int> primes;                             // vector array to generate list of prime numbers

int dist[100001], vis[100001];                  // distance and visited array

bool isPrime(int n){
    for(int i=2; i*i<=n; i++){
        if(n%i == 0) return false;

        return true;
    }
}

bool isValid(int a, int b){                     // will return true if one position differs.
    int cnt = 0;                                // will keep count of how many positions differs.

    while(a>0){                                 // a contains atleast one digit 
        if(a%10 != b%10) cnt++;                 // ie last digit of a is not equal to last digit of b

        a/=10, b/=10;                           // 1733 then 173 then 17 then 1 while we compare the last digit
    }

    if(cnt==1) return true;                     // they differ at one position only

    else return false;
}

void buildGraph(){
    for(int i=1000; i<=9999; i++){
        if(isPrime(i))
            primes.push_back(i);                // pushing all 4 digit prime numbers in primes vector
    }

    for(int i=0;i<primes.size();i++){
        for(int j=i+1;j<primes.size();j++){     // taking all the combinations of prime numbers from the array of prime numbers
            int a = primes[i];
            int b = primes[j];

            if(isValid(a,b)){                   // this function will return true if a and b differ by 1 digit only
                adj[a].push_back(b);            // building the graph
                adj[b].push_back(a);
            }
        }
    }
}

void bfs(int src){
    queue<int> q;
    q.push(src);

    dist[src] = 0;                                         
    vis[src] = 1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int child : adj[curr]){
            if(vis[child] == 0){
                vis[child] = 1;
                dist[child] = dist[curr]+1;
                q.push(child);
            }
        }
    }

}

int main(){
    int t,u,v;
    cin>>t;
    while(t--){
        cin>>u>>v;

        buildGraph();                                        // A common graph of 4 digit prime numbers.

        for(int i=1000; i<=9999; i++) dist[i]=-1, vis[i]=0;  // indicating that no number is recheable from a initially, & initialising visiting array to 0 after every test case.
        bfs(u);

        if(dist[v]== -1){
            cout<<"Impossible"<<endl;
        }
        else
            cout<<dist[v]<<endl;
    }

    return 0;
}
