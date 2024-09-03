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