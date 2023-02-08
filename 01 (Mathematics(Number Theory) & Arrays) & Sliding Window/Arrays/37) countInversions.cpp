Modified Merge Sort

https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
This problem can be solved by:
1) brute force two loops: O(n^2)
2) Modified merge sort (sufficient in an interview)
3) Fenwick tree

https://youtu.be/kQ1mJlwW-c0  (Striver)
https://youtu.be/fk0Estiuvz4 (Coding Ninjas) Better explanation
https://youtu.be/owZhw-A0yWE (Tech Dose) Explanation with dry run

Modification:
While applying the merge sort in the merge process:-
Whenever something came from the right in merging, 
everything in the right of the pointer of the left part is added to the count.
This will modify the array.
We can create a copy and apply merge sort there.

TC = O(nlogn)
SC = O(n)

1) I divide the array into two.
2) Sort them and as well as ask then ki unki andar kitne inversions hai. ie( merge sort two arrays + calculate inversion count in respective arrays)
3) Now we need to find inversions among these two half arrays. We will do this in the merge step.
  Count = Left inversion count + Right inversion Count + Count during merging.

Break kar kar k ek ek element bhi bachega uska bhi counting merge function karega while merging.

Merge step:
3 6 7         0 1 2 5 8
Now we can see 0<3 while merging so, what we need to do is that we need to add count of all elements after 3 coz they are also bigger than 3 
then we will add 0 to our final array.

// CODE

long long int merge(vector<long long> &nums, long long low, long long mid, long long high){
    long long cnt = 0, k = 0;
    int l = low, r = mid+1, size = high-low+1;  // l is left array start pt, r = right array start pt
    
    vector<long long> sorted(size);
    
    while(l<=mid && r<=high){
        if(nums[l] <= nums[r]) sorted[k++] = nums[l++];  // koi dikkat hi ni hai
        else{
            sorted[k++] = nums[r++];
            cnt = cnt + (mid-l+1);   // inversion found
        }
    }
    
    while(l<=mid) sorted[k++] = nums[l++];
    while(r<=high) sorted[k++] = nums[r++];
    
    for(k=0; k<size; ++k) nums[k+low] = sorted[k];
    
    return cnt;
}

long long int mergeSort(vector<long long> &nums, long long low, long long high){
    long long inv_cnt = 0;
    if(low>=high) return 0;
    int mid = (low+high)>>1;
    inv_cnt += mergeSort(nums, low, mid);
    inv_cnt += mergeSort(nums, mid+1, high);
    inv_cnt += merge(nums, low, mid, high);
    
    return inv_cnt;
}

long long int inversionCount(long long arr[], long long N){
    // Your Code Here
    vector<long long> nums;
    for(int i=0; i<N; ++i) nums.push_back(arr[i]);
    return mergeSort(nums, 0, N-1);
}


// Alternate Code(Kinda Better):

#include<bits/stdc++.h>
using namespace std;

int merge(int arr[],int temp[],int left,int mid,int right){
    int inv_count=0;
    int i = left;   // left array start pt
    int j = mid;    // right array start pt
    int k = left;   // k to place elements finally back to our array
    while((i <= mid-1) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while(i <= mid - 1) temp[k++] = arr[i++];

    while(j <= right) temp[k++] = arr[j++];

    for(i = left ; i <= right ; i++) arr[i] = temp[i];
    
    return inv_count;
}

int merge_Sort(int arr[],int temp[],int left,int right)
{
    int mid,inv_count = 0;
    if(right > left)
    {
        mid = (left + right)/2;

        inv_count += merge_Sort(arr,temp,left,mid);
        inv_count += merge_Sort(arr,temp,mid+1,right);

        inv_count += merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
}

int main()
{
    int arr[]={5,3,2,1,4};
    int n=5;
    int temp[n];
    int ans = merge_Sort(arr,temp,0,n-1);
    cout<<"The total inversions are "<<ans<<endl; 

    return 0;
}
