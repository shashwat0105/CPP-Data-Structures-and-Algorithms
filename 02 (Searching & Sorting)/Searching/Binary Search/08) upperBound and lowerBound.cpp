https://youtu.be/Cg7SI0WtmXY

https://youtu.be/edJ19qIL8WQ  TO watch striver

Array should be sorted.

For an element x in the search space.
Lower bound: Finds x and returns its iterator (if multiple x are there returns the iterator of first x), 
             if x is not there finds an element just greater than x.

Upper bound: Agar wo element present bhi hai na toh bhi uska greater hi element nikalega.
ie doesnot finds x.

They return the location of the element.
for arrays returns pointer
for vector returns iterator.

// for array
int a[n];
4 5 5 7 8 25
int *ptr = upper_bound(a+4, a+n, 5); // return 8 among 8 25 search space
cout<<*ptr;

// for vectors (prefrerred)
vector<int> a(n);
4 5 5 7 8 25
auto it = upper_bound(a.begin(), a.end(), 5);
if(it==a.end()) cout<<"Not found"; return 0;
cout<<(*it)<<endl;
cout<< it-a.begin(); // I will get the index.

// set and maps
they are sorted

set<int>s;
auto it = lower_bound(s.begin(), s.end(), 5); // this functions runs but has O(n) complexity instead of O(logn) hence will give tle for large inputs.
// hence this is wrong. we have to write in O(logn)
// we have to do
auto it = s.lower_bound(5);  // correct

map<int, int> m;
// lower bound, upper bound application on key only
// return the iterator of the value / bigger value.

// std: binary_search
std::binary_search (v.begin(), v.end(), 3)

// Internal implementation of lower bound, upper bound
// in case of arrays/vectors: binary search
// in case of sets/maps : tree traversal

