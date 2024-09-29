# 1876. Substrings of Size Three with Distinct Characters

## We can use three methods

1. Taking brute force approach to go thru each subarray and then take into count
2. Taking brute force and taking into account if three elements are inequal (brute force because can be applied on only this question not any variants)
3. Use Sliding window(fixed)


## Brute Force

```cpp
// 1876. Substrings of Size Three with Distinct Characters
#include <bits/stdc++.h>
using namespace std;
int main()
{   // Brute force
    int flag = 1;
    int totalSubStrings = 0;
    unordered_map<char, int> mp; // for storing the counts
    string str;
    cout << "enter string" << endl;
    cin >> str;
    int n = str.size();
    // cout << n;
    for (int i = 0; i <= n - 3; i++)
    {
        flag = 0;
        mp.clear();//clean the map for new iteration
        for (int j = i; j < i + 3; j++)
        {   //note: dont put the map loop for traversal for each iteration inside the loop as here the subarray
            // formation is taking place
            mp[str.at(j)]++;
        }
        // See the hash map for each iteration
        // for(auto it:mp){
        //     cout << it.first << " " << it.second<<endl;
        // }
        for (auto it : mp){
            if(it.second==1){
                flag = 0;
            }
            else{
                    flag = 1;
                    break;
            }
        }
        if(flag==0){
            totalSubStrings++;
        }
        // cout << endl;
    }
    cout << totalSubStrings;
    return 0;
}
```

## Brute force 2

```cpp
// 1876. Substrings of Size Three with Distinct Characters
#include <bits/stdc++.h>
using namespace std;

bool checkInEquality(int firstElement, int secondElement, int thirdElement){
    if(firstElement!=secondElement&&secondElement!=thirdElement&&firstElement!=thirdElement){
        return true;
    }
    return false;
}
int main()
{
    int totalSubStrings = 0;
    string str;
    cin >> str;
    int n = str.size();
    int k = 3;
    // we know if the three elements in comparision are equal then it means the they are getting repeatitve
    for (int i = 0; i <= n-k;i++){
        if(checkInEquality(str[i],str[i+1],str[i+2])==true){
            totalSubStrings++;
        }
    }

        cout << totalSubStrings;
    return 0;
}
```

## Optimized

```cpp
// 1876. Substrings of Size Three with Distinct Characters
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int totalSubStrings = 0;
    unordered_map<char, int> mp; // for storing the counts
    string str;
    cout << "enter string" << endl;
    cin >> str;
    int n = str.size();
    int k = 3;
    for (int i = 0; i < k; i++){
        mp[str[i]]++;
    }
    for (int j = k; j < n;j++){

    if (mp.size() == k){
        // if the map contain k elements then it is true that no elements would repeat
        totalSubStrings++;
    }

    mp[str[j - k]]--;

    if (mp[str[j - k]]==0){
    //if the frequency is zero then it will only create an illusion of existence
    // and thus have to be removed from map.
        cout << str[j - k] << endl;;
        mp.erase(str[j - k]);
    }

    mp[str[j]]++;
    }
    // for last window as the loop above runs check till only the last window
    if (mp.size() == k){
        totalSubStrings++;
    }
    cout << totalSubStrings;
    return 0;
}
```