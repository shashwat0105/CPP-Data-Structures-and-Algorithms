// https://leetcode.com/problems/sort-array-by-increasing-frequency/

// nums = [1,1,2,2,2,3]
// UMAP:
// 1 -> 2
// 2 -> 3
// 3 -> 1

// Lambda Function in C++
// https://www.geeksforgeeks.org/lambda-expression-in-c/

// [&](int a, intb){return Expression}
// [&](parameters){return Expression}

// Using lambda function during the sort, it will specify how to sort
// 1) If two numbers have different frequency, smaller goes first. 
// 2) If two numbers have same frequency, greater goes first.

vector<int> frequencySort(vector<int>& nums) {
    vector<int> ans;
    unordered_map<int, int> umap;
    for(auto x: nums){
        umap[x]++;
    }
    
    sort(nums.begin(), nums.end(), [&](int a, int b){
        return umap[a] != umap[b] ? umap[a]<umap[b] : a>b;           // if frequency is different sort fun is defined acc to value, else by key
    });
    
    return nums;
}

