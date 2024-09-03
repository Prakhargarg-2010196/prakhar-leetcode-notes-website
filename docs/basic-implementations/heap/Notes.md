
[Heap](https://en.wikipedia.org/wiki/Heap_(data_structure))

Heap is implemented as tree data structure which stores the value according to a certain order(max/min) at the root node.
There can be two types of heap generally

1. Max Heap
2. Min Heap

## Applications of Heap

1. priority queue

A C++ priority queue is a type of container adapter, specifically designed such that the first element of the queue is either the greatest or the smallest of all elements in the queue, and elements are in non-increasing or non-decreasing order (hence we can see that each element of the queue has a priority `{fixed order})`.([from here](https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/))

In simple terms, STL Priority Queue is the implementation of Heap Data Structure.

To create a max heap use the following syntax

```c++
#include <iostream>
#include <queue>
using std::priority_queue;
priority_queue<int> pq;
```

Similarly to create a min heap use the following syntax

```c++
#include <iostream>
#include <queue>
#include <vector>
using std::priority_queue,std::greater<int>,std::vector;
priority_queue <int, vector<int>, greater<int>> gq;
```
