https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

long long minCost(long long arr[], long long n) {
    // Your code here
    priority_queue<long long, vector<long long>, greater<long long>> pq; // min heap
    
    for(int i=0; i<n; ++i){
        pq.push(arr[i]);
    }
    
    long long cost = 0;
    
    while(pq.size() > 1){
        long long a = pq.top();
        pq.pop();
        
        long long b = pq.top();
        pq.pop();
        
        long long sum = a+b;
        cost += sum;
        
        pq.push(sum);
    }
    return cost;
}

// Yeh concept bhi bahot imp hai in heap ki, top k do elements nikale ar fr unse kuch operation kia ar dobara heap m daal dia.
