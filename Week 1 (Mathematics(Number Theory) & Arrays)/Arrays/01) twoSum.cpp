https://leetcode.com/problems/two-sum
Solution vid: https://youtu.be/o2WOhGSfx_8

// Brute force: Time: O(n^2), Space: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> two;
        
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                if(nums[i]+nums[j]==target && i>j){
                    two.push_back(i);
                    two.push_back(j);
                }
            }
        }
        return two;
    }
};

// Best Optimised:
// Time: O(n), Space: O(n)
// Using unordered map
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> m;         // to store the value & index corresponding to the value

    vector<int> two;

    for(int i=0; i<nums.size(); i++){
        int y = target-nums[i];
        if(m.find(y)!=m.end()){
            two.push_back(i);
            two.push_back(m[y]);
        }
        m[nums[i]] = i;               // nums[i] is the value & i is the corresponding index coz, map[key] = value // (syntax)
    }                                 // & we do this creation of map "on the go" (it will only check in the past inserted elements in the map) because to avoid cases say (2,2) but in array 2 is only once & (4,6) , (6,4) for single occurences of the elements.
    return two;
}


// TIME: O(nlogn), Space: O(n)
// Using sorting + two pointer approach

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++) v.push_back({nums[i], i});

    sort(v.begin(), v.end());

    int s=0;
    int e=n-1;
    while(s<e){
        int sum = v[s].first + v[e].first;
        if(sum==target) return {v[s].second, v[e].second};
        else if (sum>target) e--;
        else s++;                             // because the current sum is less than required so we move to right coz sorted array
    }

    return {-1,1};
    }
};

// Can do using binary search as well
// https://leetcode.com/problems/two-sum/discuss/142/Cpp-O(nlogn)-using-binary-search.

