https://leetcode.com/problems/sort-characters-by-frequency/

// Direct heap ques as in characters "bbAa" and "bbaA" both are acceptable if two have same frequency.

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(int i=0; i<s.size(); ++i){
            mp[s[i]]++;
        }
        
        priority_queue<pair<int, char>> pq;  // will make max heap
        for(auto it: mp){
            pq.push({it.second, it.first});  // mp has second as frequency.
        }
        
        string ans="";
        while(!pq.empty()){
            int freq = pq.top().first;
            char ele = pq.top().second;
            
            for(int i=0; i<freq; ++i){
                ans+=ele;
            }
            pq.pop();
        }
        return ans;
    }
};



https://leetcode.com/problems/sort-array-by-increasing-frequency/

// Here if the frequency is same then we want decreasing order. So, we will need a custom compartor.

https://leetcode.com/problems/sort-array-by-increasing-frequency/discuss/1279845/C%2B%2Bor-100-fasteror-EASY-TO-UNDERSTAND-or-fast-and-efficient-code-using-comparator-function
