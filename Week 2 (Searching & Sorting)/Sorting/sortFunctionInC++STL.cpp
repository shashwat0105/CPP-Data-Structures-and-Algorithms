// By Default sorts in ascending order
// Sort an array: sort(arr, arr+n)
// Sort a vector: sort(vec.begin(), vec.end())
// sort(arr, arr+n, greater<int>())  // Puts greater element before hence sorting in descending order.
//  We can also write our own comparator function and pass it as a third parameter. To sort in particular order
#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Sorting Array
    int arr1 = {3,2,5,6,8,6};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    sort(arr1, arr1 + n1);

    // Sorting array in reverse order
    int arr2 = {2, 4, 5, 1, 3};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    sort(arr2, arr2+n2, greater<int>());

    // Sorting Vector
    vector<int>vec = { 3, 4, 2, 5, 8, 6};

    sort(vec.begin(), vec.end());

    // Printing them
    for(int i = 0; i<n1; i++)
        cout<<arr1[i]<<" ";
    
    for(int j = 0; j<n2; j++)
        cout<<arr2[j]<<" ";

    for(int k=0; k<vec.size(); k++)
        cout<<vec[k]<<" ";
        
    return 0;
}

