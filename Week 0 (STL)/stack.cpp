.pop();
.push()
.top();

|   4    |
|   3    |
|   2    |
|   1    |
|________|

Output :1 2 3 4

#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<string> books;

    books.push("Learn C++");
    books.push("Learn JAVA");
    books.push("Learn Python");

    while(!books.empty()){
        cout<<books.top()<<endl;
        books.pop();
    }
}
