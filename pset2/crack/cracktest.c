#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#define _XOPEN_SOURCE
#include <unistd.h>

char *crypt(const char *key, const char *salt);
int main(void)
{
    char *c = crypt("rofl", "50");
    char *pw_dict = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int s = strlen(pw_dict);
    printf("%i\n", s);

}
