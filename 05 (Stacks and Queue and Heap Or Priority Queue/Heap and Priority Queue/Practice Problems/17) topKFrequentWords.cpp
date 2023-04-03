https://leetcode.com/problems/top-k-frequent-words/

class Solution {
public:
    typedef pair<string, int> P;
    
    struct lambda {
        bool operator()(P& a, P& b){
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        }  
    };
    // dikkat yahi hai ki yeh chahta hai ki agar frequency same ho toh alphabetical bhi ho jae, nahi toh jiski freqency jada wo pehle aa jae. Isliye custom likhna hi padega

    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();

        unordered_map<string, int> m;
        for(auto &word: words){
            m[word]++;
        }

        priority_queue<P, vector<P>, lambda> pq; // jada frequency walo ko preserve krna hai

        for(auto &x: m){
            auto freq = x.second;
            auto word = x.first;
            pq.push({word, freq});
            if(pq.size()>k) pq.pop();
        }
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

