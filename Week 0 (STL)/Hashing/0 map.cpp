
// ************************************************************
// Unordered set just had keys
// Uordered map stores key & value pair in random order // uses hashing under the hood // O(1) operations
// Map uses logn height balanced tree under the hood , so sorted & O(logn) operations, all standard commands are same as unordered map

#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string, int> umap;  // key is string, value is int
    umap["shashwat"] = 44;            // map[key] = value  (syntax)
    umap["hello"] = 55;
    umap["world"] = 66;

    for(auto x: umap){
        cout<<x.first <<" "<< x.second <<endl;   // will print in a random order (though that order wont change on everytime running the code)
    }

    // alternate method
    for(auto itr = umap.begin(); itr!= umap.end(); itr++){
        cout<<itr->first<<" "<<itr->second<<endl;
    }

    string key="hello";
    if(umap.find(key)!= umap.end()){
        cout<<"Key found"<<endl;
    }
    else
        cout<<"key not found"<<endl;

    umap.insert(make_pair("mobile", 24000));

    for(auto itr = umap.begin(); itr!= umap.end(); itr++){
        cout<<itr->first<<" "<<itr->second<<endl;
    }

     int arr[] = {7,1,0,3,5,0,1,3,2,5,7,3,8,9,9};
     unordered_map<int,int> umaped;

     for(int i=0; i<15; i++){
         umaped[arr[i]]++;               // it will store the keys and its count, coz whenever we insert a key its corresponding value is 0 by default.
     }
     
     for(auto itr = umaped.begin(); itr!= umaped.end(); itr++){
        cout<<itr->first<<" "<<itr->second<<endl;
    }
}


// Example to create a phonebook

#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string, list<string>> phonebook;         // can use list or vector of strings, we want any no of numbers to be associated with a person can be stored
                                                 // map coz a phonebook is sorted in lexicographical order.
    phonebook["Shashwat"].push_back("111111");   // key1 = Shashwat, value = the numbers
    phonebook["Shashwat"].push_back("111112");
    phonebook["Shashwat"].push_back("111113");

    phonebook["Lala"].push_back("5611112");      // key2 = Lala, value = the numbers
    phonebook["Lala"].push_back("5711112");
    phonebook["Lala"].push_back("5811112");


}


// To check if there is a cycle in the linkedlist 

unordered_map< node*, bool > hashtable;  // can be used

// Code:
bool containsCycle(node *head){
    unordered_map< node*, bool> hashtable;

    node *temp = head;
    while(temp != NULL){
        if(hashtable.count(temp) != 0){
            return true;
        }

        hashtable[temp] = true;
        temp = temp->next;
    }
    return false;
}
