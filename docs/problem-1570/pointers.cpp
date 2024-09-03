#include <bits/stdc++.h>
using namespace std;
class SparseVector
{
private:
    unordered_map<int,int> nZ;

public:
    // Your SparseVector object will be instantiated and called as such:
    // SparseVector v1(nums1);
    // SparseVector v2(nums2);
    // int ans = v1.dotProduct(v2);
    SparseVector(vector<int> &nums)
    {
        // do intialization here
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                continue;
            }

            nZ[i] = nums[i];
        }
    }
    void printMap()
    {
        for (auto &&[index,key] : nZ)
        {
            cout << index << " " << key << endl;
        }
    }
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector &vec)
    {
        // write your code here
        int result = 0;
        if (nZ.size() < vec.nZ.size())
        {
            return vec.dotProduct(*this); // refer to the current object;
        }
        // for (auto &it:nZ){
        //     if(vec.nZ.find(it.first)!=vec.nZ.end()){
        //         // find if the index of the element exists in the second sparse vector then 
        //         // add to result
        //         result += (it.second * vec.nZ[it.first]);
        //     }

        // }
        for(auto&[indexOfFirstSparseVector,valueOfFirstSparseVector]:nZ){
              if(vec.nZ.find(indexOfFirstSparseVector)!=vec.nZ.end()){
                  result += valueOfFirstSparseVector * vec.nZ[indexOfFirstSparseVector];
              }
            
        }
        return result;
    }
};

int main()
{
    int n1,n2;
    cin >> n1>>n2;
    vector<int> nums1(n1),nums2(n2);
    for (auto &it : nums1)
        cin >> it;
    SparseVector S1(nums1);
    // S1.printMap();
    for (auto &it : nums2)
        cin >> it;
    SparseVector S2(nums2);
    // S2.printMap();
    int result = S1.dotProduct(S2);
    cout << result;
    return 0;
}