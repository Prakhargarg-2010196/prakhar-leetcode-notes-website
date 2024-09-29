# Sort a Stack using recursion

```cpp
#include <bits/stdc++.h>
    using namespace std;
void sortStack(stack<int> &st);
void reverseStack(stack<int> &st);

void findMiddle(stack<int> &st, int k);
void deleteMiddle(stack<int> &st, int k);
// void insertStack(stack<int> &st);
void printStack(stack<int> &st);
void repositionElement(stack<int> &st, int elementToReposition);
void repositionReverseElement(stack<int> &st, int elementToReposition);

int main()
{
  int n, i = 0;
  stack<int> st;
  cout << "enter the number of elements you want to push into stack\n";
  cin >> n;
  cout << "enter the elements into stack\n";
  while (i < n)
  {
    int stackElement;
    cin >> stackElement;
    st.push(stackElement);
    i++;
  }
  int k = st.size() / 2 + 1;
  // findMiddle(st, k);
  // deleteMiddle(st, k);
  reverseStack(st);
  // sortStack(st);
  printStack(st);
  return 0;
}
void reverseStack(stack<int> &st)
{
  if (st.size() == 1)
  {
    return;
  }
  int lastElement = st.top();
  st.pop();
  reverseStack(st);
  repositionReverseElement(st, lastElement);
}
void repositionReverseElement(stack<int> &st, int elementToReposition)
{
  if (st.size() == 0)
  {
    st.push(elementToReposition);
    return;
  }
  int lastElement = st.top();
  st.pop();
  repositionReverseElement(st, elementToReposition);
  st.push(lastElement);
}
void printStack(stack<int> &st)
{
  // Base Condition
  if (st.size() == 0)
  {
    return;
  }

  // Hypothesis
  /* [
       2
       0
       5
       1
     ]

   Remove one element then again call sort to sort stack with one less element(assume/hypothesis)
     [
       5
       2
       1
       0
     ]

     */
  int lastElement = st.top();
  st.pop();
  printStack(st);

  // induction
  cout << lastElement << " ";
}
void findMiddle(stack<int> &st, int k)
{
  if (k == 1)
  {
    // st.pop();
    cout << st.top() << endl;
    return;
  }
  // will bring me the middle element from the smaller stack
  int last_element = st.top();
  st.pop();
  findMiddle(st, k - 1);
  st.push(last_element);
}

void deleteMiddle(stack<int> &st, int k)
{
  if (k == 1)
  { // when k=1
    st.pop();
    return;
  }
  // will bring me the middle element from the smaller stack
  int last_element = st.top();
  st.pop();
  findMiddle(st, k - 1);
  st.push(last_element);
}

void sortStack(stack<int> &st)
{
  // Base condition : as when their is single element the array is already sorted.
  if (st.size() == 1)
  {
    return;
  }

  // Hypothesis
  // as decision thinking doesn't works here as recursion is just dependent on choice -> decison -> small input
  // thats why we can then  use the reverse of it ie.  small input -> decison
  // Hypothesis
  /* [
       2
       0
       5
       1
     ]

   Remove one element then again call sort to sort stack with one less element(assume/hypothesis)
     [
       5
       2
       1
       0
     ]

     */
  int lastElement = st.top(); // taking out the last element to decrease the size of the stack
  st.pop();
  sortStack(st); // now running sort on decreased size stack which will return us sorted smaller input size stack.

  // Induction
  // The last element we removed then should be repositioned correctly at correct position altho we can do
  // this thru iterative approach but doing it thru recursion only here
  repositionElement(st, lastElement);
}
void repositionElement(stack<int> &st, int elementToReposition)
{
  // Base Condition
  // either if the stack is of size zero the element the element would be inserted directly
  // or if the element to be inserted is less than the last element
  if (st.size() == 0 || st.top() <= elementToReposition)
  {
    st.push(elementToReposition);
    return;
  }
  //  Hypothesis
  //  First we would remove the last element and then pass down the remaining array to the function
  // which we have to reposition the element into
  // we will reach a phase where the last element gets re-positioned correctly in the array
  int lastElement = st.top();
  st.pop();
  repositionElement(st, elementToReposition);

  // Induction
  // now what is left is to replace the last element which we removed to be positioned correctly at last.
  st.push(lastElement);
}
// Extra Learnings
//  The last element in the stack is stored at the top of the stack which can be accessed through stack.top() function
```