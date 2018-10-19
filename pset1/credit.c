#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    // sum value variables
    long long sum_last = 0;
    long long sum_second_last = 0;
    // get number
    long long cred_number = get_long_long("Number: ");
    long long cc = cred_number;
    int z = 0;
    while (cc > 0)
    {
        long long last_digit = cc % 10;
        // sum every other # from last digit
        sum_last += last_digit;
        // divide to get next value
        cc = cc / 10;
        z++;
        if (cc == 0)
        {
            break;
        }
        // 2 times every other from 2nd to last digit
        // if greater than 10, need to add digits not number
        long long second_last = 2 * (cc % 10);
        if (second_last > 9)
        {
            sum_second_last += 1 + second_last % 10;
        }
        // if under 10, just add number
        else
        {
            sum_second_last += second_last;
        }
        // divide to get next place
        cc = cc / 10;
        z++;
        if (cc == 0)
        {
            break;
        }
    }
    int big_sum = sum_last + sum_second_last;
    // get first digit or first two digits to check company
    int first_digit = cred_number / pow(10, z - 1);
    int two_digits = cred_number / pow(10, z - 2);
    if (big_sum % 10 == 0)
    {
        if (((two_digits == 34) || (two_digits == 37)) && (z == 15))
        {
            printf("AMEX\n");
        }
        else if (((two_digits == 51) || (two_digits == 52) || (two_digits == 53) || (two_digits == 54) || (two_digits == 55)) && (z == 16))
        {
            printf("MASTERCARD\n");
        }
        else if ((first_digit == 4) && (z == 13 || z == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}