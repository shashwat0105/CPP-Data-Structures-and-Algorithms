https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/

// Two pointer approach
class Solution {
public:
    int takeCharacters(string s, int k) {
        // left ar right se element nikal rahe hai toh beech m remaining jo hai wo ek variable size sliding window hai esa mujhe dikhna chahiye
        // aabaaaacaabc, k = 2
        // after removing 2 a, 2 b and 2 c, I should be atmax left with 6a , 1b, 0c substring, I will try to find such substring

        int a=0,b=0,c=0; // to store count of the alphabets
        int n = s.size();
        for(int i=0; i<n; ++i){
            if(s[i]=='a') a++;
            else if(s[i]=='b') b++;
            else c++;
        }
        // itne bachenge maximum best case mein 
        a=a-k;
        b=b-k;
        c=c-k;
        if(a<0 || b<0 || c<0) return -1; // insufficient count of alphabets in the string

        int ans=0;
        int pa=0, pb=0, pc=0;
        int j=0;
        for(int i=0; i<n; ++i){
            if(s[i]=='a') pa++;
            else if(s[i]=='b') pb++;
            else pc++;
            
            // if in our window pa exceeds the max allowed count, peeche se traverse karna chalu karenge jab tak hamko 'a nahi mil jata frse taaki window jo violate kari thi wo frse sahi ho jae
            while(pa>a){
                if(s[j]!='a'){
                    if(s[j]=='b'){
                        pb--;
                    }
                    else {
                        pc--;
                    }
                    j++;
                }
                else{  // a mil gaya
                    pa--;
                    j++;
                }
            }
            while(pb>b){
                if(s[j]!='b'){
                    if(s[j]=='a'){
                        pa--;
                    }
                    else {
                        pc--;
                    }
                    j++;
                }
                else{
                    pb--;
                    j++;
                }
            }
            while(pc>c){
                if(s[j]!='c'){
                    if(s[j]=='a'){
                        pa--;
                    }
                    else {
                        pb--;
                    }
                    j++;
                }
                else{
                    pc--;
                    j++;
                }
            }
            
            ans=max(ans,i-j+1);
            
        }
        return n-ans; 
    }
};

or

class Solution {
public:
    int takeCharacters(string s, int k) {
        int ca=0,cb=0,cc=0;
        int n=s.size();
        int ans=n;
        for(int i=0;i<n;i++){
            if(s[i]=='a') ca++;
            if(s[i]=='b') cb++;
            if(s[i]=='c') cc++;
        }
        if(ca<k||cb<k||cc<k) return -1;
        int i=n-1,j=n-1;
        while(i>=0){
            if(s[i]=='a') ca--;
            if(s[i]=='b') cb--;
            if(s[i]=='c') cc--;
            while(ca<k||cb<k||cc<k){
            if(s[j]=='a') ca++;
            if(s[j]=='b') cb++;
            if(s[j]=='c') cc++;
                j--;
            }
            ans=min(ans,i+n-1-j); i--;
        }
        return ans;
    }
};

// Using extra space ie map
class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char, int> cnt;
        for(auto c: s)
            cnt[c]++;
        
        if(cnt['a'] < k || cnt['b'] < k  || cnt['c'] < k )
            return -1;

        int windowSize = 0, startPos = 0;
        int curMin = s.length();
        // try to find the max window as possible
        // max window size = min leftover(what the problem asks for)
        for(int i = 0, N = s.length(); i < N; i++){
            
            windowSize++;
            cnt[s[i]]--;

            while(cnt[s[i]] < k){ /* there is not enough s[i] outside the window */
                cnt[s[startPos]]++;      /* add back the j th char */
                startPos++;              /* move the window to the right by 1 */
                // count[s[j++]]++; bhi likh skte hai
                windowSize--;     /* decrement windowSize here because it */
                                  /* will increment again next iteration */
            }
            // Why can we constantly move the window to the right (incrementing j)
            // if it dose not meet the criteria for the first time?
            // answer:
            //      If left startPos char out for the first time will cause the answer invalid, 
            //      no matter how big the window is, it will never be a valid answer.
            //      If n-1 is valid, we know the window size n-1 is valid and there is no need for testing a smaller window size.
            curMin = min(curMin, N - windowSize);
        }

        return curMin;
    }
};
