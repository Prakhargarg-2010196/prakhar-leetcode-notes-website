# Concatenation of array

## Brute Force

```cpp
// https://leetcode.com/problems/concatenation-of-array/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(2 * n);
        // first pass
        for (int i = 0; i < n; i++)
        {
            result[i] = nums[i];
        }
        // second pass
        for (int i = 0; i < n; i++)
        {
            result[i + n] = nums[i];
        }

        /*The above can be done as follows too instead of two passes 🫠
            for(int i=0;i<n;i++){
                result[i]=result[i+n]=nums[i];
            }
        */
        return result;
    }
    void PrintArray(vector<int>&nums){
        for(auto&it:nums){
            cout << it << " ";
        }
    }
};

int main()
{
    int n;
    cout << "Enter the size of the array\n";
    cin >> n;
    vector<int> nums(n);
    for(auto&it:nums)
        cin >> it;
    vector<int> result;
    Solution s1;
    result = s1.getConcatenation(nums);
    s1.PrintArray(result);
    return 0;
}
```
## References
- [Alt approaches](https://leetcode.com/problems/concatenation-of-array/discuss/3073190/3-ways-to-solve-this-problem-in-C%2B%2B)

- nums.insert(pos,from,to); pos: insert before that element iterator, from : iterator from which copy has to be done , to: iterator till which copy has to be done;

- push_back on the same array.
