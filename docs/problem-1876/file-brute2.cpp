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


