
Ceil of A: smallest element greater than A.

say ceil of 5:
8, 9, 11 , 13 can be candidate in finding ceil of 5
we have to chose the best ie smallest.


if(arr[mid]==ele) wahi khatam ho gaya
if(arr[mid]>ele) it is a candidate we store it in res. and move towards left ie mid-1
if(arr[mid]<ele) not store in res. and move towards right mid+1 to find a possible element.


