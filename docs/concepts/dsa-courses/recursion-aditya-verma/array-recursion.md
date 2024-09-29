# Sort an Array using recursion
```cpp
#include <bits/stdc++.h>
using namespace std;
void sortArray(vector<int> &array);
void printArray(vector<int> &array);
void repositionElement(vector<int> &array,int elementToReposition);
int main()
{
    int n;
    cout << "enter the size of the array\n";
    cin >> n;
    vector<int> arr(n);
    cout << "enter the elements of array\n";
    for(auto&it:arr){
        cin >> it;
    }
   
    sortArray(arr);
    // for (auto &it : arr)
    // {
    //     cout<< it;
    // }
    printArray(arr);
    return 0;
}
void printArray(vector<int> &array){
    
    // Base Condition
    if(array.size()==0){
        return;
    }

    // Hypothesis
    // [1,2,3,4,5] => [1,2,3,4] [5]
    int lastElement = array[array.size() - 1];
    array.pop_back();
    printArray(array);

    // induction
    cout << lastElement<<" ";
}

void sortArray(vector<int>&array){
    // Base condition : as when their is single element the array is already sorted.
    if(array.size()==1){
        return;
    }
    
    // Hypothesis
    // as decision thinking doesn't works here as recursion is just dependent on choice -> decison -> small input
    // thats why we can then  use the reverse of it ie.  small input -> decison 
    int lastElement = array[array.size() - 1]; // taking out the last element to decrease the size of the array
    array.pop_back(); 
    sortArray(array);  // now running sort on decreased size array which will return us sorted smaller input size array.

    // Induction 
    // The last element we removed then should be repositioned correctly at correct position altho we can do
    // this thru iterative approach but doing it thru recursion only here
    repositionElement(array,lastElement);
}
void repositionElement(vector<int>& array,int elementToReposition){
    // Base Condition
    // either if the array is of size zero the element the element would be inserted directly
    // or if the element to be inserted is less than the last element
    if(array.size()==0 || array[array.size()-1]<=elementToReposition)
    {
        array.push_back(elementToReposition);
        return;
    }
    //  Hypothesis 
    //  First we would remove the last element and then pass down the remaining array to the function
    // which we have to reposition the element into 
    // we will reach a phase where the last element gets re-positioned correctly in the array 
    int lastElement = array[array.size() - 1];
    array.pop_back();
    repositionElement(array, elementToReposition);
    
    // Induction
    // now what is left is to replace the last element which we removed to be positioned correctly at last.
    array.push_back(lastElement);
}
```