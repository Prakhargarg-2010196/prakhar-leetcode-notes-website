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


