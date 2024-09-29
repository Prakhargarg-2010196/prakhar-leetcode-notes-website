# Sliding Window

## Concept


## Fixed Size Window
### Code

```cpp
// Using Subarray sum to implement two methods to write fixed sliding window
#include<bits/stdc++.h>
using namespace std;
// Follow this approach while solving tho!!
// In this method we manipulate the window using two pointers and we do so in a single loop
// here building of first window takes place together with the checking
int usePointersDirectly(vector<int> arr,int k){
    // Here k is the size of the subarray given in the question
    // The window size can be calculated using the formula right-left+1
    // for example , for [2,3,4,1,9]  k =3  the left=0 , right=2 for first window then its size is right - left + 1 = 2-0+1=3 always
    int left = 0, right = 0;// two pointers used to manipulate the sliding window
    int sum = 0, maxSum = INT_MIN;
    int n = arr.size();
    while (right < n){
        sum += arr[right];
        // building of sliding window
        if ((right - left + 1) < k)
        {

            right++;
        }
        // Checking of condtions
        else if((right-left+1)==k){
            maxSum = max(maxSum, sum);
            //decrease the sum from the left
            sum -= arr[left];
            // move both the pointers forward to slide the window
            left++;
            right++;
        }
    }
    return maxSum;
}
// Second method : In this method the building of sliding window takes place in another loop and then checking is done in another loop
int usePointersIndirectly(vector<int>arr,int k){
    int sum = 0, maxSum = INT_MIN;
    int n = arr.size();
    // building of sliding window
    for (int left=0; left < k;left++){
        sum += arr[left];
    }
    // checking of condtions
    for (int right = k; right < n;right++){
        // as the window is already of good size
        maxSum = max(maxSum, sum);
        // subtract the left pointer sum and add the new right pointer sum
        sum -= arr[right - k] + arr[right];
    }
    return maxSum;
}
int main(){
    int n;
    cout << " n";
    cin >> n;
    int k;
    cout << "k";
    cin >> k;
    vector<int> arr(n);
    cout << "enter elements of array" << endl;
    for (auto &it : arr){
        cin >> it;
    }
    cout << "Using method one" << " " << usePointersDirectly(arr, k) <<" "<<"Using method 2 " << usePointersIndirectly(arr, k);
}
```