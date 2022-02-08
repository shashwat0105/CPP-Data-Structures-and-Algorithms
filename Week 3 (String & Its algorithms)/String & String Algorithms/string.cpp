https://youtu.be/abZEVCRYZP8  (Nice Video)

// C++ provides following two types of string representations −
// 1) The C-style character string.
// char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
// char greeting[] = "Hello";
// 2) The string class type introduced with Standard C++.
// string str1 = "Hello";
// string str2 = "World";

 

// character is stored using single quotes 'a'
// string(group of characters) is stored using double quotes "abcshsaa"

// string letters can be accessed/modified just like array index

int main(){
    string str = "Hello";
    str[0] = 'a';        // but can't do "a" coz you can't modify a character with a string.
    cout<< str << endl;  // str = aello
    str.push_back('b');  // pushes b at the end of the string. Better operation than concatenation due to O(1) complexity.

    cout<< str.size();   // returns length of string

    // cin takes input till it encounters a space or new line
    // So we use getline

    string s;
    getline(cin, s);   // can take input of string such as: "asjsnd dksd     dksmdks"


    // Input multiple strings:
    int t;
    cin>> t;
    cin.ignore();         // to input/output same lines of strings as t (detailed reason in video's pinned comment)
    while(t--){
        string s;
        getline(cin, s);
        cout<< s << endl; 
    }

}

// STRING METHODS:
// string::substr
// stringName.substr(start index, no of characters to include)
// ex:
// string s = abcdedf
// s.substr(2,3) // cde is the output substring

// string::strstr
// For string pattern matching(For detail se practice problem)


// CHECK PALINDROME 
int main(){
    string str;
    cin>>str;
    string str_rev;
    for(int i=str.size()-1; i>=0; --i){
        str_rev.push_back(str[i]);
    }
    // cout<<rev_str; if u want to print reverse of a string
    if(str == str_rev){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}

// Method 2 is runnig the loop till half and comparing the characters

https://youtube.com/playlist?list=PLqjW-ORyj-hLKFq_ESmFpXDnaLKaTCMio (String manipulation small playlist) can refer for logics of good inbuilt/operations methods.

string::find method
https://www.cplusplus.com/reference/string/string/find/
https://www.geeksforgeeks.org/string-find-in-cpp/



// Big numbers > 10^18 are handled using strings.

// STRING ALGORITHMS

// 1) Basic Algorithms
// (i) Sliding window algorithm
// (ii) String Hashing/ Rolling Hash
// (iii) Rabin Karp matching algorithm

// 2) Intermediate Algorithms
// (i) Prefix function and KMP algorithm
// (ii) Z-function and its application
// (iii) Suffix array and its application
// (iv) Trie DS: Implementation and its application

// 3) Advanced Algorithms
// (i) Aho corosick algorithm
// (ii) Suffix Automation & its application
// (iii) Manacher's Algorithm

