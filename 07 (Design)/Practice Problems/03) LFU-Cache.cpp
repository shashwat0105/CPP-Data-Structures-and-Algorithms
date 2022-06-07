https://leetcode.com/problems/lfu-cache/

(Striver)
https://youtu.be/0PSB9y8ehbk
https://youtu.be/mzqHlAW7jeE

// Get into the final solution directly instead of naive as the problem is already lengthy.

// LFUCache(int capacity) Initializes the object with the capacity of the data structure.
// In sample test case it is 2

// put(1, 10) : there is 1 frequent guy with key of 1 and value of 10
// get(1)     : return value of key=1 ie 10 if it is present else -1

// data structures we will be using.
map<freq, list> freqList;
map<key, node*> keyNode;

capacity=0;
freq=0;      

// We can use the list of c++ STL.
// But in interviewer they will/can ask you to implement that list as well.
// So, yeh wala part LRU cache mein bhi daalna hoga striver ki video se.



