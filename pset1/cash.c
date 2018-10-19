#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    // get dollars loop until correct value inputted
    float dollars;
    do
    {
        dollars = get_float("Change Owed: ");
    }
    while (dollars < 0);
    // convert to rounded cents
    int cents = round(dollars * 100);
    // total coin count
    int sum = 0;
    // after quarters
    int leftover = cents % 25;
    // calculate number of quarters used
    sum += (cents - leftover) / 25;

    // repeat for dimes
    int leftove = leftover % 10;
    sum += (leftover - leftove) / 10;

    // repeat for nickels
    int leftov = leftove % 5;
    sum += (leftove - leftov) / 5;

    // repeat for pennies
    int lefto = leftov % 1;
    sum += (leftov - lefto) / 1;

    printf("%i\n", sum);
}
