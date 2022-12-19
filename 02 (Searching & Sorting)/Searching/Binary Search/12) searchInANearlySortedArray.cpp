Certain elements are shifted to either of the adjacent indexes after the array was sorted, i.e., arr[i] may be present at arr[i+1] or arr[i-1]. 
Basically, the element arr[i] can only be swapped with either arr[i+1] or arr[i-1].

private static int binarySearchNearlySorted(int[] a, int target) {
    int n = a.length;
    int start = 0;
    int end = n-1;

    while(start <= end) {
        int mid = (start + end)/2;

        if(target == a[mid]) {
            return mid;
        }

        if(mid > 0 && target == a[mid-1]) {
            return mid-1;
        }

        if(mid < n-1 && target == a[mid+1]) {
            return mid+1;
        }

        if (target < a[mid]) {
            end = mid-2;
        } else {
            start = mid+2;
        }
    }

    return -1;
}
