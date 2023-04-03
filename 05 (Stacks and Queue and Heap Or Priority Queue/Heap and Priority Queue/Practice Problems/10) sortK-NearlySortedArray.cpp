https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// K-K groups m move krke heap bana k smallest element nikal k lete jao.
// Elements at max k positions pe hai

Asked in Flipkart

vector <int> nearlySorted(int arr[], int n, int k){
        // Your code here
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;  // min heap.
    for(int i=0; i<n; i++){
        pq.push(arr[i]);
        if(pq.size()>k){
            ans.push_back(pq.top());
            pq.pop();
        }
    }
    while(!pq.empty()){               // adding remaining heap elements to the heap.
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
