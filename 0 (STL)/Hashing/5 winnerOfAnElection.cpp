// https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1

// Unordered Map will look like:
// John -> 4
// Johnny -> 4
// Jamie -> 3
// Jackie -> 2

vector<string> winner(string arr[],int n)  // we want to return a vector of string
{
    unordered_map<string, int> umap;
    for(int i=0; i<n; i++){
        umap[arr[i]]++;                    // storing the elements
    }
    
    string name = "";
    int max_vote = 0;
    for(auto itr = umap.begin(); itr!=umap.end(); itr++){
        string key = itr->first;           // first element is a string
        int val = itr->second;             // second element is an integer
        
        if(val>max_vote){
            max_vote = val;
            name = key;
        }
        else if(val==max_vote){
            if(key<name){                  // comparing the names if the votes are equal
                name=key;
            }
        }
    }
    
    vector<string>ans;                    // declaring a vector of string
    ans.push_back(name);
    string temp = to_string(max_vote);    // to_string is a inbuilt string to convert to string coz max_vote is an integer
    ans.push_back(temp);
    // ans.push_back(to_string(max_vote));
    
    return ans;
}
