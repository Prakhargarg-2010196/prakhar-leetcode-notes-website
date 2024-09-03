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