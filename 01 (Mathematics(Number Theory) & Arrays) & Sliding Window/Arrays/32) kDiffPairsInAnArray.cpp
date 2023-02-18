https://leetcode.com/problems/k-diff-pairs-in-an-array/

// TC = O(nlogn)
// Sort and Binary Search with Set 
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<int> s;
        
        for(int i=0; i<n-1; ++i){
            if(binary_search(nums.begin()+i+1, nums.end(), nums[i]+k)){  
                s.insert(nums[i]);
            }
        }
        return s.size();
    }
};

// binary_search(start address, end address, value to find)

// Sort and Binary Search without set
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        
        for(int i=0; i<n-1; ++i){
            if((i==0) || nums[i]!=nums[i-1]){
                if(binary_search(nums.begin()+i+1, nums.end(), nums[i]+k)){
                   res++; 
                }
            }
        }
        return res;
    }
};

// Using unordered map
// TC = O(n)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0) return 0;
        
        int n = nums.size();
        unordered_map<int, int> umap;
        int res = 0;
        
        for(int n: nums) umap[n]++;      
        
        for(auto p: umap){
            if((k==0 && p.second>1) || (k && umap.count(p.first+k))){    // Instead of umap.count(p.first+k) can use m.find(p.first + k) != m.end()
                res++;
            }
        }
        return res;
    }
};

// count also returns true or false like find
