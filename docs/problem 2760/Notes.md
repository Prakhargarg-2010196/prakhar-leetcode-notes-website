# Longest Even Odd Subarray With Threshold

This is the problem in which I went from brute force to optimised in two days using the algorithm design canvas
I found [here](https://www.hiredintech.com/classrooms/algorithm-design/lesson/78).

## Brute Force

```cpp
// 2760. Longest Even Odd Subarray With Threshold
#include <bits/stdc++.h>
using namespace std;
int longestAlternatingSubarray(vector<int> &nums, int T)
{
    int largestSubarray = 0;
    int n = nums.size();
    // For dealing with single element edge case
    if (nums.size() == 1)
    {
        if (nums[0] % 2 == 0 && nums[0] <= T)
            return 1;
        else
            return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] % 2 == 0 && nums[i] <= T)
        {
            // for dealing with the last element
            if (nums[i] == nums[n - 1])
            {
                largestSubarray = max(largestSubarray, 1);
            }
            for (int j = i + 1; j < n; j++)
            {
                // when the the next element is within threshold T and
                // is of alternate parity then count it
                // and continue to the next iteration
                if (nums[j] <= T && nums[j] % 2 != nums[j - 1] % 2)
                {
                    largestSubarray = max(largestSubarray, j - i + 1);
                    continue;
                }
                else
                {
                    // when the next element is not within threshold T or is not of alternate parity
                    // the window size becomes 1 and then we store it by comparing if it is the maximum
                    // or not
                    largestSubarray = max(largestSubarray, 1);
                    break;
                }
            }
        }
    }
    return largestSubarray;
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
        for (auto &it : arr)
        {
            cin >> it;
        }
        cout << longestAlternatingSubarray(arr, k);
        return 0;
}
```


## Optimized

```cpp
// 2760. Longest Even Odd Subarray With Threshold
#include <bits/stdc++.h>
using namespace std;
int longestAlternatingSubarray(vector<int> &nums, int T)
{
    int largestSubarray = 0;
    int n = nums.size();
    // two pointers indicating left and right of the window respectively
    int i = 0, j = 0;
    while (j < n)
    {
        // Step 1
        /*
        Check if the first number in
        the subarray is even or not
        Also it should lie in the threshold T
        */
        if (nums[i] % 2 == 0 && nums[i] <= T)
        {
            // Edge Cases :
            /*
            When both i and j are equal
            then the window size is one
            move the window to the right
            to increase its size (j++ or right++)
            */
            if (i == j)
            {
                largestSubarray = max(largestSubarray, 1);
                j++;
            }
            /*
            If the element is the last one
            recalculate the result without increasing
            the size of the window
            */
            else if (i == n - 1)
            {
                largestSubarray = max(largestSubarray, 1);
            }

            // Step 2
            /*
            Now if the next number is of alternate parity (even/odd)
            then re-calculate the result and move the window ahead
            to increase its size(j++ or right++) otherwise decrease the size
            of the window (i++ or left++)
            */
            else if (nums[j] <= T && nums[j] % 2 != nums[j - 1] % 2)
            {
                largestSubarray = max(largestSubarray, j - i + 1);
                j++;
            }
            else
            {
                i++;
            }
        }
        // Step 3:
        /*
        If the first number is odd there is no way
        that the subarray is accounted but if the indexes are same (i==j)
        then we would have to move the window(of size = 1 )
        ahead by moving both right(j) and left(i) else only left(i) has to                 decrease size of window .
        */
        else
        {
            if (i == j)
            {
                i++;
                j++;
            }
            else
                i++;
        }
    }
    return largestSubarray;
}
int main()
{
    int n;
    cout << " n";
    cin >> n;
    int k;
    cout << "k";
    cin >> k;
    vector<int> arr(n);
    cout << "enter elements of array" << endl;
    for (auto &it : arr)
    {
        cin >> it;
    }
    cout << longestAlternatingSubarray(arr, k);
    return 0;
}
```