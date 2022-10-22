https://leetcode.com/problems/k-closest-points-to-origin/

To minimise sqrt(x^2 + y^2) ie we will make this key.
Will same as storing (x^2 + y^2) coz hona toh sort hi hai.

Other pair half will be the coordinates.

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;  // max heap kth smallest nikalna hai
        
        int n = points.size();
        for(int i=0; i<n; ++i){
            pq.push({points[i][0]*points[i][0] + points[i][1]*points[i][1], {points[i][0], points[i][1]}});
            
            if(pq.size()>k) pq.pop();
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()){
            pair<int, int> q = pq.top().second;
            ans.push_back({q.first, q.second});
            pq.pop();
        }
        return ans;
    }
};


For more practice
Refer
https://leetcode.com/discuss/general-discussion/1127238/master-heap-by-solving-23-questions-in-4-patterns-category
