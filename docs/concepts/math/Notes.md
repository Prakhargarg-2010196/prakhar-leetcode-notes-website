# Maths

## SIEVE OF ERATOSTHENES

1. Store the bool value initially to true(considering all numbers to be prime)for all a possible numbers till n including n.(size is taken as n+1 instead of n).
2. Making 0 and 1 to be false as they can't be prime by fundamental theorem of arithmetic and definition of prime numbers.
3. This step consist of three minor steps:
1. First Minor step
```cpp
    for(long long i=2;(long long)(i*i)<=number;i++){}
```

Take the initial prime numbers only till sqrt(number) or ``i^2<=number``
This comes from the major improvement of observation that any number
``n=a*b`` where a and b are two factors of n but it can be seen that any
of a or b can definitely be less than or equal to sqrt of n or square
of the number must be less than n.So if we found out that factor there m
might not be need to re-calculate till next factor.

1. Second minor step

```cpp
for(long long j=i*i;j<=number;j+=i)
```

Check if the number we are checking is prime or not if so make all of
its multiples whose square is less than or equal to n as false.This
optimization can be easily proven by the example like
taking multiples of 5 for example ie. 5,10,15 etc.
10 = 2*5
15 = 3*5
20 = 4*5
and so on.
As can be seen the multiples of 5 that are less than or equal to square
of number are already accounted by smaller factors like 2,3 and 4
so no need to again make it check for 5.

2. Third minor step

```cpp
sieve[j]=false;
```

It is to make the items that are following minor step 2
as false.

## Related Questions

- [Prime Pairs With Target Sum](../../problem-2761/Notes.md)