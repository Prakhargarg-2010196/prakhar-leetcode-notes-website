# Template
## Description

Repetitive patterns and function much frequently used in the code that i don't want to write them again and again ( They are not patterns like sliding window for those I have assigned a [special folder](../../.) to that.)

The template might include functions like

## Array

- initialise elements in array
- printing of array

```cpp
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void initArray(vector<int> &);
void printArray(vector<int> &);
class ArrayManipulation
{

private:
    vector<int> arr;

public:
    ArrayManipulation()
    {
        arr.assign(1, 0);
    }
    void initArray()
    {
        int n;
        cout << "Enter number of elements in the array" << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }
    void initArray(vector<int> &arr)
    {
        for (auto &it : arr)
            cin >> it;
    }
    void printArray(vector<int> &arr)
    {
        for (auto &it : arr)
            cout << it << " ";
    }

    void print2DVector(vector<vector<string>> &result)
    {
        for (auto &it : result)
        {
            for (auto &it2 : it)
                cout << it2 << ",";
        }
    }
};

```