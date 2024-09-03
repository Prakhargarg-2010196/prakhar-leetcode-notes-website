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