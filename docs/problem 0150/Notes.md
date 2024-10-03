# Evaluate Reverse Polish Notation

## Brute force
T:O(n2), S:O(1)

```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        bool check = true;
        int n = tokens.size();
        while (check) {
            check = false;
            for (int i = 0; i < n; i++) {
                if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
                    tokens[i] == "/") {
                    switch (tokens[i][0]) {
                    case '+':
                        tokens[i] = to_string(stoi(tokens[i - 2]) +
                                              stoi(tokens[i - 1]));
                        break;
                    case '-':
                        tokens[i] = to_string(stoi(tokens[i - 2]) -
                                              stoi(tokens[i - 1]));
                        break;
                    case '*':
                        tokens[i] = to_string(stoi(tokens[i - 2]) *
                                              stoi(tokens[i - 1]));
                        break;
                    case '/':
                        tokens[i] = to_string(stoi(tokens[i - 2]) /
                                              stoi(tokens[i - 1]));
                        break;
                    }
                    check = true;
                    tokens.erase(tokens.begin() + i - 2, tokens.begin() + i);
                    break;
                }
            }
        }
        return stoi(tokens[tokens.size() - 1]);
    }
};
```

## Optimized
T: O(N), S: O(N)

```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> result;
        for (auto& it : tokens) {
            if (it != "+" && it != "-" && it != "/" && it != "*") {
                result.push(stoi(it));
            } else {
                int opr2 = result.top();
                result.pop();
                int opr1 = result.top();
                result.pop();

                if (it == "+") {
                    result.push(opr1 + opr2);
                } else if (it == "-") {
                    result.push(opr1 - opr2);
                } else if (it == "*") {
                    result.push(opr1 * opr2);
                } else if (it == "/") {
                    result.push(opr1 / opr2);
                }
            }
        }
        return result.top();
    }
};
```

Optimized Clean Code

```cpp
class Solution {
private:
    stack<int> result;

public:
    int operation(int& opr1, int& opr2, string& oper) {
        if (oper == "+") {
            return opr1 + opr2;
        } else if (oper == "-") {
            return opr1 - opr2;
        } else if (oper == "*") {
            return opr1 * opr2;
        } else if (oper == "/") {
            return opr1 / opr2;
        } else
            return NULL;
    }
    int evalRPN(vector<string>& tokens) {

        for (auto& it : tokens) {
            if (it == "+" || it == "-" || it == "/" || it == "*") {
                int opr2 = result.top();
                result.pop();
                int opr1 = result.top();
                result.pop();
                result.push(operation(
                    opr1, opr2, it)); // solves and pushes result onto stack
            } else
                result.push(stoi(it));
        }
        return result.top();
    }
};
```