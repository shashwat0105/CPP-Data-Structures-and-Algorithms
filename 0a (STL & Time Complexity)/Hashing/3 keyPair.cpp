// https://practice.geeksforgeeks.org/problems/key-pair5616/1#

// Don't get confused with subset sum problem of dynamic programming.
// subset sum can contain any no of elements to form that sum

// Here, that subset should contain exactly 2 elements.

bool hasArrayTwoCandidates(int arr[], int N, int s) {
    unordered_map<int, int> umap;
    for(int i=0; i<N; i++){
        umap[arr[i]]++;
    }
    
    for(auto itr=umap.begin(); itr!=umap.end(); itr++){
        int key = itr->first;
        int val = itr->second;
        
        int pair = s - key;
        
        if(pair==key){                        // say sum = 8, and arr[] = {2,4,6,7}, on getting 4 as a key, pair = 4, but it will only be valid when there are two 4's is val>1
            if(val>1)
                return true;
        }
        else{
            if(umap.find(pair)!=umap.end())   // finding the pair in the remaining map.
                return true;
        }
    }
    return false;
}

