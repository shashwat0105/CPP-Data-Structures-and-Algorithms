https://leetcode.com/problems/lru-cache/

// MOST ASKED INTERVIEW QUESTION

// LEAST RECENTLY USED (LRU) CACHE
// ie the least recently used data is removed in this cache when it is filled.

// get and put makes a data as most recently used.

// key-value pair is said ie map will be used.

// if capacity was infinite, then this could be implemented only by simple map.
// Now since capacity is limited, we have to see which data has to be evicted.
// We will use doubly linked list for this purpose.


// We will maintain the most recent data at the start of the DLL
// 1) When we are putting data using put, we insert it at the start
// 2) When we get/fetch the data we take it out and put it at the start to make it most recent used data.
// 3) Evict/Delete the data from the end of the DLL.


