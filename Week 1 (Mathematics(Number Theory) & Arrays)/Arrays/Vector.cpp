#include<iostream>
#include<vector>

int main()
{
    vector<int> v;

    //Push elements
    for(int i=1; i<=5; i++)
    {
        v.push_back(i);
    }
    cout<<"Size: "<<v.size();

    //Checking if the vector is empty or not, empty() returns whether the container is empty
    if(v.empty()==false)
        cout<<"\nVector is not empty";
    else
    {
        cout<<"\nVector is empty";
    }
    
    cout<<"\nOutput from begin to end";
    for(auto i = v.begin(); i!=v.end() ; ++i)   // this is range based for loop
    {
        cout<<*i<<" ";
    }

    //emplace() – It extends the container by inserting new element at position.
    //emplace_back() – It is used to insert a new element into the vector container, the new element is added to the end of the vector.
    //inserts 45 at beginning 
    v.emplace(v.begin(),45);
    //inserts 65 at end
    v.emplace_back(65)

    cout<<"\nThe first element is"<<v[0];
    int n=v.size();
    cout<<"\nThe last element is"<<v[n-1];

    // erases the vector 
    v.clear(); 
    cout << "\nVector size after erase(): " << v.size();  

    return 0;
}