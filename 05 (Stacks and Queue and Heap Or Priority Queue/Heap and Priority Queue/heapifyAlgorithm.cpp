// In a complete binary tree.
// Leaf nodes = [n/2+1 to n] th index of the array.  // 1-based indexing

// Eg: [X 54 53 55 52 50]

// Leaf nodes = Index 3 to 5 ie 55, 52, and 50 are the leaf nodes.

// // Leaf nodes are already at their correct position
// // ie only elements from 1 to n/2 needs to placed at correct position.

void heapify(int arr[], int n, int i){    // max heapify
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
    for(int i=n/2; i>0; --i){   // array k har element se heapify call kia hai jiske kuch na kuch child hai
        heapify(arr, n, i);
    }

    cout<<"Printing the array";
    for(int i=1; i<=n; ++i) cout<<arr[i]<<endl;

    return 0;
}


/// min heapify algo

// Hamko pata hai na ki yaha pe insert kia hai hence sirf isko sahi jagah pe pahuchana hai
// Hence, time complexity of heapify kisi ek node pe is O(log n)

void heapify(int arr[], int i) { 
	int smallest = i; // The node which will be heapified 
	int l = 2 * i + 1; // left child node 
	int r = 2 * i + 2; // right child node 

	// Check if left child is smaller than its parent 
	if (l < n && arr[l] < arr[smallest]) 
		smallest = l; 

	// Check if right child is smaller than smallest 
	if (r < n && arr[r] < arr[smallest]) 
		smallest = r; 

	// If smallest is not parent 
	if (smallest != i) { 
		swap(arr[i], arr[smallest]); 

		// Recursively heapify the affected sub-tree 
		heapify(arr, smallest); 
	} 
} 

// Building the entire heap from an array: Upar usi ka code likha hua hai

Quick dekhne se lagega ki TC = O(nlogn) hogi but actual is O(n)
Proof:
https://www.geeksforgeeks.org/time-complexity-of-building-a-heap/  
