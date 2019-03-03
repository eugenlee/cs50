// Implements a dictionary's functionality

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#include "dictionary.h"

// create own data type for hash table called node
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

node *hashtable[THICC];

unsigned int size_counter = 0;

int hash(char letter)
{
    if isupper(letter)
    {
        return letter - 'A';
    }
    else
    {
        return letter - 'a';
    }
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int l = strlen(word);
    char word2[l + 1];

    for (int i = 0; i < l; i++)
    {
        word2[i] = tolower(word[i]);
    }
    word2[l] = '\0';

    int bucket = hash(word2[0]);
    node *cursor = hashtable[bucket];

    // printf("%s\n", cursor->word);

    while (cursor != NULL)
    {
        //printf("%s\n", cursor->word);
        if (strcmp(cursor->word, word2) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        unload();
        return false;
    }

    char buffer[LENGTH + 1];
    while (fgets(buffer, LENGTH + 2, fp) != NULL)
    {
        size_counter++;
        buffer[strlen(buffer) - 1] = '\0';

        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            unload();
            return false;
        }
        int bucket = hash(buffer[0]);

        strcpy(new_node->word, buffer);

        // printf("%i", bucket);
        // if nothing in hashtable, set first item to the new_node. If there is, add to beginning of list and change head ptr
        new_node->next = hashtable[bucket];
        hashtable[bucket] = new_node;
    }

    fclose(fp);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return size_counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < THICC; i++)
    {
        node *b = hashtable[i];

        while (b != NULL)
        {
            node *temp = b;
            b = b->next;
            free(temp);
        }
    }

    return true;
}
