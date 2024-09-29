# Kth grammar

```cpp
#include <bits/stdc++.h>
using namespace std;
/**
 * This question will help you think recursively.
 * As the grammar is being generated recursively
 * here from the previous row values the recursion
 * is obvious here.
*/
int kthGrammar(int n, int k)
{
    /**
     * We have made an observation that before
     * mid the child and parent nodes are the
     * same but after the mid the parent and
     * child bits are reversed
    **/

    /**
     * First find the length of the bits in the
     * current row the number of bits in the current
     * row is 1 less than row number
     **/
    int mid = pow(2, n - 1) / 2;
    // Base Condition
    if (n == 1 && k == 1)
    {
        return 0;
    }
    // Hypothesis and Induction
    if (k <= mid)
    {
        // if k is less than the mid, the parent bits are equal to
        // the child bits i.e.
        return kthGrammar(n - 1, k);
    }
    else
    {
        return !(kthGrammar(n - 1, k - mid));// negate the ouput if the k > mid
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout<<kthGrammar(n,k);
    return 0;
}
```

