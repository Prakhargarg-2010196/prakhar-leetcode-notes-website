#  Two Sum

## Brute force
```cpp
#include <iostream>
#include <vector>
using std::cout,std::cin,std::vector;

vector<int> twoSum(vector<int> &nums, int target)
{
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i + 1; j < size; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {};
}
void printVector(vector<int>&res){
    for(auto&it:res){
        cout << it<<",";
    }
}
int main(){
    int target,n;
    cin >> n >> target;
    vector<int> nums(n);
    for (auto &it : nums)
        cin >> it;
    vector<int> res = twoSum(nums, target);
    printVector(res);

    return 0;
}
```

## Optimized Two passes
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using std::cout, std::cin, std::vector, std::unordered_map;
//  Two passes approach 
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        mp[nums[i]] = i;
    }
    for (int i = 0; i < size; i++)
    {   // taking array for taking the first element as the hashmap changes the value of the repeated values
        int first_element=nums[i];
        int second_element = target - first_element;
        if (mp.find(second_element)!=mp.end()&&mp[second_element]!=i)
        {
            return {i, mp[second_element]};
        }
    }

    return {};
}
void printVector(vector<int> &res)
{
    for (auto &it : res)
    {
        cout << it << ",";
    }
}
int main()
{
    int target, n;
    cin >> n >> target;
    vector<int> nums(n);
    for (auto &it : nums)
        cin >> it;
    vector<int> res = twoSum(nums, target);
    printVector(res);

    return 0;
}
```

## Optimized One pass (not written here ) (todo)

[Other's solution](https://leetcode.com/problems/two-sum/discuss/3619262/3-Method's-oror-C%2B%2B-oror-JAVA-oror-PYTHON-oror-Beginner-Friendly)
