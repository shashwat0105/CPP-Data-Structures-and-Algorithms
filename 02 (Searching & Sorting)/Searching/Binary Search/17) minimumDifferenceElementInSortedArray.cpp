Array given: 1 3 4 5 8 10 15

key = 12

u need to return 10.

while(low<=high){
    if(ele==arr[mid]) return arr[mid];
    else if(ele<arr[mid]) high = mid-1;
    else low = mid+1;
}
compare abs(arr[low]-key) and abs(arr[high]-key)
return the one that gives minimum.

Reasoning:
After the loop exits
1 3 4 5 8 10       15
          high low/mid

ie low and high points towards our desired position in low<=high
