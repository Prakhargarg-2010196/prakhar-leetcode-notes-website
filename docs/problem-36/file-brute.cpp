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