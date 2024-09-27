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