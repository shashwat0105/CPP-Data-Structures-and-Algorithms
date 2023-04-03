Good concepts and variations (neeche wale m custom comparator ka approach)

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

// Method 2: Bucket sort
class Solution {
public:
    string frequencySort(const string& s) {
        int n = s.size();
        unordered_map<char, int> cnt;
        for (char c : s)  cnt[c] += 1;
        
        vector<vector<char>> bucket(n+1);
        for (auto [c, f] : cnt)
            bucket[f].push_back(c);
        
        string ans;
        for (int freq = n; freq >= 1; --freq)
            for (char c : bucket[freq]) 
                ans.append(freq, c);
        return ans;
    }
};

https://leetcode.com/problems/sort-array-by-increasing-frequency/

Actually, it is necessary to use minus otherwise, all test cases will not run eg [2,3,1,3,2] gives an output of [1,2,2,3,3]
but we are supposed to get [1,3,3,2,2] as '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.


class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it : mp){
            pq.push({-it.second,it.first});
        }
        vector<int> result;
        while(!pq.empty()){
            int x = pq.top().first;
            for(int i=0;i<abs(x);i++){
                result.push_back(pq.top().second);
            }
            pq.pop();
        }
        return result;
    }
};

// else u want to use a min heap
// Here if the frequency is same then we want decreasing order. So, we will need a custom compartor.
https://leetcode.com/problems/sort-array-by-increasing-frequency/solutions/3282061/using-heap/

Using a custom in sort method
https://leetcode.com/problems/sort-array-by-increasing-frequency/discuss/1279845/C%2B%2Bor-100-fasteror-EASY-TO-UNDERSTAND-or-fast-and-efficient-code-using-comparator-function

Using lambda sort u can refer my first submission.
