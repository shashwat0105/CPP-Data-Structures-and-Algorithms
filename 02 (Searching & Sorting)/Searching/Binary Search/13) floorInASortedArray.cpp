https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

 Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x. 
 To return index of k


int findFloor(vector<long long> v, long long n, long long x){
    return upper_bound(v.begin(), v.end(), x)-v.begin() -1;
}

//
if(arr[mid]==ele) then our search is over
if(arr[mid]<ele) mid is a possible candidate and we store it, and move to mid+1
if(arr[mid]>ele) mid is not a possible candidate reject and we mvoe to mid-1 in search of smaller elements.

