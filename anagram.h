#ifndef ANAGRAM_H
#define ANAGRAM_H

#include <stdint.h>

int main(int argc, char** argv);

void usage();

bool checkandnormalizeword(char *word);

uint64_t nextprime(uint64_t n);

typedef struct
{
    char chr;
    uint64_t prime;
}  primechar;

#endif