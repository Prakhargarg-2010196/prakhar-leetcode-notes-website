#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
#include<algorithm>
using std::cout,std::cin,std::vector,std::string,std::unordered_map;

//     The sorted string solution
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> result;
    for (auto &it : strs)
    {
        string currentSortedString = it;
        sort(currentSortedString.begin(), currentSortedString.end());
        mp[currentSortedString].push_back(it); // checking the sorted strings and then pushing the original string
    }
    for (auto &it : mp)
    {
        result.push_back(it.second);
    }
    return result;
}
void print2DVector(vector<vector<string>>&result){
    for(auto&it:result){
        for(auto&it2:it)
        cout << it2<<",";
    }
}
int main(){
    int n;
    cin >> n;
    vector<string> strings(n);
    for (auto &it : strings)
        cin >> it;
    vector<vector<string>> res = groupAnagrams(strings);
    print2DVector(res);

    return 0;
}

// T(n): O(n* klogk) where k is the length of the maximum string
// S(n): O(n) : because of hashmap