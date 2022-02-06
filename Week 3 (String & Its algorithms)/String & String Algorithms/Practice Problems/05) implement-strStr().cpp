https://leetcode.com/problems/implement-strstr/

// "Needle in a haystack" with relaxed time constraints

// Python Implementation(BEST):
// We have string slicing facility in python
if needle == "":
    return 0

// if the length of the last several characters is shorter than the length of the needle, there must not be a needle, i.e. no need to search for it. so n-m+1
for i in range(len(haystack) + 1 - len(needle)):   
    if haystack[i: i+len(needle)] == needle:
        return i

return -1

// C++
// O(m*n) solution sometimes gives AC sometimes not in Leetcode
// This ques works with this(Naive approach)
// Traverse all the possible starting points of haystack (from 0 to haystack.length() - needle.length()) and see if the following characters in haystack match those of needle.
TC = O(n*m)
SC = O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(m==0) return 0;
        
        for(int i=0; i<n-m+1; ++i){
            for(int j=0; j<m; ++j){
                if(haystack[i+j] != needle[j]) break;
                if(j == m-1) return i;
            }
        }
        return -1;
    }
};

// Can write the loop in other way as:
for(int i=0; i<n-m+1; ++i){
    int j = 0;
    for(; j<m; ++j){
        if(haystack[i+j] != needle[j]) break;
    }
    if(j == m) return i;
}
return -1;

*******************************
// Using built in strStr() function in c++ , TC = O(m*n) but runs in just 6ms
// https://www.geeksforgeeks.org/strstr-in-ccpp/
// https://www.geeksforgeeks.org/convert-string-char-array-cpp/ (some methods to convert string data type to char array that is taken from C language)
// Coz we know in c++ we can declare strings using two methods.

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(m==0) return 0;
  
        char p[n+1];
        strcpy(p, haystack.c_str());     // because inbuilt function take char array insted of string as argument.

        
        char q[m+1];
        strcpy(q, needle.c_str());
        
        char* r;
        
        r = strstr(p, q);
        int index = r - p;               // Use pointer subtraction. Credits: https://stackoverflow.com/questions/7500892/get-index-of-substring
        
        if(index>=0 && index<=n) return index;
        return -1;
    }
};

// without using strcpy() function. (GFG method 4)
class Solution {
public:
    int strStr(string haystack, string needle) {
       const char* p = strstr(haystack.c_str(), needle.c_str());
       if(p==NULL) return -1;
       return p-haystack.c_str();
        
    }
};

// Change language to C
int strStr(char * haystack, char * needle){
	char *pos = strstr(haystack, needle);
	return pos ? pos-haystack : -1;
}

*********************************************************************
KMP or Rabin Karp
TC = O(n+m)
SC = O(m)

