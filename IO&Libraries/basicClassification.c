#include <stdio.h>
#include <math.h>
#include "NumClass.h"

// An helper function that factorials a number. (helper for isStrong function)
int fact(int n)
{
    int fn = 1;
    for (int i = 1; i <= n; i++)
    {
        fn *= i;
    }
    return fn;
}
// Function to find if the given number is a Strong number.
int isStrong(int n)
{
    int num = n;
    int sum = 0;
    if (n == 0)
    {
        return 0;
    }
    while (num > 0)
    {
        sum += fact(num % 10);
        num = num / 10;
    }
    if (sum == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// Function to find if the given Integer is prime. (In this Assignment the number 1 is a prime).
int isPrime(int n)
{
    int num = n;
    if (n < 1)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
