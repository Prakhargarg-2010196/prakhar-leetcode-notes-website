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