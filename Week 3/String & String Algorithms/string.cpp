https://youtu.be/abZEVCRYZP8  (Nice Video)

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

// Big numbers > 10^18 are handled using strings.

