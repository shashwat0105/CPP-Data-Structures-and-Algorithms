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

// We can insert first k elements like this as well
priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.begin()+k);  // min heap


OR
// Best yahi hai min heap bana k karna
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;  // min heap
        
    for(auto &x: nums){
        pq.push(x);
        if(pq.size()>k) pq.pop();
    }
    
    return pq.top();
}


// If u want to use max heap instead
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());  // saare elements ko daal dia
        // for (int i = 0; i < k - 1; i++) {
        //     pq.pop();
        // }
        // return pq.top();
        int ans = 0;
        while(k--){
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};

// TC = Build Max heap O(N) + Remove k and heapify O(Klogn) 