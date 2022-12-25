// https://leetcode.com/problems/merge-sorted-array/

// https://youtu.be/FyzWXlSMNoI

// simply used the merge function of the merge sort. (from last)
// TC = O(m+n)
// SC = O(1)

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int i = m-1;
    int j = n-1;
    int k = m+n-1;
    
    while(i>=0 && j>=0){
        if(nums1[i] > nums2[j]){
            nums1[k--] = nums1[i--];        // k position pe jo badi value hogi wo jaegi either from i or j
        }
        else{
            nums1[k--] = nums2[j--];
        }
        
    }
    while(i>=0){                           // the code will also work without this while block as well
        nums1[k--] = nums1[i--];
    }
    
    while(j>=0){
        nums1[k--] = nums2[j--];
    }
    
}

