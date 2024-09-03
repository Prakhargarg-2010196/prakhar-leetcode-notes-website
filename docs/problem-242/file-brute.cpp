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