# Valid Sudoku

## Concepts

- To check if greater than 1 and while incrementing its value

```js
do this if(number++){

}
```

Multiple solutions to finding position of grid box were found of which this is the [context](https://en.wikipedia.org/wiki/Mathematics_of_Sudoku) for math context

- To find the index of grid box in sudoku use `(i/3*3 +j/3)`

indexBox = `i / 3 * 3 + j / 3`
for visualization indexBox  here

```
0  0  0 | 1  1  1 | 2  2  2
0  0  0 | 1  1  1 | 2  2  2
0  0  0 | 1  1  1 | 2  2  2
--------+---------+---------
3  3  3 | 4  4  4 | 5  5  5
3  3  3 | 4  4  4 | 5  5  5
3  3  3 | 4  4  4 | 5  5  5
--------+----------+--------
6  6  6 | 7  7  7 | 8  8  8
6  6  6 | 7  7  7 | 8  8  8
6  6  6 | 7  7  7 | 8  8  8
```

- We can also use the key of the grid hashmap as a pair of `{i/3,j/3}` or we can use set to represent like this [solution](https://leetcode.com/problems/valid-sudoku/discuss/15472/Short%2BSimple-Java-using-Strings)
- [One visualisation of sudoku check](https://docs.google.com/spreadsheets/d/1f3fdAJ4xsABHr0WKaz_gQluNeutPPu5gRh1GZDohG7g/edit?usp=sharing)

## Brute Force 
```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int, int>> rows(9);
        vector<unordered_map<int, int>> cols(9);
        vector<unordered_map<int, int>> boxes(9);
        // For rows
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int curr = board[i][j];
                if (curr == '.')
                    continue;
                rows[i][curr]++;
            }
        }
        // For cols
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int curr = board[j][i];
                if (curr == '.')
                    continue;
                cols[i][curr]++;
            }
        }
        // For boxes
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int gi = (i / 3) * 3 + j / 3;
                int curr = board[i][j];
                if (curr == '.')
                    continue;
                boxes[gi][curr]++;
            }
        }
        // End check for the count
        for (int i = 0; i < 9; i++) {
            for (auto& it : rows[i]) {
                if (it.second > 1)
                    return false;
            }
            for (auto& it : cols[i]) {
                if (it.second > 1)
                    return false;
            }
            for (auto& it : boxes[i]) {
                if (it.second > 1)
                    return false;
            }
        }
        return true;
    }
};
```

```cpp
// Good for readability but not for simplicity and fast coding moreover it takes more space and time for execution
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using std::cin, std::cout, std::endl, std::unordered_map, std::multimap, std::vector, std::pair, std::greater;
bool isValidCol(vector<vector<char>> &sudoku);
bool isValidBox(vector<vector<char>> &sudoku);
bool isValidRow(vector<vector<char>> &sudoku);
bool isValidSudoku(vector<vector<char>> &sudoku);
int main()
{
    int n;
    cin >> n;
    vector<vector<char>> sudoku(n);
    for (auto &it : sudoku)
    {
        for (auto &it2 : it)
        {
            cin >> it2;
        }
    }
    cout << isValidSudoku(sudoku) << endl;
    return 0;
}
bool isValidSudoku(vector<vector<char>> &sudoku)
{
    return isValidRow(sudoku) && isValidCol(sudoku) && isValidBox(sudoku);
}
bool isValidRow(vector<vector<char>> &sudoku)
{
    // take 9 hashmaps for 9 rows
    // Will store count for 9 columns
    unordered_map<char, int> countRows[9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[i][j] == '.')
            {
                countRows[i][sudoku[i][j]] = 0;
            }
            else
            {
                countRows[i][sudoku[i][j]]++;
            }
        }
    }
    // Now check if any row contain count of element more than 2 or not
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (countRows[i][sudoku[j][i]] >= 2)
            {
                return false;
            }
        }
    }
    return true;
}
bool isValidCol(vector<vector<char>> &sudoku)
{
    unordered_map<char, int> countCol[9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[j][i] == '.')
            {
                countCol[i][sudoku[j][i]] = 0;
            }
            else{
                 countCol[i][sudoku[j][i]]++;
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(countCol[i][sudoku[j][i]]>=2){
                 return false;
            }
        }
    }
    return true;
}
bool isValidBox(vector<vector<char>> &sudoku)
{
    // take 9 hashmaps for 9 rows
    // Will store count for 9 columns
    unordered_map<char, int> countBoxes[9];
    int indexBox;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            indexBox = (i / 3) * 3 + j / 3;
            if (sudoku[i][j] == '.')
            {
                 countBoxes[indexBox][sudoku[i][j]] = 0;
            }
            else
            {
                 countBoxes[indexBox][sudoku[i][j]]++;
            }
        }
    }
    // Now check if any row contain count of element more than 2 or not
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (countBoxes[i][sudoku[j][i]] >= 2)
            {
                 return false;
            }
        }
    }
    return true;
}
void printVector(vector<int> &res)
{
    for (auto &it : res)
    {
        cout << it << ",";
    }
}
```

## Optimized
```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> row;
            for (int j = 0; j < 9; j++) {
                char curr = board[i][j];
                if (curr == '.')
                    continue;
                if (row.count(curr)) {
                    return false;
                }
                row.insert(curr);
            }
        }
        // For cols
        for (int i = 0; i < 9; i++) {
            unordered_set<char> col;
            for (int j = 0; j < 9; j++) {
                char curr = board[j][i];
                if (curr == '.')
                    continue;
                if (col.count(curr)) {
                    return false;
                }
                col.insert(curr);
            }
            // For boxes
            vector<unordered_set<char>> boxes(9);
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    char curr = board[i][j];
                    int boxIndex = (i / 3) * 3 + j / 3;
                    if (curr == '.')
                        continue;
                    if (boxes[boxIndex].count(curr)) {
                        return false;
                    }
                    boxes[boxIndex].insert(curr);
                }
            }
        }
        return true;
    }
};

```

```cpp
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using std::cin, std::cout, std::endl, std::unordered_map, std::multimap, std::vector, std::pair, std::greater;
bool isValidCol(vector<vector<char>> &sudoku);
bool isValidBox(vector<vector<char>> &sudoku);
bool isValidRow(vector<vector<char>> &sudoku);
bool isValidSudoku(vector<vector<char>> &sudoku);
int main()
{
    int n;
    cin >> n;
    vector<vector<char>> sudoku(n);
    for (auto &it : sudoku)
    {
        for (auto &it2 : it)
        {
            cin >> it2;
        }
    }
    cout << isValidSudoku(sudoku) << endl;
    return 0;
}
bool isValidSudoku(vector<vector<char>> &sudoku)
{
    return isValidRow(sudoku) && isValidCol(sudoku) && isValidBox(sudoku);
}
bool isValidRow(vector<vector<char>> &sudoku)
{
    // take 9 hashmaps for 9 rows
    // Will store count for 9 columns
    unordered_map<char, int> countRows[9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[i][j] != '.')
            {
                // way to check if the element occurs more than twice as for first time it will increase the count but check remains falls as the count number remains zero
                /*
                    Other way to do this is that
                    countRows[i][soduko[i][j]]++;
                    if(countRows[i][soduko[i][j]]>=1){return false;}
                */
                if(countRows[i][sudoku[i][j]]++){
                    return false;
                }
            }
           
        }
    }
    return true;
}
bool isValidCol(vector<vector<char>> &sudoku)
{
    unordered_map<char, int> countCol[9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {   
            if (sudoku[j][i] != '.'){
                
                if(countCol[i][sudoku[j][i]]++);
                return false;
            }
        }
    }
    return true;
}
bool isValidBox(vector<vector<char>> &sudoku)
{
    // take 9 hashmaps for 9 rows
    // Will store count for 9 columns
    unordered_map<char, int> countBoxes[9];
    int indexBox;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            indexBox = (i / 3) * 3 + j / 3;
            if (sudoku[i][j] != '.')
            {   
                if (countBoxes[indexBox][sudoku[i][j]]++)
                {
                    return false;
                }
            }
        }
    }
    
    return true;
}
void printVector(vector<int> &res)
{
    for (auto &it : res)
    {
        cout << it << ",";
    }
}
void printHashMap(){
}
```



## References
- [Solution from other person](https://leetcode.com/problems/valid-sudoku/discuss/15464/My-short-solution-by-C%2B%2B.-O(n2))
- https://en.wikipedia.org/wiki/Mathematics_of_Sudoku
- https://en.wikipedia.org/wiki/Sudoku_solving_algorithms
- https://en.wikipedia.org/wiki/Sudoku#Variants
- https://learn.microsoft.com/en-us/cpp/cpp/declarations-and-definitions-cpp?view=msvc-170