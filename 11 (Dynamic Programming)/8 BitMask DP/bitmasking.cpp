Example:
s = {1, 5}
This s can be represented as just 17 coz: [0 0 0 ... 0 1 0 0 0 1] in binary.


// Example:
Given a set represented as a bitmask.
Implement:
1) adding element to set
2) removing element from set
3) display elements of the set.

//
void add(int &subset, int x){
    subset = (subset ^ (1<< (x-1)));
}

void remove(int &subset, int x){      // I want to turn that bit to zero.
    // assuming x is not in the subset
    subset = (subset ^ (1<< (x-1))); // becoz i is represented by i-1th bit. XOR does the work. Rest bits stay the same
}

void display(int subset){
    for(int bit_no = 0; bit_no <= 9; bit_no++){  // assuming the range is between 0 and 9
        if(subset & (1 << bit_no)){             // And with 2^i to check if that partcular bit is set or not
            cout<<bit_no + 1<<' '; 
        }
    }
}

int main(){
    int set = 15;
    remove(set, 2);
    add(set, 5);
    display(set);
     
    return 0;
}
