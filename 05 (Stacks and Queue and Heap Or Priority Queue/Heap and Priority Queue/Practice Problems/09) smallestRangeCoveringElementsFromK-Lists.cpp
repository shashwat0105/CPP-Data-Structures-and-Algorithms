https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

https://ideone.com/6PK6n9

V V V V HARD PROB. (yet to understand well.)

// Similar to merge K sorted Lists:
// Yeh seekh k isko seekhne ka try krna

We take the 1st element from each of the k lists and insert it inside the min heap. 
We use a min heap to track the min element from each of the k list (currMin), 
and currMax to track the max element whilst keeping the range as minimum as possible (currRange).
We track the start and end as the min and max of the smallest range.

// Other solns
// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/solutions/3101213/complete-handwritten-approach-dry-run/

// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/solutions/2142779/c-easy-to-understand-priority-queue-based-approach-comment-rich/

typedef pair<int, pair<int, int>> pi;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        int mn = INT_MAX, mx = INT_MIN, range = INT_MAX;
        for (int i=0; i<n; i++) {
            pq.push({nums[i][0], {i, 0}});
            mn = min(mn, nums[i][0]);
            mx = max(mx, nums[i][0]);
        }
        int a = mn, b = mx;
        while (!pq.empty()) {
            pi curr = pq.top();
            pq.pop();
            //cout<<curr.first<<" "<<curr.second.first<<" "<<curr.second.second<<endl;
            if (curr.second.second + 1 < nums[curr.second.first].size()) {
                int r = curr.second.first, c = curr.second.second + 1;
                pq.push({nums[r][c], {r, c}});
                mn = pq.top().first;
                mx = max(mx, nums[r][c]);
                if (b-a > mx-mn) {
                    a = mn;
                    b = mx;
                }
            } else {
                break;
            }
        }
        return {a, b};
    }
};
