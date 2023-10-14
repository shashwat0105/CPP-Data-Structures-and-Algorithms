https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

// Gist of the logic used:-

// 1. We're creating a list to store all the negative elements of a current window. At a particular point of time, the list holds negative numbers which are there in the current running window 
// and not all the negative elements in the array. So, that we can retrieve first negative number from the current window.
// 2. When we reached the window size, we need to perform two operations:-
// -> First, we have to retrieve the answer that is the first negative number from the current window. We're checking if the list is empty or not. If it is empty, then there is no negative number 
// in the current window. In that case we'll push 0 in the vector.
// If it's not empty, then the first element in the list is the first negative number of the current window., pushing that into the vector.
// -> Second, we need to slide the window. For that we need to remove the first element of the current window, and add the next element from the array to the window. But before removing the first element, 
// we need to check whether it belongs to the list or not. If it belongs to the list, we need to remove it from the list, as it will not be a part of our next window. 
// So, if the first element is found to be a negative number, then we have to remove it from the list, and this number is happened to be the front element of the list. 
// Then, incrementing the values of i and j to slide the window.

// Template of fixed window problems:
j and i are done separately
while(j<n){
    calculation on j
    if( <k) j++
    if( ==k){
        1) find some ans from that calculation
        2) slide the window i++, j++
    }
}

// Code:
vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k) {
    int i=0, j=0;
    deque<long long> dq;
    vector<long long> res;
    while(j<n){
        if(arr[j]<0) dq.push_back(arr[j]);  
        if(j-i+1 < k) j++;
        else if(j-i+1==k){
            // ans from that calculation
            if(dq.size()==0){
                res.push_back(0);
            }
            else{
                res.push_back(dq.front());  // ans from calculation
                
                if(arr[i]<0){ 
                    dq.pop_front();  // that number is not in our window now hence cannot be in our list
                }
            }
            // slide the window
            i++;
            j++;
        }
    }
    return res;
}
