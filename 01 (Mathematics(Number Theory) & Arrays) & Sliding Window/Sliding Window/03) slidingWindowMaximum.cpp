https://leetcode.com/problems/sliding-window-maximum/submissions/

This ques is in other folder as well.

// method 1
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

// Using sliding window:
Ek heap bana k max element ka track kar skte hai jaise hi slide krna hoga agar wo max element hoga toh use remove kr denge 
Instead of deque using a heap here.

https://leetcode.com/problems/sliding-window-maximum/solutions/620707/sliding-window-template/

https://leetcode.com/problems/sliding-window-maximum/solutions/1505556/c-sliding-window-solution/


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int i=0, j=0;
        vector<int> res;
        while(j<nums.size()){
            while(!dq.empty() && dq.back()<nums[j]) dq.pop_back(); // continuously remove all smaller element
            dq.push_back(nums[j]); // push toh krna hi hai
            if(j-i+1 < k) j++;
            else if(j-i+1 == k){
                // how front will have bigger element? 
                // coz right m keval smaller element hai. agar bada element jab aata tha toh chote element ko pop_back kar dete the.
                res.push_back(dq.front());
                if(dq.front()==nums[i]) dq.pop_front();  // ek bade number ko kab hataoge deque se. (deque is of variable size)
                i++;
                j++;
            }
        }
        return res;
    }
};

//
https://leetcode.com/problems/sliding-window-maximum/solutions/65999/3-c-solutions/
