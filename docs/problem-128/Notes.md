# 128. Longest Consecutive Sequence

##  Brute Force

### Brute force 1 (using only array)  : T: O(n2) , S: O(1)
```cpp
#include <iostream>
#include <vector>
#include<unordered_map>
using std::cout, std::cin, std::vector, std::unordered_map, std::max, std::endl;
bool isConsecutive(vector<int> &nums,int current){
    int n = nums.size();
    for (int i = 0; i < n;i++){
        int consecutiveElement = nums[i];
        if(consecutiveElement==current)
            return true;
        
    }
    return false;
}
int longestConsecutive(vector<int> &nums)
{
    /* A brute force approach is the traversal of the array and first find the
    elements whose previous element don't exist and then finding the count of
    consecutive numbers.
    */
    int largestConsecutiveSequence = 0;
    for (int i = 0; i < nums.size();i++){
        int prev = nums[i];
        int k = 0;
        int currentCount = 0;
        while(isConsecutive(nums,prev+k)==true){
            currentCount++;
            k++;
        }
        largestConsecutiveSequence = max(largestConsecutiveSequence, currentCount);
    }
    
    return largestConsecutiveSequence;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);// stores unsorted array 
    for (auto &it : nums)
        cin >> it;
    int res = longestConsecutive(nums);
    cout << res << endl;
    return 0;
}
```


### Brute Force 2 (using sorting and array) : T:O(nlogn) , S:O(1)
```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return 1;
        }

        sort(nums.begin(), nums.end());
        int maxLength = 0;
        int length = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] != nums[i]) {//check only if the previous element is not equal ot current 
                if (nums[i - 1] + 1 == nums[i]) {
                    length++;
                } else
                    length = 1;// To set the length to 1 if the nums are not consecutive
                maxLength = max(length, maxLength);// To calculate the max each time
            }
        }
        return max(maxLength,length);// To calculate the max element when the elements are repeated
    }
};
```

## Optimized T:O(n) , S: O(n)

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLength = 0;
        unordered_map<int, bool> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = true;
        }
        // Filtering the non traversable elements
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i] - 1) != mp.end()) {
                // Because if once previous exists there is no need to travere
                // the next one each time
                mp[nums[i]] = false;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            int current = nums[i];
            int j = 0;
            if (mp[nums[i]] == true) {
                // To find the next element to the current element add the index where you want to reach for that you need a separate index
                while (mp.find(current + j) != mp.end()) {
                    count++;
                    j++;
                }
                maxLength = max(count, maxLength);
            }
        }
        return maxLength;
    }
};
```
[Question](https://leetcode.com/problems/longest-consecutive-sequence/)

[other's solution](https://leetcode.com/problems/longest-consecutive-sequence/discuss/3171985/Best-C++-4-solution-oror-Hash-Table-oror-Sorting-oror-Brute-Force-greater-Optimize-oror-One-Stop-Solution.)
