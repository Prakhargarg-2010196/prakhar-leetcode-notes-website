# 3691 · Dot Product of Two Sparse Vectors


[Question Link](https://www.lintcode.com/problem/3691/description)

## Approaches

Hashmap

- Avoid use of vector for storing the data as it would be difficult to deal with non-placed values while traversing (we have to account for zeroes in the array to leave them in calculation)

Two Pointer

[Solution](https://walkccc.me/LeetCode/problems/1570/)

- As we have to traverse in consecutive manner two pointers can be used
- Approach remains the same but the difference is using vector of pairs instead of hashmap
- Move pointers around when pointers are either behind or forward.
