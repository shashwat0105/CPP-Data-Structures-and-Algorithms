https://leetcode.com/problems/insert-delete-getrandom-o1/description/

// Asked in many companies.

// Usually the first thing that comes to find when we hear "lookup" , "insert" in constant time is "hashmaps".
// That's the reason we use an unordered_map here which stores the element as " key " and its position in vector as the "value ".. 
// The average time complexity of search , insert and remove elements from a hashmap is O(1).

// However , here we need to support "Random()" access in O(1) as well. so we are using a vector here to achieve that.

// In order to search whether it exist there or not we need to store its index ie location as well to verify whether it already existed.
// When removing an element we replace that element with the last element of that array so that, 
// that position dont remain empty, and pop the last element, and update this in our map as well.
// agar ek hi element raha hoga vector m toh wo bas pop ho jaega, qki wo usi index pe dobara chala jaega

https://leetcode.com/problems/insert-delete-getrandom-o1/solutions/85422/AC-C++-Solution.-Unordered_map-+-Vector

// 
class RandomizedSet {
public:
    vector<int> vec;
    unordered_map<int, int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!= mp.end()) return false; // already exist in the map or vector
        vec.push_back(val);
        mp[val]=vec.size()-1;                     // map m uska index daal dia uski value k against
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()) return false; // doesnt exist
        // need to remove it, sabse pehle uska index store kar lo
        int idx = mp[val]; 
        vec[idx] = vec.back();                  // last element ko utha k jaha remove karna hai waha daal do, last element mtlb ease of access k liye le lia hai
        mp[vec.back()] = idx;
        mp.erase(val);
        vec.pop_back();
        return true;
    }
    
    int getRandom() {
        int n = vec.size();
        int randomIndex = rand()%n;
        return vec[randomIndex];
        // or return vec[rand() % vec.size()];  // vec[0.....(n-1)] tak koi random number select karke de dega
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
