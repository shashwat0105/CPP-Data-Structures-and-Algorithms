https://leetcode.com/problems/reorganize-string/

Approach 1: Ki most occuring characters ko ek ek pakad k even positions m daal do fr remaining ko even m daal do. b _ b _ b 
Code for this is slightly lengthy:
https://leetcode.com/problems/reorganize-string/solutions/3253376/easy-beginner-friendly-cpp-solution-100-faster-then-other-solition/
https://leetcode.com/problems/reorganize-string/solutions/3487921/beats-100-c-code/

Approach 2: Take two most occuring characters and place them side by side. ie : b a b a then fill last element
Thinking this is less trivial but coding this is easier.

class Solution {
public:
    string reorganizeString(string s) {
        string res = "";
        unordered_map<char, int> mp;

        priority_queue<pair<int, char>> pq;

        for(auto c: s){
            mp[c]++;
        }

        for(auto m: mp){
            pq.push({m.second, m.first});
        }

        while(pq.size()>1){
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();

            res += top1.second;
            res += top2.second;

            top1.first--;
            top2.first--;

            if(top1.first>0) pq.push(top1);
            if(top2.first>0) pq.push(top2);
        }
        // for remaining characters
        if(!pq.empty()){
            if(pq.top().first>1) return ""; // mtlb isko adjacent ana hi padega
            else res+=pq.top().second; 
        }
        return res;
    }
};


