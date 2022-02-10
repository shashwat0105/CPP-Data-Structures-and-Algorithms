https://www.spoj.com/problems/ADAPET/

string s
integer k

We have to find the minimum length of a string which contains string s, k number of times

void KMP(string s) {
	int n = s.size();
    vector<int> pi(n);
	for (int i = 1; i < n; i++) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
		j = pi[j-1];
		if (s[i] == s[j])
		j++;
		pi[i] = j;
	}
}

cout<<(k*n - (k-1)*pi[n-1])<<endl;         // LOGIC

