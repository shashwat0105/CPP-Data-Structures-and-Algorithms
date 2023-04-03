// You cannot use simple indexing method(used for simple array) to traverse through a complex container like tree, hashmap etc

// All STL containers by default are passed by value, so to update the changes in main, we pass by reference in function: array<int, 6> &arr

#include<bits/stdc++.h>
// #include<vector>
// #include<algorithm>
// #include<set>
// #include<map>
using namespace std;

bool f(int x, int y)                                          //comparator function which returns true and false
{
    return x>y;
}

void vectorDemo()
{
vector<int> A ={11, 13, 6, 16};
    cout << A[1];

    sort(A.begin(), A.end());                                 // O(NlogN)
    // 6, 11, 13, 16 , now we can apply binary search in O(log N) 


    bool isPresent = binary_search(A.begin(), A.end(), 13);   // true
    isPresent = binary_search(A.begin(), A.end(), 15);        // false

    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(125);
    // 6,11, 13, 16, 100, 100, 100, 100, 125

    vector <int>::iterator it = lower_bound(A.begin(), A.end(), 100);  //returns index of first element >= to element passed
    vector <int>::iterator it2 = upper_bound(A.begin(), A.end(), 100); // retuns index of > element passed
    // you can use the below 2 instead as well (auto is C++ intelligence)
    // auto it = lower_bound(A.begin(), A.end(), 100);
    // auto it = upper_bound(A.begin(), A.end(), 100);

    cout<<*it <<" "<<*it2<<endl;                              // prints value 
    cout<<it2 - it<<endl;                                     //4  we can find number of times an element is repeated.

    // sorting vector in reverse order
    sort(A.begin(), A.end(), f)                               //passing a comparator function f to control the ordering we want in this overloaded function

    // printing using iterator
    vector<int> :: iterator it3;

    for(it3=A.begin();  it3!=A.end(); it3++)
    {
        cout<<*it3<<" ";
    }
    // you can also print in this way
    // for(int x: A)
    // {
    //     cout<< x <<" ";
    // }

    // iterate on your vector simultaneously update the values iterate by reference 
    for(int &x :A)                                            //reference
    {
        x++;                                                  // any changes here made on x will be reflected on our vector.
        cout<<x<<" ";
    }
}

// We need a data structure such that we keep on inserting elements in logn time and performing 
// lower or upper bound in log n time, as everytime we insert a random number we need to sort in NlogN time. So, we use sets  
void setDemo()
{
    set<int>S;
    S.insert(1);                                              // logN time
    S.insert(2);
    S.insert(-1); 
    S.insert(-10);

    // beauty of Set, the elements inserted automatically get sorted 
    for(int x:S)
    {
        cout<<x<<" "<<endl; //   
    }

    auto it = S.find(-1);
    auto it2 = S.lower_bound(-1);                             //-1  See the difference in syntax from vector
    auto it3 = S.upper_bound(0);                              // 1
}

void mapDemo()
{
    map<int, int>A;                                           // mapping int to int
       
}

int main()
{
    
    setDemo();

    return 0;
}

// *********************************************************************************
// PAIR

// initilising
pair<string, int> hello("car", 5.6);

cout<< hello.first <<" "<< hello.second <<endl;

// or
pair<string, int> hello;
hello2 = make_pair(5, 5.6);                                   // using this way no need to declare type explicitly
hello = {2, 5};

cin>>hello.first>>hello.second;
cout<< hello.first <<" "<< hello.second <<endl;

// a use case of pair
int a[] = {1,2,3};
int b[] = {2,5,8};
pair<int, int> p_array[3];
p_array[0] = {1,2};
p_array[1] = {2,5};
p_array[2] = {3,8};

for(int i=0;i<3; i++){
    cout<<p_array[i].first<<" "<<p_array[i].second;
}



// *****************************

// You can swap two queues having same type but different size.

// front is at the leftmost, back is at the rightmost,, in queue and dequeue(double ended queue) : shown while printing.

// top is at the leftmost, bottom is at the rightmost in the stack : shown while printing


//*********************************
// CONTAINERS:
//  A) Sequential
//  - vectors
//  - stack
//  - queue
//  - pair (not a container)
//  B) Ordered (Value is stored in a sequence like ascending or descending order)
//  - map
//  - multimap
//  - set
//  - multiset
//  C) Unordered (used in hashing algorithms to store things)
//  - unordered map
//  - unordered set

// NESTED CONTAINERS: (used to solve complex problems) (like nested loops)
// For example
// vector<vector<int>>
// map<int,vector<int>>
// set<pair<int,string>>
// vector<map<int,set<int>>>

// ITERATORS
// To point to memory address of containers

//***************************************************************

We can use .insert(v.beigin()+3) etc to insert anywhere in the DS
We can use .erase(v.beigin())  etc to erase an element or elements in a range anywhere in the DS

rbegin()  points to last iterator in a vector etc. Used to reverse sort as well.
https://cplusplus.com/reference/vector/vector/rbegin/


// STL Good ones:
https://github.com/MAZHARMIK/Cpp-STL-Quick-Help/blob/main/README.md
