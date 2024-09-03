// Illustration of usage of priority queue data structure in stl library 

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