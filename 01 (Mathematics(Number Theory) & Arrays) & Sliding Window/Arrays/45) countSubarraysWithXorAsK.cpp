https://www.geeksforgeeks.org/count-number-subarrays-given-xor/

https://youtu.be/lO9R5CaGRPY (Striver)


<-------XR--------->
1 2 3 4 5 6 7 8 9 10 11 12
<---Y--><----K----->

// XR, Y, K are the XOR's of that subarray

// Y^K = XR
// Y = XR^K // taking xor with k with side.
// We know XR(prefix xor) and k(given) I can check for count of such Y's easily now.

Hashmap <prefix xor, count (how many times it is appearing)>

int solve(vector<int> &A, int k){
    unordered_map<int, int> mp;
    int cnt = 0;
    int xorr = 0;
    for(auto it: A){
        xorr = xorr^it;  // prefix xor
        if(xorr==k){
            cnt++;
        }
        if(mp.find(xorr^k)!=mp.end())
            cnt+=mp[xorr^k];
        mp[xorr]++;
    }
    return cnt;
}
