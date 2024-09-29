# Product of Array Except Self

## Brute Force
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using std::cin, std::cout, std::endl, std::unordered_map, std::multimap, std::vector, std::pair, std::greater;
vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> res;
    int product = 1;
    for (int i = 0; i < nums.size();i++){
        product = 1;
        for (int j = 0; j < nums.size();j++){
            if(i==j)
                continue;
            else
                product *= nums[j];
        }
        res.push_back(product);
    }
    return res;
}
void printVector(vector<int> &res)
{
    for (auto &it : res)
    {
        cout << it << ",";
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &it : nums)
        cin >> it;
    vector<int> res = productExceptSelf(nums);
    printVector(res);

    return 0;
}

```



## Optimized

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using std::cin, std::cout, std::endl, std::unordered_map, std::multimap, std::vector, std::pair, std::greater;
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n);
    vector<int> prefixProduct(n);
    vector<int> suffixProduct(n);
    prefixProduct[0] = 1;
    suffixProduct[n - 1] = 1;
    for (int i = 1; i < n;i++){
        prefixProduct[i] = prefixProduct[i - 1] * nums[i-1];
    }
    for (int j = n - 2; j >= 0;j--){
        suffixProduct[j] = suffixProduct[j +1] * nums[j+1];
    }
    for (int k = 0; k < n;k++){
        res[k]=prefixProduct[k] * suffixProduct[k];
    }
        return res;
}
void printVector(vector<int> &res)
{
    for (auto &it : res)
    {
        cout << it << ",";
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &it : nums)
        cin >> it;
    vector<int> res = productExceptSelf(nums);
    printVector(res);

    return 0;
}
```

## References

- [other's](https://leetcode.com/problems/product-of-array-except-self/discuss/1342916/3-Minute-Read-Mimicking-an-Interview)