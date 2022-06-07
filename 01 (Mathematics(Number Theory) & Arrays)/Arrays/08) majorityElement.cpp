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

        // same above loop can be written as below as well
        // for(auto x: nums){
        //     umap[x]++;                              // // it will store the keys and its count, coz whenever we insert a key its corresponding value is 0 by default.
        //     if(umap[x] > n/2) return x;
        // }
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
// Moore's Voting Algorithm or Voting algorithm  (Famous algo)
// TC = O(n), SC = O(1)      // Most efficient algo

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        for(auto a: nums){
            if(count == 0){
                candidate = a;
            }

            if(a == candidate) count++;
            else count--;
        }
        return candidate;
    }
};

// In voting, we will make first number as majority winner, then we move on to next element, 
// if the vote is in favour ie same element is found again we increment the number of votes,
// else we nullify the vote, if the count of votes become 0, we make the current element as new majority winner.
// At last we confirm the count of majority winner. (If it is not given whether majority element always exist or not)
// We are cancelling one element with another if they are not equal.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Step 1: Finding the majority element 
        int count=1;
        int res=0;
        int n=nums.size();
        
        for(int i=1; i<n; i++){
            if(nums[i] == nums[res]){
                count++;
            }
            else
                count--;
            
            if(count==0){
                count=1;
                res=i;
            }
        }

        // Step 2: Verify the majority element
        // In this ques it is given always exist, so it will pass without the below part of code.
        count=0;
        for(int i=0; i<n; i++){
            if(nums[i] == nums[res]){
                count++;
            }
        }
        if(count>=n/2) return nums[res];
        
        else
            return -1;
    }
};
