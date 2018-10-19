#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Integer between 0 and 23: ");
    }
    while (height < 0 || height > 23);
    for (int i = 0; i < height; i++)
    {
        // prints spaces for left portion
        for (int spaces = height - 1; spaces > i; spaces--)
        {
            printf(" ");
        }
        // prints # for left portion
        for (int x_s = -1; x_s < i; x_s++)
        {
            printf("#");
        }
        // prints double gap
        printf("  ");
        // prints # for right portion
        for (int x_s = -1; x_s < i; x_s++)
        {
            printf("#");
        }
        printf("\n");
    }
}
