#include <iostream>
#include <vector>
#include <unordered_map>
using std::cout, std::cin, std::vector, std::unordered_map, std::max, std::endl;

int longestConsecutive(vector<int> &nums)
{
    /* A brute force approach is the traversal of the array and first find the
    elements whose previous element don't exist and then finding the count of
    consecutive numbers.
    */
    int largestConsecutiveSequence = 0;
    unordered_map<int, bool> visited;
    //         Set all the values to false
    for (auto &it : nums)
        visited[it] = false;
    //         Set all the values with no previous value to true
    for (auto &it : nums)
    {
        if (visited.find(it - 1) == visited.end())
        {
            visited[it] = true;
        }
    }

    // [100: true,
    //  4  : false,
    //  200 : true,
    //  1   : true,
    //  3   : false,
    //  2    : false,
    // ]
    for (auto &it : nums)
    {
        if (visited[it] == true)
        {
            int k = 0, currentCount = 0, prev = it;
            while (visited.find(prev + k) != visited.end())
            {
                // check for consecutive by adding the 1 consecutively
                currentCount++; // increase the count if element consecutives are found
                k++;
            }
            largestConsecutiveSequence = max(currentCount, largestConsecutiveSequence);
        }
    }

    return largestConsecutiveSequence;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n); // stores unsorted array
    for (auto &it : nums)
        cin >> it;
    int res = longestConsecutive(nums);
    cout << res << endl;
    return 0;
}