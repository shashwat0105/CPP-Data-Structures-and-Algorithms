// FIFO

#include <iostream>
#include <stack>
using namespace std;

int main(){
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
}
