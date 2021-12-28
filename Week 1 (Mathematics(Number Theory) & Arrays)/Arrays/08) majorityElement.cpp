https://leetcode.com/problems/majority-element/

https://youtu.be/PqU48t80rn8

// Method 1:
// TC = O(n), SC = O(n/2) or O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        
        int n = nums.size();
        for(int i=0; i<n; i++){
            umap[nums[i]]++;                           // // it will store the keys and its count, coz whenever we insert a key its corresponding value is 0 by default.
            if(umap[nums[i]] > n/2) return nums[i];
        }
        return -1;
    }
};


// can also write
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        
        int n = nums.size();
        for(auto x: nums){
            umap[x]++;                           // // it will store the keys and its count, coz whenever we insert a key its corresponding value is 0 by default.
            if(umap[x] > n/2) return x;
        }
        return -1;
    }
};


// Method 2: (Nice thinking)
// TC = O(nlogn), SC = O(1)
// Sorting the vector, middle element will be the majority element hence returning it.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n/2];
    }
};


// Method 3:
// Moore's Voting Algorithm
// TC = O(n), SC = O(1)  // Most efficient algo


