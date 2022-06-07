// https://leetcode.com/problems/group-anagrams/
// https://practice.geeksforgeeks.org/problems/print-anagrams-together/1

// strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

// unordered_map<string, vector<string> > umap;

// aet -> eat, tea, ate
// ant -> tan, nat
// abt -> bat

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;                      // to store our vector of vector of string result
    unordered_map<string, vector<string>> umap;
    
    for(auto x: strs){
        string temp = x;                            // temp = eat or tea or tan etc
        sort(x.begin(), x.end());                   // sort that string
        umap[x].push_back(temp);                    // storing the original string value corresponding to the sorted key.
    }
    
    for(auto x: umap){
        ans.push_back(x.second);                    // shorthand access through . instead of -> when using auto instead of that 'itr' thing
    }
    
    return ans;
}


// The above code can be written in this way as well (Just different loop, to give a clear area)
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         if(strs.size() == 1) {
//             return {{strs[0]}};
//         }
//         vector<vector<string>> ans;
//         unordered_map<string, vector<string>> M;
        
//         for(int  i = 0; i < strs.size(); i++) {
//             string str = strs[i];
//             sort(strs[i].begin(), strs[i].end());
//             M[strs[i]].push_back(str); 
//         }
//         for(auto i = M.begin(); i != M.end(); i++) {
//             ans.push_back(i -> second);
//         }
        
//         return ans;
//     }
// };

// TC = O(n* k log k)
// SC = O(n * k)




// Another Method  (Abhi k liye above method best hai, future m dekhenge)
// TC = O(n*k*26) or O(n*k)
// Group by count of characters (instead of sorted string as key we will use 2a1c1z type as the key)
// Example: s = "caaz"
// {cnt[0]}a{cnt[2]}c...{cnt[25]}z, result: "2a1c1z"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const string& str : strs)
            groups[getKey(str)].push_back(str);                   // will call the getKey function and which will return the key value

        vector<vector<string>> ans;
        for (const auto& p : groups)
            ans.push_back(p.second);
        return ans;
    }
    string getKey(const string& str) {
        int cnt[26] = {0};
        for (char c : str) cnt[c - 'a']++;                       // using ASCII relative substraction.
        string key;
        for (int i = 0; i < 26; ++i)
            if (cnt[i] > 0)
                key += to_string(cnt[i]) + char(i + 'a');
        return key;
    }
}; 

// to_string inbuilt function
https://www.cplusplus.com/reference/string/to_string/

