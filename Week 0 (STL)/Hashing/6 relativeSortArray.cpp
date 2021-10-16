// https://leetcode.com/problems/relative-sort-array/
// https://practice.geeksforgeeks.org/problems/relative-sorting4323/1

// Example:
// arr1 = {2,1,2,5,7,1,9,3,6,8,8}
// arr2 = {2,1,8,3}

// Making map of array 1  (will get stored in sorted order)
// 1 -> 2
// 2 -> 2
// 3 -> 1
// 4 -> 1 
// 5 -> 1
// 6 -> 1
// 7 -> 1
// 8 -> 2
// 9 -> 1

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    vector<int> ans;

    map<int, int> mp;
    for(int i=0; i<arr1.size(); i++){
        mp[arr1[i]]++;                   // map creation
    }
    
    for(int i=0; i<arr2.size(); i++){    // traversing through 2nd array and pushing the element number of times it is present in the map
        while(mp[arr2[i]]>0){
            ans.push_back(arr2[i]);
            mp[arr2[i]]--;
        }
    }
    
    for(int i=0; i<=1000; i++){
        while(mp[i]>0){                  // mp[500] is non zero means there is an element 500 present
            ans.push_back(i);
            mp[i]--;
        }
    }
    return ans;
}
