#include <bits/stdc++.h>
using namespace std;
 vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int start=0;
        int end=n-1;
        int sum;
        while(start<end){
            sum=numbers[start]+numbers[end];// to keep track of sum with changing pointers
            if(target==sum)
                return {start+1,end+1};//as the array is one indexed
            else if(sum<target)
                start++;
            else end--; 
            }
        return {};
        
    }
int main()
{
        int n;
        cin >> n;
        vector<int> nums(n);
        for(auto&it:nums){
            cin >> it;
        }
        int target;
        cin >> target;
        vector<int> indexes;
        indexes = twoSum(nums, target);
        for (auto &it:indexes){
            cout << it<<" ";
        }
            return 0;
}
