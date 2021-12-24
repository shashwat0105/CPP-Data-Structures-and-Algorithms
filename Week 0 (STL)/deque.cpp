// Sequence container
// Expanded or Contracted on both ends
push_front
pop_front
push_back
pop_back
[]
back()
front()

// Create a deque
deque<int> first;
deque<int> dq(10);         // deque of 10 elements
deque<int> second(4,100);  // 100 100 100 100
deque<int> third(second.begin(), second.end());  // iterating over second
deque<int> fourth(third);  // copy of third
 


#include<dequeue>
using namespace std;

