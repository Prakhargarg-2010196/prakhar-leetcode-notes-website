# Two Sum II - Input Array Is Sorted

## Optimized

```cpp
#include <bits/stdc++.h>
using namespace std;
 vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int start=0;
        int end=n-1;
        int sum;
        while(start<end){
            sum=numbers[start]+numbers[end];// to keep track of sum with changing pointers
            if(target==sum)
                return {start+1,end+1};//as the array is one indexed
            else if(sum<target)
                start++;
            else end--; 
            }
        return {};

    }
int main()
{
        int n;
        cin >> n;
        vector<int> nums(n);
        for(auto&it:nums){
            cin >> it;
        }
        int target;
        cin >> target;
        vector<int> indexes;
        indexes = twoSum(nums, target);
        for (auto &it:indexes){
            cout << it<<" ";
        }
            return 0;
}
```

## References

- [Question](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/)
This solution is an extension to the two sum problem and hence the [two sum](../problem-1/) solutions can be applied here too.As here the array is sorted hence binary search or the other approaches in like two pointers make sense.

- [Brute force](../problem-1/file-brute.cpp) and  [hashmap approach](../problem-1/file-optimised.cpp) in two sum can be applied here too.

[All approaches](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/discuss/2128516/4-Approaches%3A-Brute-Force-HashMap-Binary-Search-Two-Pointers)