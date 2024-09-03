// Vector solution with alternative map solution too
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>
using std::cin, std::cout, std::endl, std::unordered_map,std::multimap,std::vector,std::pair,std::greater;
// vector solution
// static bool sortPairs(pair<int,int>a,pair<int,int>b){
//     return a.first > b.first;
// }
// vector<int> topKFrequent(vector<int> &nums, int k)
// {
//     vector<int> result;
//     unordered_map<int, int> map;
//     for(auto it:nums){
//         map[it]++;
//     }
//     vector<pair<int,int>> sortedMap(map.size());
//     for(auto&it:map){
//         sortedMap.push_back({it.second, it.first});
//     }
//     sort(sortedMap.begin(), sortedMap.end(), sortPairs);
//     for (int i = 0; i < k;i++)
//     {
//         result.push_back(sortedMap[i].second);
//     }
//     return result;
// }
vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<int> res;
    int count = 0;
    multimap<int,int,greater<int>> result; // to store the values-key order from another map (i.e to reverse the order of pair of another map)
    unordered_map<int, int> map;// to store the number of occurences  
    for (auto& it : nums)
    {
        map[it]++;
    }
    for(auto&it:map){
        result.insert({it.second, it.first});
    }
    for(auto&it:result){
        
        if(count<k)
        {
            res.push_back(it.second);
            count++;
        }
        else
        break;
    }
    
    return res;
}
void printMap(unordered_map<int,int>mp){
    for(auto&[key,value]:mp){
        cout << key << ":" << value;
    }
}
void printVector(vector<int> &res)
{
    for (auto &it : res)
    {
        cout << it << ",";
    }
}
int main(){
    int n,target;
    cin >> n>>target ;
    vector<int> nums(n);
    for (auto &it : nums)
        cin >> it;
    vector<int> res = topKFrequent(nums,target);
    printVector(res);

    return 0;
}
