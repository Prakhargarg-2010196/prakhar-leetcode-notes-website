# Valid Parentheses

# Brute force

```cpp
class Solution {
public:
    bool isValid(string str) {
        int n = str.size();
        if (n == 0)
            return true;
        if (n == 1 || n % 2 != 0)
            return false;

        bool isPairFound = true;
        while (isPairFound) {
            isPairFound = false;
            for (int i = 0; i < n; i++) {
                if (str[i] == '(' && str[i + 1] == ')' ||
                    str[i] == '[' && str[i + 1] == ']' ||
                    str[i] == '{' && str[i + 1] == '}')
                    {
                        str.erase(i,2);
                        isPairFound=true;
                        break;
                    }
            }
        }
        return str.empty();
    }
};
```


## Optimized

```cpp
class Solution {
public:
    bool isValid(string str) {
        int n = str.size();
        if (n == 0)
            return true;
        if (n == 1 || n % 2 != 0)
            return false;

        stack<char>
            st; // To store the open parenthesis,common brackets , and braces
        for (auto& it : str) {
            if (it == '(' || it == '{' || it == '[')
                st.push(it);

            else {
                if (!st.empty() && (it == ')' && st.top() == '(' ||
                                    it == '}' && st.top() == '{' ||
                                    it == ']' && st.top() == '['))
                    st.pop();
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
```