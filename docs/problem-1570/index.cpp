#include <bits/stdc++.h>
using namespace std;
class SparseVector
{
private:
    vector<int> nonZeroArray;

public:
    // Your SparseVector object will be instantiated and called as such:
    // SparseVector v1(nums1);
    // SparseVector v2(nums2);
    // int ans = v1.dotProduct(v2);
    SparseVector(vector<int> &nums)
    {
        // do intialisation here
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                continue;
            }

            nonZeroArray[i] = nums[i];
        }
    }
    void printVector(){
        for(auto&it:nonZeroArray){
            cout << it << " ";
        }
    }
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector &vec)
    {
        // write your code here
        int result = 0;
        if (nonZeroArray.size() < vec.nonZeroArray.size())
        {
            return vec.dotProduct(*this); // refer to the current object;
        }
        for (int i = 0; i < vec.nonZeroArray.size(); i++)
            if (vec.nonZeroArray[i] && nonZeroArray[i])
                result += (vec.nonZeroArray[i] * nonZeroArray[i]);
        return result;
    }
};

int main(){
    int  n1,n2;
    cin >> n1 >> n2;
    vector<int> nums1(n1),nums2(n2);
    for (auto &it : nums1)
        cin >> it;
    SparseVector S1(nums1);
    S1.printVector();
    for (auto &it : nums2)
        cin >>it;
    SparseVector S2(nums2);
    S2.printVector();
    // int result = S1->dotProduct(*S2);
    // cout << result;
    return 0;
}