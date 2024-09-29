# Valid Anagram

## Brute Force

```cpp
#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using std::cout,std::cin,std::vector,std::string;

bool isAnagram(string s,string t){
    vector<int> charCountArray(26, 0);
    int n = s.size();
    int m = t.size();
    if(n!=m){
        return false;
    }
    for (int i = 0; i < n; i++){
        int charIndex = s[i] - 'a';
        charCountArray[charIndex]++;
    }
    for (int j = 0; j < m; j++){
        int charIndex = t[j] - 'a';
        charCountArray[charIndex]--;
    }
    for (int k = 0; k < 26;k++){
        if(charCountArray[k]!=0)
            return false;
    }
    return true;
}
int main(){
    string s, t;
    cout << "string 1";
    cin >> s;
    cout << "string 2";
    cin >> t;
    cout << isAnagram(s,t);
    return 0;
}
```

## Optimized

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
typedef long long ll;
using std::cout, std::cin,std::vector,std::unordered_map;

bool containsDuplicate(vector<int> &nums, int size)
{
    unordered_map<int, int> mp;
    for(auto&it:nums)
        mp[it]++;
    for(auto&it:mp){
        if(it.second>=2){
            return true;
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    if (n == 0 || n == 1)
    {
        cout << true;
    }
    else
    {
        vector<int> nums(n);
        for (auto &it : nums)
            cin >> it;
        cout << containsDuplicate(nums, n);
    }

    return 0;
}
```

## References
[other's solution](https://leetcode.com/problems/valid-anagram/discuss/66519/2-C%2B%2B-Solutions-with-Explanations)
