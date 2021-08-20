// Finding first & last occurence of a number in an array
int first_occ(int arr[], int n, int x) {
    int l=0, r=n-1;
    while(l<=r) {
    int mid = l + (r-l)/2;
    if(arr[mid]==x && (mid==0) || arr[mid-1]!=x) return mid;
    if(arr[mid]<=x) r= mid-1;
    else l=mid+1;
    }
    return -1;
}

int last_occ(int arr[], int n, int x) {
    int l=0, r=n-1;
    while(l<=r) {
    int mid = l + (r-l)/2;
    if(arr[mid]==x && (mid==n-1) || arr[mid+1]!=x) return mid;
    if(arr[mid]>x) r= mid-1;
    else l=mid+1;
    }
    return -1;
}
count = last_occ - first_occ + 1;
