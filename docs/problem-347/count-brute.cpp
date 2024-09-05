// Vector solution with alternative map solution too
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
void printVectorOfPairs(vector<pair<int, int>> &);
vector<pair<int, int>> countArrayUsingLoops(vector<int> &);
vector<pair<int, int>> countArrayUsingSorting(vector<int> &);
vector<pair<int, int>> countArrayUsingHashMap(vector<int> &);
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &it : nums)
        cin >> it;
    // vector<pair<int, int>> res = countArrayUsingLoops(nums);
    // vector<pair<int, int>> res = countArrayUsingSorting(nums);
    vector<pair<int, int>> res = countArrayUsingHashMap(nums);
    printVectorOfPairs(res);

    return 0;
}

vector<pair<int, int>> countArrayUsingLoops(vector<int> &nums)
{
    vector<int> seen;
    int n = nums.size();
    int count = 1;
    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++)
    {
        count = 1;
        if (find(seen.begin(), seen.end(), nums[i]) == seen.end())
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j])
                {
                    count++;
                    seen.push_back(nums[i]); // The element is now marked as seen or visited.
                }
            }
            res.push_back({nums[i], count});
        }

        //! This should be avoided as range based for loop iterates over the vector and making operations
        //! over it can cause iterators to become undefined returning ambiguous results. Instead use another vector for checking seen values.
        // for (auto &it : res)
        // {
        //     if (it.first != nums[i])
        //     {
        //         res.push_back({nums[i], count});
        //     }
        // }
    }
    return res;
}

vector<pair<int, int>> countArrayUsingSorting(vector<int> &nums)
{
    int n = nums.size();            // Size of the array
    sort(nums.begin(), nums.end()); // REQUIRED
    vector<pair<int, int>> countArray;
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
        {
            if (nums[i] == nums[i + 1])
            {
                count++;
            }
            else
            {
                countArray.push_back({nums[i], count});
                count = 1;
            }
        }
        else
        {
            countArray.push_back({nums[i], count});
        }
    }

    for (auto &it : countArray)
    {
        cout << it.first << " " << it.second << endl;
    }
    return countArray;
}

vector<pair<int, int>> countArrayUsingHashMap(vector<int> &nums)
{
    unordered_map<int, int> countMap;
    for (auto &it : nums)
        countMap[it]++; // Store the counts and increase if the value is found again i.e according to its frequency
    vector<pair<int, int>> res;
    for (auto &it : countMap)
        res.push_back(it);
    return res;
}

void printVectorOfPairs(vector<pair<int, int>> &nums)
{
    for (auto &it : nums)
    {
        cout << it.first << " " << it.second << endl;
    }
}