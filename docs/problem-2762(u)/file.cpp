// 2762. Continuous Subarrays
#include <bits/stdc++.h>
using namespace std;
 long long continuousSubarrays(vector<int>& nums) {
     int n = nums.size();
     long long count = 0;
     for (int i = 0; i < n; i++)
     {
         for (int j = i+1; j < n;j++){
             long long absolute_value = abs(nums[j - 1] - nums[j]);
             if (0 <= absolute_value && absolute_value <= 2)
             {
                 count++;
             }
            else
                continue;
         }
     }
     return count+n;
}
int main (){
     int n;
     cout << "Enter n" << endl;
     cin >> n;
     cout << "Enter elements" << endl;
     vector<int> nums(n);
     for(auto&it:nums){
         cin >> it;
     }
     cout << continuousSubarrays(nums);
     return 0;
}
