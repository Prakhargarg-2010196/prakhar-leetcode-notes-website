# 36. Valid Sudoku

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


## References
- [Solution from other person](https://leetcode.com/problems/valid-sudoku/discuss/15464/My-short-solution-by-C%2B%2B.-O(n2))
- https://en.wikipedia.org/wiki/Mathematics_of_Sudoku
- https://en.wikipedia.org/wiki/Sudoku_solving_algorithms
- https://en.wikipedia.org/wiki/Sudoku#Variants
- https://learn.microsoft.com/en-us/cpp/cpp/declarations-and-definitions-cpp?view=msvc-170