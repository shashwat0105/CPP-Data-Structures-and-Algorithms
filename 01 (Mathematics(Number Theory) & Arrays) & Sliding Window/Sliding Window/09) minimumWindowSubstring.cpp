https://leetcode.com/problems/minimum-window-substring/

// Hardest problem of Sliding window

count= mp.size() jab bhi koi character decrement hoke zero hoga, count ko ek less kar denge.
jaha count 0 ho jaega wo esi sliding window hai jo possible answer hai.
count of a charcter will go in negative as well. T T T T T A , T T A , start k extra T hata denge seeing the negative count.
count = 1 hua means it is no longer our ans tab j increment karenge ans milega use optimise krne k liye i increment karenge


// Aditya verma solution



// Other solution
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size())
            return "";
        unordered_map<char,int> mp;
        for(auto a:t)
            mp[a]++;
        int i=0,j=0, cnt=t.size();
        int st=0;
        int ans=INT_MAX;
        while(j<s.size())
        {
            mp[s[j]]--;
            if(mp[s[j]]>=0)
                cnt--;
            j++;
            while(cnt==0)
            {
                mp[s[i]]++;
                if(ans>(j-i))
                {
                    ans=j-i;
                    st=i;
                }
                if(mp[s[i]]>0)
                    cnt++;
                i++;
            }
        }
        return ans==INT_MAX?"":s.substr(st,ans);
    }
};
