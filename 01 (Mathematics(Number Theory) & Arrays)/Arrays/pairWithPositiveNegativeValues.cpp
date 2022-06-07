// https://practice.geeksforgeeks.org/problems/pairs-with-positive-negative-values3719/1

vector<int> PosNegPair(int a[], int n) {
    vector<int> v, ans;                  // v vector will store all negative values, ans will store answer
    map<int, int>mp;                     // mp will store all positive values in ascending order.
    
    for(int i=0; i<n; i++){
        if(a[i]<0){
            v.push_back(a[i]);
        }
        else
            mp[a[i]]++;
    }
    
    sort(v.begin(), v.end());            // sorting of the values of array : -9, -7, -3, -2  (contains all -ve)
    
    for(int i=v.size()-1; i>=0; i--){    // righmost value will be greatest negative but smallest positive, so we traverse from last
        if(mp[abs(v[i])]>0){             // we check if the absolute of that -ve value is in map.
            ans.push_back(v[i]);         // pushing the -ve value first
            ans.push_back(abs(v[i]));    // pushing its positive value
            mp[abs(v[i])]-=1;            // decreasing the count of occurence from the map by 1.
        }
    }
    return ans;                          // to return a vector of int.
}

