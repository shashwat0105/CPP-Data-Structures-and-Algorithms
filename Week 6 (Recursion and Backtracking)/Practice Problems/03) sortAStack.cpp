https://www.geeksforgeeks.org/sort-a-stack-using-recursion/
https://practice.geeksforgeeks.org/problems/sort-a-stack/1

Same as sorting an array

STL is : stack.sort()

/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

// there was not a single class so need to declare insert before.
void insertAtCorrectPosition(stack<int> &s, int temp){
    if(s.size()==0 || s.top()<=temp){                   // top of stack has greatest element. Just change < to > then top of stack will have least element. (WOW)
        s.push(temp);
        return;
    }
    
    int val = s.top();
    s.pop();
    insertAtCorrectPosition(s, temp);
    s.push(val);
    return;
}

void SortedStack :: sort()
{
   //Your code here
   if(s.size()==1) return;
   
   int temp = s.top();
   s.pop();
   sort();
   insertAtCorrectPosition(s, temp);
   return;
}

