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