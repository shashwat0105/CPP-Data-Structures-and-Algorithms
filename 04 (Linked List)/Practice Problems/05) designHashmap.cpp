https://leetcode.com/problems/design-hashmap/

// Method 1 (Troll method XD)

class MyHashMap {
public:
  
    vector<int> m;                      // An error I faced while initilising -1 here: 
                                        // https://stackoverflow.com/questions/39560277/vector-declaration-expected-parameter-d
    MyHashMap() {
        int siz = 1e6+1;
        m.resize(siz);
        fill(m.begin(), m.end(), -1);         // Initilising all vector values by -1
    }
    
    void put(int key, int value) {
        m[key] = value;
    }
    
    int get(int key) {
        return m[key];
    }
    
    void remove(int key) {
        m[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */


// METHOD 2

class MyHashMap {
public:
  
    vector<list<pair<int, int>>> m;    // to store key and value pair
    int siz;
    MyHashMap() {
        siz = 10007;                   // 10007(nearest prime of size of array) then your solution would more efficient because Using nearest prime of size of array the chances of collision would be minimum and there will be more chances of equally distribution of element of array.
        m.resize(siz);
    }
    
    int hash(int key){
        return key%siz;
    }

    // iterator of type list of pair, which will return the location
    list<pair<int, int>> :: iterator search(int key){
        int i = hash(key);
        // cannot use inbuilt find function because we know the key but not {key, value}
        list<pair<int, int>> :: iterator it = m[i].begin();
        while(it!=m[i].end()){
            if(it->first==key) return it;   // ie without value we searched just with key
            it++;
        }
        return it;                          // if it reaches the end
    }
    
    void put(int key, int value) {
        int i = hash(key);                  // we got the index jispe put or update krna hai
        remove(key);                        // will remove if it already exist else it will do nothing
        m[i].push_back({key, value});
    }
    
    int get(int key) {
        int i = hash(key);
        list<pair<int, int>> :: iterator it = search(key);
        if(it==m[i].end()) return -1;       // the key doesnt exist
        else return it->second;
        
    }
    
    void remove(int key) {
        int i = hash(key);
        list<pair<int, int>> :: iterator it = search(key);
        if(it!=m[i].end()) m[i].erase(search(key));  // will remove jiska mujhe search krne pe iterator return hua hai and it exists in the list
    }
};

// everywhere
list<pair<int, int>> :: iterator  iski jagah pe auto likh skte ho chahe variable declare ya function return type.



