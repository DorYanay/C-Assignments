#include <stdio.h>
#include <math.h>
#include "NumClass.h"

// Function to check if the given Integer is Armstrong (Recursively)
int isArmstrong(int n)
{
    int length = 0;
    int num = n;
    int sum = 0;
    while (num)
    {
        length++;
        num = num / 10;
    }
    sum = recArmstrong(n, length);
    if (sum == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int recArmstrong(int number, int length)
{
    int sum = 0;
    if (number > 0)
    {
        sum = pow(number % 10, length) + recArmstrong(number / 10, length);
    }
    return sum;
}
// Function to check if the given Integer is Palindrome (Recursively)
int isPalindrome(int n)
{
    int sum = 0;
    sum = recPalindrome(n, 0);
    if (sum == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int recPalindrome(int num1, int num2)
{
    if (num1 == 0)
    {
        return num2;
    }
    num2 = (num2 * 10) + (num1 % 10);
    return recPalindrome(num1 / 10, num2);
}
