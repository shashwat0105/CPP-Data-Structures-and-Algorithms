// https://leetcode.com/problems/custom-sort-string/

// order= "cba"
// s = "abcd"
// Output = "cbad"
// a->1
// b->1
// c->1
// d->1

string customSortString(string order, string s) {
    map<char, int> mp;
    string ans = "";
    
    for(auto x: s){
        mp[x]++;
    }
    for(auto x: order){
        if(mp.find(x)!=mp.end()){
            auto temp = mp.find(x);
            int count = temp->second;  // c -> 5 ,, ccccc
            
            // for(int i=0;i<count;i++)
            //     ans+=x;
            
            string s(count, x);
            ans+=s;
            mp.erase(x);
        }
    }
    for(auto x: mp){
        string s(x.second, x.first);
        ans+=s;
    }
    return ans;
}

