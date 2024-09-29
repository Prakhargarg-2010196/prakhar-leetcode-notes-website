# Prime Pairs With Target Sum

The problem is simple if you know about [sieve of eratosthenes](../basic-implementations/math/SieveOfErastothenes.md).

## Brute Force

```cpp
// 2761. Prime Pairs With Target Sum
#include <bits/stdc++.h>
using namespace std;
vector<bool> isPrimeSieve(int number)
{
   
    vector<bool> sieve(number + 1, true);
   
    sieve[0] = sieve[1] = false;
   
    for (long long i = 2; (long long)(i * i) <= number; i++)
    {
        if (sieve[i] == true)
        {
            for (long long j = i * i; j <= number; j += i)
            {
                sieve[j] = false;
            }
        }
    }
    return sieve;
}

vector<vector<int>> findPrimePairs(int n)
{
    vector<vector<int>> result;
    vector<bool> primeSieve = isPrimeSieve(n);
    for (int i = 2; i <= n / 2; i++)
    {
        // Only checking till n/2 as we only want the increasing values of x
        if (primeSieve[i] == true and primeSieve[n - i] == true)
        {
            // if both i and number - i ie if 3 is prime and 7 is prime
            // then as sieve consist of only prime numbers then it
            // becomes part of result.
            result.push_back({i, n - i});
        }
    }

    return result;
}
```
