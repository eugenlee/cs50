#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int key = atoi(argv[1]);
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            // change upper case characters
            if (isupper(plaintext[i]))
            {
                printf("%c", 'A' + (plaintext[i] - 'A' + key) % 26);
            }
            // change lower case characters
            else if (islower(plaintext[i]))
            {
                printf("%c", 'a' + (plaintext[i] - 'a' + key) % 26);
            }
            // return non alphabetic values as same
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        // make pretty add line
        printf("\n");
    }
    // if command line not inputted, throw error
    else
    {
        printf("Must input one command-line argument\n");
        return 1;
    }
}