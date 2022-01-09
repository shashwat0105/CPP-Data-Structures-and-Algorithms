https://leetcode.com/problems/merge-intervals/

https://youtu.be/2JzRBPFYbKE

// We have to ask the interviewer if the intervals are sorted, here they are not

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;   
        
        int n = intervals.size();
        if(n==0){
            return res;
        }
        
        sort(intervals.begin(), intervals.end());  // according to the ques
        
        vector<int> temp = intervals[0]; // Initilise temp with first ele of intervals

        for(auto it: intervals){
            if(temp[1] >= it[0]){     // temp ka second element >= it ka first element (Yes overlapping)
                temp[1] = max(it[1], temp[1]);
            }
            else{
                res.push_back(temp);  // ie no need of comparison now coz separate intervals (No overlapping)
                temp = it;
            }
        }
        res.push_back(temp);
        return res;
    }
};

// Another good solution with detailed explanation
https://leetcode.com/problems/merge-intervals/discuss/600013/C%2B%2B-solution-with-detailed-explanation

