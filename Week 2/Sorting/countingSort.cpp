// counts the number of occurences of each unique element
// not a comparison sort.
// Time  O(n+k)
// Space O(n+k)
// part of Radix sort
// n is number of element k is the range of input
// 5 for loops are used

#include<iostream>
using namespace std;

void countingSort(int input_arr[], int s, int r)
{
    // Step 1. Create output array of the same size(say 5 elements)
    int output_arr[s];
    // Step 2. Create output array of size range(10 coz 0-9)
    int count_arr[r];

    // Step 3. Initiallise all elements of count array to zero
    for(int i=0; i<r; i++)
    {
        count_arr[i] = 0;
    }
    
    // All the elements of input array are mapped to indexes in count array
    // Step 4. Increment the value of elements(all 0 inititally) of count array at the index where an element is found in input array
    // To take count of all elements of the input array
    for(int i=0; i<r; i++)
    {
        ++count_arr[input_arr[i]];   // say i = 0; input_arr[i] = 5 ; count_arr[5] value will be increased by 1 
    }

    // Step 5. Cummulative count of count array to get the positions of elements to be stored in output array
    for(int i = 1; i<r; i++)  // no element before 0
    {
        count_arr[i] = count_arr[i] + count_arr[i-1];
    }

    // Step 6. placing elements of input array in output array so that result is a sorted array
    for(int i=0; i<s; i++)
    {
        output_arr[--count_arr[input_arr[i]]] = input_arr[i];  // dry run this u will get
    }

    // Step 7. Copy from output to input
    for(int i=0; i<s; i++)
    {
        input_arr[i] = output_arr[i];
    }

}

int main()
{
    int size = 0;
    int range = 10; // in our case elements will be from 0 to 9
    
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    int myarr[size];

    cout<<"Enter "<<size<<" integers in any order lying between 0 & 9:"<<endl;
    for(int i = 0; i<size; i++)
    {
        cin>>myarr[i];
    }

    // say 5 , 6 , 1, 1, 6
    countingSort(myarr, size, range);  // function call

    for(int i = 0; i<size; i++)
    {
        cout<<myarr[i]<<" ";
    }

    return 0;
}

