# Implementation
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


### Illustration of usage of priority queue data structure in stl library
```cpp
// Creating a priority queue in c++ using stl
#include <iostream>
#include <queue>
#include <vector>
using std::priority_queue,
      std::cout, 
      std::cin,
      std::endl,
      std::greater,
      std::vector;

void pushArrayMax(priority_queue<int> &pq, int array[])
{
    for (int i = 0; i < 6; i++)
    {
        pq.push(array[i]); // inserting into the queue
    }
}
void showMaxHeap(priority_queue<int> &pq)
{
    while(!pq.empty()){
        cout<< pq.top() << " ";
        pq.pop();
    }
}

void pushArrayMin(priority_queue<int,vector<int>,greater<int>>& pq,int array[]){
    for (int i = 0; i < 6; i++)
    {
        pq.push(array[i]); // inserting into the queue
    }
}
void showMinHeap(priority_queue<int, vector<int>, greater<int>> &pq)
{
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main(){

    int array[6] = {2, 3, 5, 1, 5, 7};
    // Decalaring the priority queue(max heap by default)
    // note this will create a max heap that the element with highest priority is at the top but the highest priority here would be of max element
    priority_queue<int> pq;
    pushArrayMax(pq, array);
    showMaxHeap(pq);
    cout << endl;
    // Decalaring the priority queue (converted to min heap by greater<int>() function);
    //note this will create a min heap that the element with highest priority is at the top but the highest priority here would be of min element
    priority_queue<int, vector<int>, greater<int>>
        pq2(array, array + 6); // another way of copying the elements of vector using the base address iterator
    // pushArrayMin(pq2, array);
    showMinHeap(pq2);
    return 0;
}
```