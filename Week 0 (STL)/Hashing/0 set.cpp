// Unordered set - uses hash table under the hood
// Here, keys are hashed into indices of a hash table so that insertion is always randomised
// All operations on unordered set takes O(1) average TC.

// Set VS Unordered Set
// Set - keys stored in ordered fashion. Internally uses RED BLACK TREE(Self balancing tree). TC = O(log n).
// Unordered set - keys stored in unordered fashion. Internally uses Hashing. TC = O(1).

#include <bits/stdc++.h>
using namespace std;

int main(){

    unordered_set<int> s;
    s.insert(10);
    s.insert(50);
    s.insert(5);
    s.insert(20);
    s.insert(20);                                    // duplicacy is ignored

    for(auto it = s.begin(); it!= s.end(); it++){
        cout<<(*it)<<endl;                           // will print in a random order: 20,5,10,50
    }

    cout<<"No of elements: "<<s.size()<<endl;        // size  = 4     

    // s.clear();  // will clear the set
    // cout<<"No of elements: "<<s.size()<<endl;     // size = 0  

    int key = 25;
    if(s.find(key) == s.end()){
        cout<<"key not found"<<endl;
    }
    else{
        cout<<"key found"<<endl;
    }


    int deleted_key = 50;
    s.erase(deleted_key);
    for(auto it = s.begin(); it!= s.end(); it++){
        cout<<(*it)<<endl;                           
    }


    int key=20;
    if(s.find(key) == s.end()){       // if the iterator of the key is equal to iterator of end
        cout<<"key not found"<<endl;

    }
    else{
        auto temp=s.find(key);
        s.erase(temp);               // if the key is found we want to erase that key.(method 2 to delete)
    }


    if(s.count(5)){                  // count function returns 1 or 0 depending on if its present or not.
        cout<<"key found"<<endl;
    }
    else
        cout<<"key not found"<<endl;
}

