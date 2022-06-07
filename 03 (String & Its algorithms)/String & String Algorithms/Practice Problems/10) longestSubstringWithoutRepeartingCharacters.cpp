https://leetcode.com/problems/longest-substring-without-repeating-characters/


// If you want to refer to a video
https://youtu.be/qtVh-XEpsJo

// VARIABLE SIZE SLIDING WINDOW

// TC = O(2n)
// SC = O(256) // All ascii values in the set

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> set;
        int res = 0;
        
        int l = 0, r=0;
        
        while(l<n && r<n){
            if(set.find(s[r])==set.end()){   // s[r] is not found in set
                set.insert(s[r]);
                r++;                         // I am calculating res after this r++ so I did r-l instead of r-l+1
            }
            else{                            // s[r] is found in the set ie we have to decrease the size of the set(window)
                set.erase(s[l]);
                l++;                        
            }
            res = max(res, r-l);             // r-l is the size of the current set ie int k = s.size(); res = max(res, k) can alse be used.
        }
        return res;
    }
};

// ****
Insert till you become invalid.
Erase till you become valid again.
// ****

// Now as we can see l++ can be further optimesed by moving it directly to the position where it gets valid again instead of moving it one by one.
// ie  If the character is already in the hashmap, then move the left pointer to the right of the same character last found.
TC = O(n)
SC = O(256)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> arr(256, -1);              // for ASCII char sequence, we can array as a hashmap
        int res = 0;
        
        int l = 0;
        for(int r=0; r<n; r++){
            l = max(arr[s[r]]+1, l);
            arr[s[r]] = r;
            res = max(res, r-l+1);
        }
        return res;
    }
};



