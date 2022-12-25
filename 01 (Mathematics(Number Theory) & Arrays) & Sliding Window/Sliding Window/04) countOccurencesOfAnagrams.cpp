https://www.geeksforgeeks.org/count-occurrences-of-anagrams/

https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

In this we have to return the number of anagrams

Identification:
Array/String, subarray/substring, k = window size.

Pattern in the string will be in continuos manner.
size of window k = size of pattern.

ans ++; instead of pushing in vector in below code.


https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

In this we have to return the first index of occurence of those anagrams.

Approach 1:

Vectors can be compared directly.
And comparing two vectors of size 26 is O(26) ie O(1)
Hence total TC = O(n)

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // vector comparison is possible and of size 26 is in O(1) time
        int s_len = s.size();
        int p_len = p.size();
        if(s_len<p_len) return {};
        vector<int> goal_freq_p(26, 0);
        vector<int> cur_window(26, 0);
        
        // first window
        for(int i=0; i<p_len; ++i){
            goal_freq_p[p[i]-'a']++;
            cur_window[s[i]-'a']++;
        }
        vector<int> ans;
        if(goal_freq_p == cur_window) ans.push_back(0);

        for(int i=p_len; i<s_len; ++i){
            cur_window[s[i]-'a']++;       // adding new element
            cur_window[s[i-p_len]-'a']--; // subtractring an element from the window, the element to be removed corresponds to i-p_len position
            if(goal_freq_p == cur_window) ans.push_back(i-p_len + 1);
        }
//     for (int i = 1; i < S_SIZE - P_SIZE + 1; ++i) {  // u can either start the loop from i or j ie start the window or end of the window
//          ++window_map[s[i + P_SIZE - 1] - 'a'];
//          --window_map[s[i - 1] - 'a'];

//          if (window_map == p_map) output.push_back(i);
//          
//     }
        return ans;
    }
};

OR

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // vector comparison is possible and of size 26 is in O(1) time
        int s_len = s.size();
        int p_len = p.size();
        if(s_len<p_len) return {};
        vector<int> goal_freq_p(26, 0);
        vector<int> cur_window(26, 0);
        
        // creating our window/vector from which comparision will be done
        for(int i=0; i<p_len; ++i){
            goal_freq_p[p[i]-'a']++;  
        }
        vector<int> ans;
        int i=0, j=0;
        while(j<s_len){
            cur_window[s[j]-'a']++;
            if(j-i+1<p_len){
                j++;
            }
            else if(j-i+1==p_len){ // p_len = k (size of the window)
                if(cur_window==goal_freq_p) ans.push_back(i);
                cur_window[s[i]-'a']--;
                i++;
                j++;
            }
        }
        return ans;
    }
};

//
Aditya verma approach:

class Solution {
public:
// Aditya verma approach
        vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char,int> m;//HashMap to store the frequencies of all the characters present in string 'p'.
        for(int i=0;i<p.length();i++)
            m[p[i]]++;
        int count=m.size();//count variable to check when all the characters present in the map have frequencies zero,which implies that an anagram is found.
        int k=p.length();//Window size.
        int i=0;
        int j=0;
        while(j<s.length()){
            // calculation part
            if(m.find(s[j])!=m.end())//if a character is found which is present in the map then decrease it's frequency by 1.
            {
                m[s[j]]--;
                if(m[s[j]]==0)//if the frequency of a particular character in the map is zero it implies that all the occurences of that particular character is found in the current window size.
                    count--;
            }
            // window length not yet achieved
            if(j-i+1<k)
                j++;
            // window length achived, find ans and slide the window
            else if(j-i+1==k)
            {
                // find ans
                if(count==0)//if the count is equal is zero it means that an anagram is found.
                    res.push_back(i);//if an anargram is found then push the starting index of the window.
                if(m.find(s[i])!=m.end())//while sliding the window check if that character is present in the map then increase it's frequency by one as we have decreased the frequency of that character when it was first encountered while traversing the window.
                {
                    m[s[i]]++;
                    if(m[s[i]]==1)
                        count++;
                }
                // slide window
                i++;
                j++;
            }
        }
        return res;
    }
};


