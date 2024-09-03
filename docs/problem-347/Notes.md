# Question Breakdown

<!-- Questions coming to head while reading the problem statement -->

<!-- As occurence is considered, then how to count the occurences? -->
## [Counting the Occurences](https://stackoverflow.com/a/28511600/15645824)

1. I can do counting the simple way by taking the array of counts (with all the elements initially set to zero).
Then take the element of original array as index in the count array and increment the count of element.
Problem: The problem with this method is that it allocates static array and doesn't reallocates memory when size of original array increases or decreases.
Although malloc and realloc can be used to solve the above problem stated.I would still prefer to use map for this.

2. Using map
Take the count of the array elements using a map of key-count pair using mp[element]++ syntax.

<!-- I have got the count and now I want to get the most occurence one-->

1. The first thought that came to my head was to use ordered map to this but that won't work as we have to do a lot of work to implement even if its sorted in that way.

2. Second thought is of using another array to store the reversed pair from the hashmap just created and then sort the pairs using comparator function
(O(nlogn)). Its simple approach but kind of off our time complexity.(brute force) or as found with another solution from [here](https://stackoverflow.com/a/2699091/15645824) we can use another mutimap (as two elements count can be same too) for solving this problem of sorting.

3. Use a heap data structure (using priority_queue)

4. Use bucket sort
