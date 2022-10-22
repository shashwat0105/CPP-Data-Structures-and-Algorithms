https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;  // min heap
        
        // step 1: Add first k elements to the heap
        int n = nums.size();
        
        for(int i=0; i<k; i++){
            pq.push(nums[i]);
        }
        
        // step 2
        for(int i=k; i<n; ++i){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        return pq.top();
    }
};


OR

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;  // min heap
    
    int n = nums.size();
    
    for(int i=0; i<n; i++){
        pq.push(nums[i]);
        if(pq.size()>k) pq.pop();
    }
    
    return pq.top();
}
