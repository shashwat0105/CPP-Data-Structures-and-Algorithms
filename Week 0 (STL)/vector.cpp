void printVec(vector<int> v){            // v yaha copy ban rha hai (expensive operation)
    for(int i = 0; i < v.size(); i++){
        cout << v[i] <<" ";
    }
    cout << endl;
}
vector<int> v2=v;                        // O(n) one one element is copied
v2.push_back(5);
printVec(v);
printVec(v2);
// here v2 is copy of v, changes in v2 won't affect v

void printVec(vector<int> &v){           // exact vector is passed
    for(int i = 0; i < v.size(); i++){
        cout << v[i] <<" ";
    }
    cout << endl;
}
vector<int> v2=v;                        // copy is made here
v2.push_back(5);
printVec(v);
printVec(v2);


void printVec(vector<int> &v){           // exact vector is passed
    for(int i = 0; i < v.size(); i++){
        cout << v[i] <<" ";
    }
    cout << endl;
}
vector<int> &v2=v;                       // copy isn't made here
v2.push_back(5);
printVec(v);
printVec(v2);


// ****************************

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    v.reserve(100);                      // This would make capacity to be fixed = 100, instead of doubling everytime when there is short of space.
    
    int n; 
    cin>>n;
    
    for(int i=0; i<n; i++){
        int no;
        cin>>no;
        v.push_back(no);
        cout<<"Capacity "<<v.capacity()<<" Size "<<v.size()<<endl;
    }
    return 0;
}

// ****************************
