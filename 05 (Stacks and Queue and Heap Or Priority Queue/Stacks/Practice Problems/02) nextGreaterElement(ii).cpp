https://leetcode.com/problems/next-greater-element-ii/

// Basically NGE in circular array.

https://youtu.be/Du881K7Jtk8 (Striver)

// We can have the same array repeated again. And use modulo (for circular array handling)

Array can be imagined as: 1 7 5 3 8 5, 1 7 5 3 8 5

class Solution{
public:
    vector<int> nextGreaterElements(vector<int> &nums){
        int n = nums.size();
        stack<int> st;
        vector<int> v(n);
        for (int i = 2 * n - 1; i >= 0; i--){
            while (!st.empty() && st.top() <= nums[i % n]){
                st.pop();
            }
            if (st.empty())
                v[i % n] = -1;
            else
                v[i % n] = st.top();
            st.push(nums[i % n]);
        }
        return v;
    }
};

OR
// Small variation from past code
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        stack<int>s;
        
        for(int i=n-1; i>=0; --i){   // in reverse order I push all the elements in the stack
            s.push(nums[i]);
        }
        
        for(int i=n-1; i>=0 ; --i){
            while(!s.empty() && s.top()<=nums[i]){  // I forget this =
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top());
            }
            s.push(nums[i]);
        }
        reverse(ans.begin(), ans.end());           // I forget this coz push_back kia hai
        return ans;
    }
}; 

