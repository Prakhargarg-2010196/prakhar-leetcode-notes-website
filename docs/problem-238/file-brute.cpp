#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using std::cin, std::cout, std::endl, std::unordered_map, std::multimap, std::vector, std::pair, std::greater;
vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> res;
    int product = 1;
    for (int i = 0; i < nums.size();i++){
        product = 1;
        for (int j = 0; j < nums.size();j++){
            if(i==j)
                continue;
            else
                product *= nums[j];
        }
        res.push_back(product);
    }
    return res;
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
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &it : nums)
        cin >> it;
    vector<int> res = productExceptSelf(nums);
    printVector(res);

    return 0;
}
