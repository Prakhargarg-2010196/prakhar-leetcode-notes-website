#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string initialString)
{
    int n = initialString.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        // skip non-alphanumeric char whenever they occur and no matter how many they occur
        // keeping the i<j condition because we want to check if whole string is of special characters or spaces
        while (i < j && !isalnum(initialString[i]))
            i++;
        while (i < j && !isalnum(initialString[j]))
            j--;

        // if then the lowered form of char is not equivalent from start and end then the string is not palindrome

        if (tolower(initialString[i]) != tolower(initialString[j]))
            return false;
        else
        {
            i++;
            j--;
        }
    }
    return true;
}
int main()
{
    string initalString;
    cin >> initalString;
    cout<<isPalindrome(initalString)<<endl;
    return 0;
}