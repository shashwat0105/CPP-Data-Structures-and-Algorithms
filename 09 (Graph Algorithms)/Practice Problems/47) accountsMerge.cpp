https://leetcode.com/problems/accounts-merge/

// Good ques of Union Find
// Medium-Hard asked in Nutanix perhaps

// Yet to understand better

static int fastio=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    # define endl '\n'
    return 0;
}();
// Good question of Union Find
class Solution {
private:
    string find(string s, unordered_map<string, string>& p) {
        
        if(p[s]==s)
            return s;
        return p[s]=find(p[s],p); // using path compression
        // return p[s] == s ? s : find(p[s], p);
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acts) {
        unordered_map<string, string> owner;
        unordered_map<string, string> parents;
        unordered_map<string, set<string>> unions;
        
        for (int i = 0; i < acts.size(); i++) {
            for (int j = 1; j < acts[i].size(); j++) {
                parents[acts[i][j]] = acts[i][j]; // initially self parent
                owner[acts[i][j]] = acts[i][0];
            }
        }
        
        // Tricky Part
        for (int i = 0; i < acts.size(); i++) {
            string p = find(acts[i][1], parents);
            for (int j = 2; j < acts[i].size(); j++)
                parents[find(acts[i][j], parents)] = p; // then making the first elements parent as alls parent
        }
        
        // Save the emails with same parent email to same set
        for (int i = 0; i < acts.size(); i++)
            for (int j = 1; j < acts[i].size(); j++)
                unions[find(acts[i][j], parents)].insert(acts[i][j]);

        vector<vector<string>> ans;
        for (const auto& p : unions) {
            vector<string> emails(p.second.begin(), p.second.end()); // convert set to vector
            emails.insert(emails.begin(), owner[p.first]); // insert the owner at the start of vector , p.first is the parent email of all p.second(s)
            ans.push_back(emails);
        }
        return ans;
    }
};

