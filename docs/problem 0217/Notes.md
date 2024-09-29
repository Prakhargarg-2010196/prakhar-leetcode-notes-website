# Contains Duplicate

## Brute Force
```cpp
#include <bits/stdc++.h>
typedef long long ll;
using std::cout,std::cin,std::vector;

bool containsDuplicate(vector<int>&nums,int size){
    bool status = false;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size;j++)
        {
            if (nums[i] == nums[j])
            {
                status = true;
                break;
            }
        }
    }
    return status;
}
int main(){
    int n;
    cin >> n;
    if(n==0||n==1){
        cout << true;
    }
    else {
        vector<int> nums(n);
        for (auto &it : nums)
            cin >> it;
        cout << (bool)(containsDuplicate(nums, n));
    }
    return 0;
}
```

## Optimized

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
typedef long long ll;
using std::cout, std::cin,std::vector,std::unordered_map;

bool containsDuplicate(vector<int> &nums, int size)
{
    unordered_map<int, int> mp;
    for(auto&it:nums)
        mp[it]++;
    for(auto&it:mp){
        if(it.second>=2){
            return true;
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    if (n == 0 || n == 1)
    {
        cout << true;
    }
    else
    {
        vector<int> nums(n);
        for (auto &it : nums)
            cin >> it;
        cout << containsDuplicate(nums, n);
    }

    return 0;
}
```

[other's solution](https://leetcode.com/problems/contains-duplicate/discuss/2728722/All-Possible-Easy-Solution-with-single-line-code-oror-c%2B%2B)
