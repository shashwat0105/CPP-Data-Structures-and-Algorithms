// An anagram of a string is another string that contains the same characters, only the order of characters can be different. 
// https://www.geeksforgeeks.org/check-whether-two-strings-are-anagram-of-each-other/
// For example, “abcd” and “dabc” are an anagram of each other.

// Method 1: By sorting both the strings (Sorting will take nlogn, comparing will take n, hence total TC = O nlogn)
#include<bits/stdc++.h>
using namespace std;

// int, void, bool are return types, here we want true, false return type
bool areAnagrams(string str1, string str2)
{
    // Get lengths of both strings
    int l1 = str1.length();
    int l2 = str2.length();
  
    // If length of both strings is not same, then they cannot be anagram, also our program won't fail at aaca, aca type
    if (l1 != l2)
        return false;
  
    // Sort both the strings
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
  
    // Compare sorted strings
    for (int i = 0; i < l1; i++)
        if (str1[i] != str2[i])
            return false;

    return true;
    
}

int main()
{
    string str1;
    string str2;
    cout<<"Enter a string"<<endl;
    cin>>str1;
    cout<<"Enter another string"<<endl;
    cin>>str2;
    
    // calling the function
    if(areAnagrams(str1, str2))
    {
        cout<<"Yes, they are anagrams";
    }
    else
    {        
        cout<<"No, they are not anagrams";
    }
    return 0;
}

// Method 2: Storing the frequency of each character if they are equal then anagram
// In two arrays -> incrementing both and then comparing
// In one array -> incrementing one, & decrementing other, count should be zero to be anagram


