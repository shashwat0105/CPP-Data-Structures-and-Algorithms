https://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/

Input: 
N = 5
Arr[] = {3, 30, 34, 5, 9}
Output: 9534330

static bool mycmp(string a, string b){
    return a+b>b+a;
}
string printLargest(vector<string> &arr) {
    // code here
    string ans;
    int n = arr.size();
    sort(arr.begin(), arr.end(), mycmp);
    
    for(int i=0; i<n; ++i){
        ans += arr[i];
    }
    return ans;
}
