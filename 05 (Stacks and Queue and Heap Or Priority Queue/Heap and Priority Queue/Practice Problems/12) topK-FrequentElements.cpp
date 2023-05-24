https://leetcode.com/problems/top-k-frequent-elements/

{key, number} // sorting will be done acc to first element ie key

here key is the frequency.

TC = O(nlogk)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // edge case so that nlogk doesnt becomes nlogn
        if (k == nums.size()) {
            return nums;
        }

        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); ++i){
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto it: mp){
            pq.push({it.second, it.first});  // mp has second as frequency.
            if(pq.size()>k) pq.pop();
        }
        
        vector<int> ans;
        
        while(!pq.empty()){
           ans.push_back(pq.top().second);
           pq.pop();
        }
        return ans;
    }
};

// If loop was written using iterator
for(auto it = mp.begin(); it!=mp.end(); it++){
    pq.push({it->second, it->first});
    if(pq.size()>k) pq.pop();
}


// Approach 2: Quick select
(Hoare's selection algorithm)

It has O(N) average time complexity and is widely used in practice. 
It worth noting that its worst-case time complexity is O(N^2), although the probability of this worst-case is negligible.

refer editorial.

// Approach 3: Bucket sort
https://youtu.be/YPTqKIgVk-k  (neetcode)

class Solution {
public:
// Bucket sort method O(N)
// [1,1,1,2,2,3,3]
// 0 1  2     3 4 5 6
//     [2,3] [1]   // 2 and 3 are occuring 2 times. Iski range hogi N tak, coz an element can at max repeat N times.
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==n) return nums;

        vector<int> ans;
        if(n==0) return ans;
        vector<vector<int>> buckets(n+1);

        unordered_map<int, int> m;

        for(int num: nums) m[num]++;

        for(auto &x: m){
            buckets[x.second].push_back(x.first);
        }

        // now we traverse from back(ie taking elements with max frequency)
        for(int i=buckets.size()-1; i>=0; --i){
            for(int j=0; j<buckets[i].size(); ++j){
                ans.push_back(buckets[i][j]);
                if(ans.size()==k) return ans;
            }
        }
        return ans;
    }
};
