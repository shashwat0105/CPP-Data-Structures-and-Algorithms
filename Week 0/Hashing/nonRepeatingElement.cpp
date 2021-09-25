// https://practice.geeksforgeeks.org/problems/non-repeating-element3958/1

// int arr[] = {5, -1, 2, -1, 3, 2}

// We will use unordered_map
// Key = the element
// Value = its occurence

int firstNonRepeating(int arr[], int n){ 
    unordered_map<int, int> umap;
    for(int i=0; i<n; i++){
        umap[arr[i]]++;
    }
    for(int i=0; i<n; i++){
        if(umap[arr[i]]==1){
            return arr[i];
        }
    }
    return 0;
} 


// https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1#

int firstRepeated(int arr[], int n) {
        // code here
    unordered_map<int,int> umap;
    for(int i=0; i<n; i++){
        umap[arr[i]]++;
    }
    for(int i=0; i<n; i++){
        if(umap[arr[i]]>1){
            return i+1;
        }
    }
    return -1;
}
