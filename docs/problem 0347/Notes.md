# Top K Frequent Elements
## Approaches
- Counting using brute force of two loops:  **(O(N^2),O(N))**
- Counting after sorting : **(O(NlogN),O(N))**
- Count using hashmap and then returning using priority queue : **(O(NlogK),O(N))** where K is the number of elements that are unique or to be sorted using priority queue

## Solution using Brute force of two loops
```cpp
class Solution {
public:
    static bool comp(const pair<int, int>& a, const pair<int, int>& b) {
        return b.second < a.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> seen;
        int n = nums.size();
        int count = 1;
        vector<pair<int, int>> countArray;
        for (int i = 0; i < n; i++) {
            count = 1;
            if (find(seen.begin(), seen.end(), nums[i]) == seen.end()) {
                for (int j = i + 1; j < n; j++) {
                    if (nums[i] == nums[j]) {
                        count++;
                        seen.push_back(nums[i]);
                        // The element is now marked as seen or visited.
                    }
                }
                countArray.push_back({nums[i], count});
            }
        }
        sort(countArray.begin(), countArray.end(), comp);

        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            result[i] = countArray[i].first;
        }
        return result;
    }
};
```

```cpp
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
```

## Solution using counting and sorting
```cpp
class Solution {
public:
    static bool comp(const pair<int, int>& a, const pair<int, int>& b) {
        return b.second < a.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();            // Size of the array
        sort(nums.begin(), nums.end()); // REQUIRED
        vector<pair<int, int>> countArray;
        int count = 1;
        for (int i = 0; i < n; i++) {
            if (i < n - 1) {
                if (nums[i] == nums[i + 1]) {
                    count++;
                } else {
                    countArray.push_back({nums[i], count});
                    count = 1;
                }
            } else {
                countArray.push_back({nums[i], count});
            }
        }

        for (auto& it : countArray) {
            cout << it.first << " " << it.second << endl;
        }

        sort(countArray.begin(), countArray.end(), comp);
        for (auto& it : countArray) {
            cout << it.first << " " << it.second << endl;
        }

        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            result[i] = countArray[i].first;
        }
        return result;
    }
};
```



## Use a heap data structure (using priority_queue)
```cpp
typedef pair<int, int> pi;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int>
            countMap; // for storing frequency of each element
        priority_queue<pi, vector<pi>, greater<pi>> sortedfreq;
        for (auto& it : nums) {
            countMap[it]++;
        }

        // Arranging elements in priority queue
        for (auto& it : countMap) {
            sortedfreq.push(
                {it.second,
                 it.first}); // Putting the element according to which we
                             // want to sort as the first element
        }
        //Check and pop the pairs which are not to be included as they are smaller counts
        while (sortedfreq.size() > k) 
            sortedfreq.pop();
        
        // push into result array
        while (!sortedfreq.empty()) {
            result.push_back(sortedfreq.top().second);
            sortedfreq.pop();
        }
        return result;
    }
};
```
