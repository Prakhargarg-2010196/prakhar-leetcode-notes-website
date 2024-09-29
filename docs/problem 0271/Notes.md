# Encode & Decode strings

In this problem the we need to encode the array of strings and decode the string recieved from the encoded function back to the array of strings.

> **Intuition: To attach the length of the each word and attach a delimeter like "#" next to the length to separate length and the original string (as the string itself can contain a number)** 

## Explanation:

For doing so in the encode function we utilize the `to_string()`  function to convert the size() of each word and attach it in front of the word with "#". This is done so that we can traverse this length amount while decoding the encoded string.

In Decode string function we need to find the length number which can be any length long but as we had put a delimiter after number i.e "#" we can make out the how much is the length by traversing it till "#" is found and using the substring(startingIndex,length) to calculate the length as well as to separate the strings out.

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;
class EncodeDecode
{
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs)
    {
        // write your code here
        string str = "";
        for (int i = 0; i < strs.size(); i++)
        {
            str += to_string(strs[i].size()) + "#" + strs[i];
        }
        return str;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str)
    {
        // write your code here
        vector<string> res;
        int length = 0;
        int i = 0;
        while (i < str.size())
        {
            int k = i; // for storing the position of "#"
            while (str[k] != '#')
            {
                k++;
            }
            cout << "K\t" << k << endl; // To debug the value of k
            length = stoi(str.substr(i, k - i));
            cout << "current length\t" << length << endl; // To debug the length of current string
            res.push_back(str.substr(k + 1, length));
            i = length + k + 1;
        }
        return res;
    }
};
int main()
{
    EncodeDecode E1;
    vector<string> str{"Hello", "World"};
    string str2 = E1.encode(str);
    str = E1.decode(str2);
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << "\t";
    }
}
```