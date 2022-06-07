// repeatedly finding the minimum element (considering ascending order) 
// from unsorted part and putting it at the beginning(of unsorted part of array).

void selectionSort(int arr[], int n)
{
    int i, j , min_idx;

    // One by one moving boundary of unsorted array
    for(int i=0; i<n-1; i++)
    {
        // finding minimum element in unsorted part
        min_idx = i; // initialising the index of min element at i (beginning element of unsorted part of array)
        for(j=i+1; j<n; j++)
            if(arr[j]<arr[min_idx])
                min_idx = j;

        swap(arr[min_idx], arr[i]);        
    }
}