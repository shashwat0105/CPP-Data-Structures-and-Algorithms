https://leetcode.com/problems/lru-cache/

// TAGDA SAWAL HAI

https://youtu.be/nN36SSIMn1k  (LIT VIDEO fraz)

// MOST ASKED INTERVIEW QUESTION

// LEAST RECENTLY USED (LRU) CACHE
// ie the least recently used data is removed in this cache when it is filled.

// A data becomes most recent if get or put operation is performed on it.

// key-value pair is said ie map will be used.

// if capacity was infinite, then this could be implemented only by simple map.
// Now since capacity is limited, we have to also see which data has to be evicted. We will use doubly linked list for this purpose.

// We will use double linked list for LRU.

// We will maintain the most recent data at the start of the DLL
// 1) When we are putting data using put, we insert it at the start
// 2) When we get/fetch the data we take it out and put it at the start to make it most recent used data.
// 3) Evict/Delete the data from the end of the DLL.

// TC: O(log n) for both get and put function
// SC: O(n)

class LRUCache {
public:
    map<int, int> m;                            // to store key, val pair from ques.
    map<int, list<int>::iterator> address;      // to store key, address of key // to avoid list traversal
    list<int> l;
    int cap;                                    // max no of elements I can store in cache
    int siz;                                    // elements I have stored till now.
    
    LRUCache(int capacity) {
        cap = capacity;
        siz = 0;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        list<int>::iterator it = address[key];  // yeh jo key hai iski node kis address pe hai
        l.erase(it);                            // delete that node
        address.erase(key);                     // delete it from map as well
        l.push_front(key);                      // take the key and put it at the start
        address[key] = l.begin();               // new position ie start will be stored in the map
        return m[key];
    }
    
    void put(int key, int value) {
       if(m.find(key) != m.end()){              // key already exist(not key-value pair) in the map, delete it from map and list,, ie (2,5) was saved now (2,4) is to be saved so remove the old value 
           l.erase(address[key]);
           address.erase(key);
           m.erase(key);
           siz--;
       }
       // put the key in the start of DLL
        if(siz==cap){                           // ie capacity gets filled
           int k = l.back();
            l.pop_back();
            address.erase(k);
            m.erase(k);
            siz--;
        }
        siz++;
        l.push_front(key);
        address[key] = l.begin();
        m[key] = value;
    }
};


// Iska discuss section ar dusre YT videos future mein dekhna hai

// YT 
(Striver)
https://youtu.be/xDEuM5qa0zg
https://youtu.be/Xc4sICC8m4M
