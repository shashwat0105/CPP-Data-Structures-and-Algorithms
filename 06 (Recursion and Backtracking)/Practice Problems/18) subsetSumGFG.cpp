https://practice.geeksforgeeks.org/problems/subset-sums2234/1#

// To interviewer
// Brute force using bit manipulation to generate power set TC = O(2^N*k)

void solve(int i, vector<int> &ip, int sum, vector<int> &ans){
    if(i==ip.size()){
        ans.push_back(sum);
        return;
    }
    
    // pick
    solve(i+1, ip, sum+ip[i], ans);
    // not pick
    solve(i+1, ip, sum, ans);
}

vector<int> subsetSums(vector<int> arr, int N){
    // Write Your Code here
    vector<int> ans;

    solve(0, arr, 0, ans);
    return ans;
}

// Dusra hai ki wahi op nikalo ar fr op k har element ko add krke sum nikal k ans m push kr do(Jiski jaroorat ni hai)

// Very Similar ques
https://leetcode.com/problems/sum-of-all-subset-xor-totals/
