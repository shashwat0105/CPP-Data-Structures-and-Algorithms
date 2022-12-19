Binary search can be applied on unsorted array.

There is a criteria for the key
And we have to see hamara ans kis side mein lie karega
for example to find peak of the mountain. (there is only one peak)

peak can be mid
peak can lie on left half
peak can lie on right half

find peak question (multiple peaks are there) we go towards larger element from mid.

Bitonic array(also not sorted but can apply binary search):
Monotonic increase then monotonic decrease
There is only one peak element
can solve using binary search.


Search element in bitonic array:
Find peak element
Apply increasing binary search on 0 to peak-1
Apply decreasing binary search on peak to end element
And see if you can search the element.

Similar to pivot that u found in case of rotated sorted array.
