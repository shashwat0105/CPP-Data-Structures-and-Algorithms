https://leetcode.com/problems/reverse-pairs/

Future Read:
https://leetcode.com/problems/reverse-pairs/solutions/97268/general-principles-behind-problems-similar-to-reverse-pairs/

class Solution {
public:
// https://youtu.be/S6rsAlj_iB4 (Striver)
    int merge(vector<int> &nums, int low, int mid, int high){
        int cnt = 0;
        int j = mid+1;
        // counting reverse pairs separtely in the two halfs
        for(int i=low; i<=mid; ++i){
            while(j<=high && nums[i]>2ll*nums[j]) j++;
            cnt+= (j-(mid+1));
        }

        // or using while loop to count
        // int l = start, r = mid + 1;
        // while (l <= mid && r <= end){
        //     if ((long) nums[l] > (long) 2 * nums[r]){
        //         count += (mid - l + 1);
        //         r++;
        //     }else {
        //         l++;
        //     }
        // }
        vector<int> temp;
        int left = low, right = mid+1;
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) temp.push_back(nums[left++]);
            else temp.push_back(nums[right++]);
        }
        while (left <= mid) temp.push_back(nums[left++]);
        
        while (right <= high) temp.push_back(nums[right++]);
        
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
        return cnt;
        // or using array we can do ++ instead of push_back
        // int a[end - start + 1], t = 0;
        // l = start, r = mid + 1;
        // while (l <= mid and r <= end) {
        //     if (l <= mid and nums[l] < nums[r]) {
        //         a[t++] = nums[l++];
        //     } else {
        //         a[t++] = nums[r++];
        //     }
        // }
        // while (l <= mid) {
        //     a[t++] = nums[l++];
        // }
        // while (r <= end) {
        //     a[t++] = nums[r++];
        // }
        // for (int i = 0; i < end - start + 1; i++) {
        //     nums[start + i] = a[i];
        // }
    }

    int mergeSort(vector<int> &nums, int low, int high){
        if(low>=high) return 0;
        int mid = (low + high)>>1;
        int inv = mergeSort(nums, low, mid);
        inv    += mergeSort(nums, mid+1, high);
        inv    += merge(nums, low, mid, high);  // all the count happens at this merge or countInversions
        return inv; 
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};