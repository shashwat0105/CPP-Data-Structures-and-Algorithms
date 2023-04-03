https://leetcode.com/problems/daily-temperatures/

// Same as NGER
// We have to return days to wait ie difference in indices.

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        stack<int> s;
        for(int i=temperatures.size()-1; i>=0; i--){
            while(!s.empty() && temperatures[s.top()]<=temperatures[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(s.top()-i);
            }
            s.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

