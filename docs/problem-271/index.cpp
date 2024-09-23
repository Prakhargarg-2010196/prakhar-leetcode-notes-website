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