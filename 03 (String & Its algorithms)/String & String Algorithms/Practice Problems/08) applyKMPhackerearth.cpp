https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/tutorial/


// Here we have applied KMP in a very innovative way:
// We have merged both the text and pattern with # symbol in between
// Now we will make the prefix array of this merged string
// Number of times the prefix value is == size of the pattern means it has occured.


#include <bits/stdc++.h>
using namespace std;

int main() {
	string pat, text;
	cin>>pat>>text;
	string s = pat + '#' + text;

	int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }

	int res = 0;
	for(int i = pat.size(); i<s.size(); i++){
		if(pi[i] == pat.size()) res++;
	}
	cout<<res;
}
