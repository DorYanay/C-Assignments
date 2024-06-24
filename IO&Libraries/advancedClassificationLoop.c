#include <stdio.h>
#include <math.h>
#include "NumClass.h"

// Function to check if the given Integer is Armstrong (Iteratively)
int isArmstrong(int n)
{
    int length = 0;
    int num = n;
    int number = n;
    int sum = 0;
    while (num)
    {
        length++;
        num = num / 10;
    }
    while (number)
    {
        int p = number % 10;
        sum += pow(p, length);
        number = number / 10;
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
// Function to check if the given Integer is Palindrome (Iteratively)
int isPalindrome(int n)
{
    int reverse = 0;
    int num = n;
    while (num != 0)
    {
        reverse = (reverse * 10) + (num % 10);
        num = num / 10;
    }
    if (reverse == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
