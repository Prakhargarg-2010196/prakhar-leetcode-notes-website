
# N parking slots

This is a question given in theory on hired in tech website just a puzzle and asked in few companies so try it if possible

```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    std::cout << "Enter the number of elements" << std::endl;
    cin >> n;
    int arr[n+1];
    std::cout << "Enter the  elements" << std::endl;
    for (int i = 0; i < n+1;i++){
        std::cin >> arr[i];
    }
    // output calculations
    if(arr[0]!=-1){
        for (int i = 0; i < n+1; i++){
            if(arr[i]==-1){
                swap(arr[0], arr[i]);
            }
        }
    }
    for (int i = 1; i < n+1;i++){
        while(arr[i+1]<arr[i]){
            swap(arr[i], arr[i + 1]);
        }
    }
    for (int i = 0; i < n+1; i++) {
        cout << arr[i] << ' ';
    }
        return 0;
}
```
Not giving right output up-solve it
[hint](https://www.careercup.com/question?id=5979500173066240)