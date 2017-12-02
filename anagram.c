#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "anagram.h"

int main(int argc, char **argv)
{
    bool anagram = false;

    /* check number of command-line arguments */
    if (argc != 3)
    {
        usage();

        /* return error */
        return -2;
    }

    if (!checkandnormalizeword(argv[1]))
    {
        return -2;
    }

    if (!checkandnormalizeword(argv[2]))
    {
        return -2;
    }

    /* detect characters in use */
    bool characters[255];
    for (int i = 0; i < 255; i++)
    {
        characters[i] = false;
    }

    for (int i = 0; argv[1][i]; i++)
    {
        characters[argv[1][i]] = true;
    }

    for (int i = 0; argv[2][i]; i++)
    {
        characters[argv[2][i]] = true;
    }

    int charcount = 0;
    for (int i = 0; i < 255; i++)
    {
        if (characters[i])
        {
            charcount++;
        }
    }

    primechar *mapping = calloc(charcount, sizeof(primechar));

    int j = 0;
    int prime = 2;
    for (int i = 0; i < 255; i++)
    {
        if (characters[i])
        {
            mapping[j].chr = i;

            mapping[j].prime = prime;

            j++;
            prime = nextprime(prime);
        }
    }

    uint64_t primes[255];

    for (int i = 0; i < charcount; i++)
    {
        if (characters[mapping[i].chr])
        {
            primes[mapping[i].chr] = mapping[i].prime;
        }
    }

    uint64_t word1 = 1;
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        word1 = word1 * primes[argv[1][i]];
    }

    uint64_t word2 = 1;
    for (int i = 0; i < strlen(argv[2]); i++)
    {
        word2 = word2 * primes[argv[2][i]];
    }

    anagram = word1 == word2;

    fprintf(stdout, "\"%s\" and \"%s\" are", argv[1], argv[2]);

    if (!anagram)
    {
        fprintf(stdout, " not");
    }
    
    fprintf(stdout, " anagrams");

    if (anagram)
    {
        /* return */
        return 0;
    }

    return -1;
}

bool checkandnormalizeword(char *word)
{
    if (word == NULL)
    {
        return false;
    }

    for (int i = 0; word[i]; i++)
    {
        if (!isalpha(word[i]))
        {
            return false;
        }

        word[i] = tolower(word[i]);
    }

    return true;
}

uint64_t nextprime(uint64_t n)
{
    uint64_t i, j;

    for (i = n + 1;; i++)
    {
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
                break;
        }

        if (j == i)
        {
            return i;
        }
    }
}

void usage()
{
    fprintf(stdout, "Usage: anagram.exe WORD_1 WORD_2");
}