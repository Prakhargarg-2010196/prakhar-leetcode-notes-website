# Valid Palindrome

## Brute force (Not complete)

```cpp
#include <bits/stdc++.h>
using namespace std;
string stripSpaces(string initialString);
string toLowerCase(string initialString);
bool reverseCheck(string initialString);
bool isPalindrome(string initialString);
int main()
{
    return 0;
}
bool isPalindrome(string initalString){
    string finalString;
    finalString=stripSpaces(initalString);
    cout << finalString;
    // finalString = toLowerCase(stripSpaces(initalString));
    return reverseCheck(finalString);
}
string stripSpaces(string initialString){
    // https://thispointer.com/how-to-trim-a-string-in-c/
    string finalString;
    const string whiteSpaces = " \t\n\r\f\v";

    size_t first_non_space = initialString.find_first_not_of(whiteSpaces);// returns  first not whitespace from beginning
    size_t last_non_space = initialString.find_last_not_of(whiteSpaces);  // returns  last non whitespace from end
    initialString.erase(0, first_non_space);// erase the spaces from the beginning
    initialString.erase(last_non_space+1);// erases the ending spaces from the end
    finalString = initialString;
   
    return finalString;
}
string toLowerCase(string initialString){
    for(auto&it:initialString){
        if(isdigit(it)){
            continue;
        }
        else {

        }
    }
}
```

## Optimized

```cpp
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
```

## References

```cpp
    cout << sizeof(size_t)<<endl; // https://stackoverflow.com/questions/2550774/what-is-size-t-in-c
    cout << sizeof(SIZE_MAX)<<endl;// max size
```

[remove certain characters from string](https://stackoverflow.com/questions/5891610/how-to-remove-certain-characters-from-a-string-in-c)
[erase-remove idiom](https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom)
[remove stl](https://cplusplus.com/reference/algorithm/remove/?kw=remove+)
[erase](https://cplusplus.com/reference/string/string/erase/)