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