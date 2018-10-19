#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#define _XOPEN_SOURCE
#include <unistd.h>

/* key is a user's typed password.
salt is a two-character string chosen from the set [a-zA-Z0-9./].
This string is used to perturb the algorithm in one of 4096 different
ways. */
// rofl:50fkUxYHbnXGw
// some way to use recursion

char *crypt(const char *key, const char *salt);
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        char *hash = argv[1];
        char salt[2];
        // salt is first two characters
        memcpy(salt, hash, 2);
        // list of all possibilities
        char *pw_dict = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int l = 55;
        // initialize as NUL
        char pw[6] = "\0\0\0\0\0\0";
        // nested for loops to test all possibilities of pw in pw_dict from length 1 to 5
        for (int five = 0; five < l; five++)
        {
            for (int four = 0; four < l; four++)
            {
                for (int three = 0; three < l; three++)
                {
                    for (int two = 0; two < l; two++)
                    {
                        for (int one = 1; one < l; one++)
                        {
                            pw[0] = pw_dict[one];
                            pw[1] = pw_dict[two];
                            pw[2] = pw_dict[three];
                            pw[3] = pw_dict[four];
                            pw[4] = pw_dict[five];
                            // compare hash to generated hash to see if correct pw
                            if (strcmp(hash, crypt(pw, salt)) == 0)
                            {
                                printf("%s\n", pw);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
        printf("nope\n");
        //char *c = crypt("rofl", "50");
        //printf("%s\n", c);
    }
    else
    {
        printf("Must input a hashed password\n");
        return 1;
    }
}
