https://leetcode.com/problems/sum-of-subarray-minimums/

// Acha sawal hai!

https://youtu.be/9-TXIVEXX2w

// Generate all subarrays O(N^3)
// Generate and find min on the way O(N^2)

// Acc to given constraints need to do in O(N)
// We will use concept of monotonic stack

Ex: 2 9 7 8 3 4 6 1

NSL of 3 is 2
NSR of 3 is 1

So, 9 7 8 3 4 6, making subarray always having 3 in it.
Can chose starting point in 4 ways 9,7,8,3
Can chose the ending point in 3 ways 3, 4, 6
Hence total 12 subarrays will have min number as 3


CODE

class Solution {
public:
    vector<int> NSL(vector<int>& arr, vector<int>& a1){
        stack<int> s1;
        
        for(int i=0; i<arr.size(); ++i){
            while(!s1.empty() && arr[s1.top()] > arr[i]){         // yaha > sign hai
                s1.pop();
            }
            if(s1.empty()){
                a1.push_back(-1);
            }
            else{
                a1.push_back(s1.top());
            }
            s1.push(i);
        }
        // for(auto i: a1){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        return a1;
    }
    
    vector<int> NSR(vector<int>& arr, vector<int>& a2){
        stack<int> s2;
        
        for(int i=arr.size()-1; i>=0; --i){
            while(!s2.empty() && arr[s2.top()] >= arr[i]){      // yaha >=
                s2.pop();
            }
            if(s2.empty()){
                a2.push_back(arr.size());
            }
            else{
                a2.push_back(s2.top());
            }
            s2.push(i);
        }
        reverse(a2.begin(), a2.end());
        // for(auto i: a2){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        return a2;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> a1;
        vector<int> a2;

        NSL(arr, a1);
        NSR(arr, a2);
        
        long ans=0;
        for(int i=0; i<n; ++i){
            ans+= ((long) arr[i]*(i-a1[i])*(a2[i]-i))%1000000007;   // formula to calculate har element ka contribution
            ans%=1000000007;
        }
        return (int) ans;
    }
};


// Abhi isme ar comments likh skte ho agar man ho

>, >= ka chakkar?
Kayde se NSl k liye bhi >= hona chahiye tha but consider the case

[2,13,13,13,13,13,13,13,1]

if we dont handle the repeating case then the answer will be 1117 but the actual answer is 389. 
We have counted several array twice!!
ie iska NSL hoga: -1 0 1 2 3 4 5 6 -1 agar waha pe > use kia
either use >, >= or >=, > for NSL and NSR respectively. As I want ki ek side se 13 ek hi baar count ho.
Jada dikkat ho value daal k dry run kar k dekh lena (padhne time maine dekh lia hai)




