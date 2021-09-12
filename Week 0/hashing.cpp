// technique to uniquely identify a specific object from a group of similar objects.

// Large keys are converted into small keys(index) by using hash functions(some logic).

// Hash table (These maping of keys)
// bookew12 - 0
// hello13c - 1
// carl12cd - 2

// An array has both +ve and -ve numbers, elements in the range -MAX to +MAX (in this ques Max is not very large)
// To search a number:

// O(n) approach
// To traverse the whole array.

// O(1) approach
// Using hash table

// Since -ve no we will use a 2D array of size [MAX+1][2]
//     0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 ... MAX
// 0                                                    // mark in this row if the no is +ve
// 1                                                    // mark in this row if the no is -ve

// hash cant be used as a variable name coz its a reserved keyword.

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

bool hashTable[MAX+1][2];   // all have 0 value, coz global

bool search(int x){
    if(x>=0){
        if(hashTable[x][0]==1){
            return true;
        }
        else{
            return false;
        }   
    }
    else{
        x=abs(x);
        if(hashTable[x][1]==1){
            return true;
        }
        else{
            return false;
        }
    }
}

void insert(int a[], int n){
    for(int i=0;i<n; i++){
        if(a[i]>=0){
            hashTable[a[i]][0]=1;
        }
        else{
            hashTable[abs(a[i])][1]=1;
        }
    }
}
int main(){
    int arr[] = {-1,9,2,-5,3,1};
    int n = sizeof(arr)/ sizeof(arr[0]);
    insert(arr,n);

    int find = -3;
    if(search(find)){
        cout<<"Element is present"<<endl;
    }
    else{
        cout<<"Element is not present"<<endl;
    }
}
 
// **************************************************************
// Hashing: Search, Insert, Delete - O(1) & O(len) for string of length "len"


// Examples of Hash function

// H(large_key) = large_key%m // ideally we chose a prime no for m, to reduce collisons(multiple values mapping to same key)

// For strings, weighted sum
// str[] = "abcd"
// str[0]*x^0 + str[1]*x^1 + str[2]*x^2 + str[3]*x^3     // where str[0] is ASCII value of the element
 
// Chaining
// Hash(key) = key%7;
// Key = {50,21,58,17,15,49,56,22,23,25}

// 0  21 -> 49 -> 56
// 1  50 -> 15 -> 21
// 2  58 -> 23
// 3  17
// 4  25
// 5
// 6

// Load factor alpha = n/m = no of keys to be inserted/ no of slots in Hash table  // We aim to minimise alpha
 
// *************************************************

// Unordered set - uses hash table under the hood
// Here, keys are hashed into indices of a hash table so that insertion is always randomised
// All operations on unordered set takes O(1) average TC.

// Set VS Unordered Set
// Set - keys stored in ordered fashion. Internally uses RED BLACK TREE. TC = O(log n).
// Unordered set - keys stored in unordered fashion. Internally uses Hashing. TC = O(1).

#include <bits/stdc++.h>
using namespace std;

int main(){

    unordered_set<int> s;
    s.insert(10);
    s.insert(50);
    s.insert(5);
    s.insert(20);
    s.insert(20);                                   // duplicacy is ignored

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


// ************************************************************
// Unordered set just had keys
// Uordered map stores key, value pair in random order // uses hashing under the hood
// Rest the comparison bw map and unordered map is similar to above.

#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string, int> umap;  // key is string, value is int
    umap["shashwat"] = 44;
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

    
    
}

