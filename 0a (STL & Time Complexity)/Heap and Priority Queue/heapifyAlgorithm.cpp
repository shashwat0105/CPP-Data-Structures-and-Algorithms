// In a complete binary tree.
// Leaf nodes = [n/2+1 to n] th index of the array.

// Eg: [X 54 53 55 52 50]

// Leaf nodes = Index 3 to 5 ie 55, 52, and 50 are the leaf nodes.

// // Leaf nodes are alreayd at their correct position
// // ie only elements from 1 to n/2 needs to places at correct position.

void heapify(int arr[], int n, int i){
    int largest = i;  // The element that needs to be taken to correct place.
    int left = 2*i;
    int right = 2*i+1;

    if(left<=n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <=n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest!= i){  // ie largest has been updated
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);  // recur again for remaining
    }
}

int main(){
    heap h;
    // Jo jo insert hoga wo left side se fill hoga in the BST

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteFromHeap();
    h.print(); 

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i=n/2; i>0; --i){
        heapify(arr, n, i);
    }

    cout<<"Printing the array";
    for(int i=1; i<=n; ++i) cout<<arr[i]<<endl;

    return 0;
}
