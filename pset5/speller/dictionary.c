// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
//may change
const unsigned int N = 26;
unsigned int no_words = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
// must be case-insensitive
// Beware hard-coding common words (e.g., the)
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *cursor = table[index];
    while(cursor != NULL){
        if(strcasecmp(cursor->word, word) == 0){
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int x = 0;
    for(int i = 0, n = strlen(word); i < n; i++){
        int y = toupper(word[i]);
        x += y;
    }
    return x % 26;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *infile = fopen(dictionary, "r");
    if(infile == NULL){
        return false;
    }
    char str[LENGTH + 1];
    while(fscanf(infile, "%s", str) != EOF){
        node *n = malloc(sizeof(node));
        if(n == NULL){
            return false;
        }
        strcpy(n->word, str);

        int index = hash(str);
        if(table[index] == NULL){
            n->next = NULL;
        }
        else{
        n->next = table[index];
        }
        table[index] = n;

        no_words += 1;
    }
    fclose(infile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return no_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int i = 0; i < N; i++){
        node *cursor = table[i];
        while(cursor != NULL){
        node *tmp = cursor;
        cursor = cursor->next;
        free(tmp);
        }
        if(cursor == NULL){
        return true;
        }
    }
    return false;
}
