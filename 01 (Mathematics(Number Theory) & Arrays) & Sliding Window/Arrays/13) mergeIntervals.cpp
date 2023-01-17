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

OR (better code)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //base case
        if(intervals.size()<=1) return intervals;
        //resultan vector
        vector<vector<int>> result;
        //sort takes O(nlogn) time
        sort(intervals.begin(), intervals.end()); 
        //insert the the the first interval in the result
        result.push_back(intervals[0]);
         //Traverse the whole vector .Takes O(n) time
        for(int i=1; i<intervals.size(); i++) {
             //if intevals are overlapping
            if(result.back()[1] >= intervals[i][0]) result.back()[1] = max(result.back()[1] , intervals[i][1]);
            //else they are not overlapping
            else result.push_back(intervals[i]); 
        }
        return result;
    }
};

// O(1) space
class Solution {
public:
// O(1) space
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int index = 0;
        sort(intervals.begin(), intervals.end());
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= intervals[index][1]){
                intervals[index][1] = max(intervals[i][1], intervals[index][1]);
                intervals[index][0] = min(intervals[i][0], intervals[index][0]);
            }else{
                index++;
                intervals[index] = intervals[i];
            }
        }
        while(intervals.size() != index + 1)
            intervals.pop_back();
        return intervals;
    }
};

// O(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& I) {
        sort(begin(I), end(I));
        int R = 0;
        for(auto i : I)
            if(i[0] <= I[R][1])                          
                I[R][1] = max(I[R][1], i[1]);
            else                                              
                I[++R] = i;
        I.resize(R+1);
        return I;
    }
};

// Another good solution with detailed explanation
https://leetcode.com/problems/merge-intervals/discuss/600013/C%2B%2B-solution-with-detailed-explanation

