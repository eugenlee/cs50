#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];
        // check if inputted key is all alphabetical
        for (int h = 0, m = strlen(key); h < m; h++)
        {
            if (isalpha(key[h]))
            {
                continue;
            }
            else
            {
                printf("Must be alphabetic values only\n");
                return 1;
            }
        }
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        // initialize counter for letters in plaintext
        int v = 0;
        char keyword;
        for (int i = 0, n = strlen(plaintext), p = strlen(key); i < n; i++)
        {
            // make sure capitalization doesn't matter in key
            if isupper(key[v % p])
            {
                keyword = key[v % p] - 'A';
            }
            if islower(key[v % p])
            {
                keyword = key[v % p] - 'a';
            }
            // change upper case characters
            if (isupper(plaintext[i]))
            {
                printf("%c", 'A' + (plaintext[i] - 'A' + keyword) % 26);
                v++;
            }
            // change lower case characters
            else if (islower(plaintext[i]))
            {
                printf("%c", 'a' + (plaintext[i] - 'a' + keyword) % 26);
                v++;
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