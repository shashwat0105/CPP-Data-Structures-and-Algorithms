https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

Leetcode 340 (premium)

Condition: Jaha pe k unique characters ho wo apni candidate window hogi.

 int longestKSubstr(string s, int k) {
// your code here
    int n = s.size();
    int i=0, j=0;
    unordered_map<int, int> m; // map is much better than set, can store unique as well as count both are required here
    int maxi=-1; // for the case when there is no substring with k distinct characters
    while(j<n){  // three cases < = >
        m[s[j]]++;
        if(m.size()<k){  // no issue 
            j++;
        }
        if(m.size()==k){
            // we get an ans
            maxi = max(maxi, j-i+1); // j-i+1 is the size of window
            j++;
        }
        if(m.size()>k){
            // using a while loop to continuosly reduce the element so that it gets valid
            while(m.size()>k){ // till this condition doesn't becomes false
                m[s[i]]--;
                if(m[s[i]]==0){ // even if the element count becomes zero it still remains inside the map we need to remove it
                    m.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return maxi;
}
