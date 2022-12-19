Good for face 2 face interview question,
but online platform m nahi aa skta

size-1 is not defined coz infinite
where to mark the high index?

say:
start at 0 index
and high at 1 index
target should always be between start and high.
Compare target and high, if not bounded then high = 2*high.
And start will go to old high.
Now you obtained the start and end index. Hence u can obtain as usual Binary search.

int low = 0;
int high = 1;
// to find low and high
while(key>arr[high]){
    low = high;
    high = 2*high;
}
// as usual binary search.
binary search(arr, low, high){};



