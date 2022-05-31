https://leetcode.com/problems/sliding-window-maximum/

https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

// We use a deque(DLL) that can have push, pop operations from both the ends, this will store indices
// And we are storing in some decreasing fashion similar to NGE questions


// TC = O(N)
// SC = O(K)

// At every index a[i] we are removing: out of bound
//                           and      :  <= a[i] elements


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;                                                   // using the deque stl which will store indexes
        vector<int> ans;
        for(int i=0; i<nums.size(); ++i){
            if(!dq.empty() && dq.front() == i-k) dq.pop_front();         // all the out of bound will be removed(dq.front location)
            
            while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();  // removes all the elements that are smaller as there is no use in comparing with them
            
            dq.push_back(i);                                              // push the current index
            if(i>=k-1) ans.push_back(nums[dq.front()]);                   // push in ans whatever is at the front in this condition location
        }
        return ans;
    }
};


// more to review
LC Discuss
https://leetcode.com/problems/sliding-window-maximum/discuss/?currentPage=1&orderBy=most_votes&query=

Aditya verma solution explanation
https://youtu.be/xFJXtB5vSmM



