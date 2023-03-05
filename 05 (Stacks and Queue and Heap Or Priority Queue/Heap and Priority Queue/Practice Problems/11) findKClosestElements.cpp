https://leetcode.com/problems/find-k-closest-elements/

We will make a max heap because we want to keep 0, 0, 1, 1.. differences.

// Will store a pair.
pair<int, int>
{abs(arr[i]-x, arr[i])}  // will get automatically sort acc to abs values.

// code

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<n; ++i){
            pq.push({abs(arr[i]-x), arr[i]});
            
            if(pq.size()>k) pq.pop(); 
        }
        
        vector<int> ans;
        // Now the heap contains the required elements
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//
Another easy solution using min heap and without pairs:


vector<int> findClosestElements(vector<int>& arr, int k, int x) { 
    int n = arr.size();
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < n; i++){
        if(pq.size() != k)
            pq.push(arr[i]);
        else {
            if(abs(arr[i] - x) < abs(pq.top() - x))
                pq.pop(), pq.push(arr[i]);
        }
    }
        
    while(pq.size())
        ans.push_back(pq.top()), pq.pop();
    
    return ans;
}

