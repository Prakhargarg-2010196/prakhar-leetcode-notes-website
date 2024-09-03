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