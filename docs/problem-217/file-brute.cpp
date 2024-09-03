#include <bits/stdc++.h>
typedef long long ll;
using std::cout,std::cin,std::vector;

bool containsDuplicate(vector<int>&nums,int size){
    bool status = false;
   
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size;j++)
        {
            if (nums[i] == nums[j])
            {
                status = true;
                break;
            }
        }
    }
    return status;
}
int main(){
    int n;
    cin >> n;
    if(n==0||n==1){
        cout << true;
    }
    else {
        vector<int> nums(n);
        for (auto &it : nums)
            cin >> it;
        cout << (bool)(containsDuplicate(nums, n));
    }
    
    return 0;
}