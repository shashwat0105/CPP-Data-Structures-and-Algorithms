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