https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


class Solution{
    public:
    void heapify(vector<int> &arr, int n, int i){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        
        if(left <n && arr[largest] < arr[left]){
            largest = left;
        }
        if(right <n && arr[largest] < arr[right]){
            largest = right;
        }
        
        if(largest!=i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
        
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> ans;
        for(auto i: a){
            ans.push_back(i);
        }
        for(auto i:b){
            ans.push_back(i);
        }
        
        // heapify
        int size = ans.size();
        for(int i = size/2 -1; i>=0; i--){
            heapify(ans, size, i);
        }
        return ans;
    }
};

