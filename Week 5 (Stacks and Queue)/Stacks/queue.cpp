https://www.cplusplus.com/reference/queue/queue/

FIFO (Topmost / pop element is the first element that got in first)

// Implement Queue using Array
3     2 1 8 6
Front       Rear

If we perform a push operation after a pop operation, we can manage it using a circular array ie taking modulo.

// Given the size of array is n

push(x){
    if(cnt==n){    // ie the queue is full
        return -1;
    }
    a[rear%n] = x;
    rear++;
    cnt++;
}

pop(){
    if(cnt==0) return; // no element in the queue
    a[front%n] = -1;   // a dummy number assigned
    front++;
    cnt--;
}

top(){
    if(cnt==0) return -1; // no element in the queue
    return a[front%n];    
}


