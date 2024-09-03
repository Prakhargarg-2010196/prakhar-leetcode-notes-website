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