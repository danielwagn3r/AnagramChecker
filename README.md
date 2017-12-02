# AnagramChecker
Write a program that checks if the two passed command-line arguments are anagrams.

The program shall support the following command-line interface:

```shell
$ anagram.exe WORD_1 WORD_2
```

The program shall operate case-insensitive. You may either convert the input to upper- or lowercase using `toupper()` or `tolower()`.

To check if a word is valid, you may use `isalpha()` on each character (thus, your program may only support English words or transliterations that just use a-z and/or A-Z).

In the case of the two words being anagrams, your program shall return 0. In the case of the two words not being anagrams, your program shall return -1. In the case of an error, your program shall return -2.

## Checking Method
Implement the anagram checking functionality as follows:

For each natural number, there is only one way to represent it as a product of prime numbers (=factorization). Any permutation of these prime factors leads to the same product. This anagram checker makes use of this property.

Create a table that maps each allowed character to a unique prime number, for example:

| character | prime |
| :---: | :---: |
| E | 2 |
| R | 3 |
| T | 5 |
| S | 7 |
| A | 11 |
| ... | ... |

The word STARE can now be represented as 7 * 5 * 11 * 3 * 2 = 2310

The word TEARS (an anagram) is represented as 5 * 2 * 11 * 3 * 7 = 2310

The word STARS (not an anagram) is represented as 7 * 5 * 11 * 3 * 7 = 8085

Two words that are anagrams result in the same product of their primes.

Note 1

---
The products for larger words get quite big. Use `uint64_t` from
`<stdint.h>` to store the numbers in the character → prime table
and for the product.

Additionally, use the fact that some characters occur more often than others to map the more frequent characters to the lower
primes.

Note 2

---
Try to find a way to detect when a multiplication overflow occurs,
that is, when a multiplication product gets to large for `uint64_t` (larger than 18446744073709551616)


## Example Executions

```shell
$ anagram.exe word drow
"word" and "drow" are anagrams
$ anagram.exe word draw
"word" and "draw" are not anagrams
$ anagram.exe
Usage: anagram.exe WORD_1 WORD_2
$ anagram.exe word drow draw
Usage: anagram.exe WORD_1 WORD_2
```