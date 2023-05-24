https://leetcode.com/problems/design-hashset/

// Important Interview Question

// METHOD 1  (Sirf yeh karne se interview pass ni hoga)
// Since all values are in the range of [0, 1000000], create an array with length 1000001, which has boolean type.
// If a value is added, set the element at the corresponding index in the array to true. If a value is removed, 
// set the element at the corresponding index in the array to false.
// For the contains function, simply return the element at the corresponding index in the array.
// where true means the element exists in the HashSet and false means the element does not exist in the HashSet.

class MyHashSet {
public:
    vector<int> m;
    int siz;
    MyHashSet() {
        siz = 1e6+1;   // 0 to 10^6 both inclusive so we do +1
        m.resize(siz);
    }
    
    void add(int key) {
        m[key] = 1;
    }
    
    void remove(int key) {
        m[key] = 0;
    }
    
    bool contains(int key) {
        return m[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */


// METHOD 2
// The range 10^7 se jada ka vector ni bana skte so that will be the bottleneck, so will try to generalise it

// hashing technique, in which we try to reduce collisions

// Chaining technique, ie we will use a chain or LL for collisions

// We will use DLL because we want to perform delete operation efficiently and easily.

0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
1             1               1
1             1               1
1                             1

// Also we need to follow the property of the set ie it stores unique values only

class MyHashSet {
public:
    vector<list<int>> m;                    // using vector of list  // can use vector of vector as well.
    int siz;
    MyHashSet() {
        siz = 100;                          // we can change this according to our wish say 100, 1000, 1e6 etc, more the size less collisions but more memory; 10007(nearest prime of size of array)
        m.resize(siz);
    }
    
    int hash(int key){
        return key%siz;
    }
    
    list<int>::iterator search(int key){    // to search in our data structure, will return iterator to number present else iterator to m.end()
        int i = hash(key);
        return find(m[i].begin(), m[i].end(), key);   // 
    }
    
    void add(int key) {
        if(contains(key)) return;           // ie the number is already present
        int i = hash(key);                  // to find the index where it will be added
        m[i].push_back(key);                // insert key in the list at ith index.
    }
    
    void remove(int key) {
        if(contains(key)){
            int i = hash(key);
            m[i].erase(search(key));
        }
    }
    
    bool contains(int key) {
        int i = hash(key);
        if(search(key) != m[i].end()) return true;
        else return false;
    }
};


// Load factor:
LF = n/k
n = number of entries occupied in the hash table
k = number of buckets

// To research more methods of this question on YT and LC discuss of this ques (currently method 2 is also decent)

