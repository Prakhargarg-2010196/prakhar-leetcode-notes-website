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
                    length = 1;// To set the length to 1 if the nums are not consecutive to reset the length while calculating new 
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
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return 1;
        }
        unordered_map<int,bool>mp;// To store the elements'check that are needed to be traversed
        for(auto&it:nums){
            mp[it]=true;
        }
        //Now turn all those elements to false which don't require to be checked 
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i]-1)>0){
                mp[nums[i]]=false; // this is to make sure the elements whose previous elements already exist don't get re-traversed.
            }
        }
        int maxLength=0;
        //Now calculate the maxLength
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==true){
                int length=0;
                while(mp.find(nums[i]+length)!=mp.end()){
                    length++;
                }
                maxLength=max(maxLength,length);
            }
        }
        return maxLength;
    }
};
```
[Question](https://leetcode.com/problems/longest-consecutive-sequence/)

[other's solution](https://leetcode.com/problems/longest-consecutive-sequence/discuss/3171985/Best-C++-4-solution-oror-Hash-Table-oror-Sorting-oror-Brute-Force-greater-Optimize-oror-One-Stop-Solution.)

[What is a Sequence ?](https://en.wikipedia.org/wiki/Sequence)
[What is a sub-sequence](https://www.geeksforgeeks.org/array-subarray-subsequence-and-subset/)