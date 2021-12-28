// https://youtu.be/UJkE-apV9Dk 
// technique to uniquely identify a specific object from a group of similar objects.

// Large keys are converted into small keys(index) by using hash functions(some logic). (Hashing with separate chaining technique)

// Hash table (These maping of keys)
// bookew12 - 0
// hello13c - 1
// carl12cd - 2

// An array has both +ve and -ve numbers, elements in the range -MAX to +MAX (in this ques Max is not very large)
// To search a number:

// O(n) approach
// To traverse the whole array.

// O(1) approach
// Using hash table

// Since -ve no we will use a 2D array of size [MAX+1][2]
//     0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 ... MAX
// 0                                                    // mark in this row if the no is +ve
// 1                                                    // mark in this row if the no is -ve

// hash cant be used as a variable name coz its a reserved keyword.

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

bool hashTable[MAX+1][2];   // all have 0 value, coz global

bool search(int x){
    if(x>=0){
        if(hashTable[x][0]==1){
            return true;
        }
        else{
            return false;
        }   
    }
    else{
        x=abs(x);
        if(hashTable[x][1]==1){
            return true;
        }
        else{
            return false;
        }
    }
}

void insert(int a[], int n){
    for(int i=0;i<n; i++){
        if(a[i]>=0){
            hashTable[a[i]][0]=1;
        }
        else{
            hashTable[abs(a[i])][1]=1;
        }
    }
}

int main(){
    int arr[] = {-1,9,2,-5,3,1};
    int n = sizeof(arr)/ sizeof(arr[0]);
    insert(arr,n);

    int find = -3;
    if(search(find)){
        cout<<"Element is present"<<endl;
    }
    else{
        cout<<"Element is not present"<<endl;
    }
}
 
// **************************************************************
// Hashing: Search, Insert, Delete - O(1) & O(len) for string of length "len"


// Examples of Hash function

// H(large_key) = large_key%m // ideally we chose a prime no for m, to reduce collisons(multiple values mapping to same key)

// For strings, weighted sum
// str[] = "abcd"
// str[0]*x^0 + str[1]*x^1 + str[2]*x^2 + str[3]*x^3     // where str[0] is ASCII value of the element
 
// Chaining
// Hash(key) = key%7;
// Key = {50,21,58,17,15,49,56,22,23,25}

// 0  21 -> 49 -> 56
// 1  50 -> 15 -> 21
// 2  58 -> 23
// 3  17
// 4  25
// 5
// 6

// Load factor alpha = n/m = no of keys to be inserted/ no of slots in Hash table  // We aim to minimise alpha
 
// *************************************************

