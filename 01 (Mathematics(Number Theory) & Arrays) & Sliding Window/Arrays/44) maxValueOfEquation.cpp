https://leetcode.com/problems/max-value-of-equation/

yi + yj + |xi - xj|

We know xj>xi
Hence we can write above eqn as =
yi + yj + xj - xi
ans: (xj + yj) + (yi-xi)

From previous indices only (yi-xi) part is changing(variable jiski max value apan use karenge hamesha)
Har index k liye past max value se karenge.

So we will take a priority queue.
pair why?
(yi-xi) jiske according sorted order m store hoga
xi      so that we can verify our condition.


class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;  // max heap
        int n = points.size();
        int ans = INT_MIN;
        for(int i=0; i<n; ++i){
            while((!pq.empty()) && (points[i][0]-pq.top().second >k)) pq.pop(); // remove the invalid elements
            if(!pq.empty()){  // queue still has some elements, calculate ans using the top element only
                ans = max(ans, points[i][0] + points[i][1] + pq.top().first);
            }
            pq.push({points[i][1]-points[i][0], points[i][0]});
        }
        return ans;
    }
};

TC = nlogn
Sc = n
