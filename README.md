# HashTableSpellChecker
A simple spell checker using a hash table

## Description
This assignment implements a spellchecker using a hash table. The program reads a text file to generate the dictionary.
The user can add additional words to the dictionary, remove words, print the contents of the dictionary or spellcheck a file.


## Running the Program

To compile the program, navigate to the main directory for the assignment and use the command "make"
To run the program, use the command "./bin/program <INPUT FILE>" where <INPUT FILE> is a properly formatted text document
A sample file has been included in the assests directory
To compile the test program, navigate to the main directory for the assignment and use the command "make test"
To run the test program, use the command "./bin/testing"

## Testing
The test program tests the hash table functions with normal input.

## Limitations
If the hash function generates two identical keys, the latter will not appear in certian hash table functions. The menu can act unusual if the input is not
a single integer on the menu (The original specifications of this project stated input will be normal and not to perform input checking)

## Hash function and Collisions
The hash function is based upon a common string hash function. Each letter's ascii value is added in a sum to generate a key.
To help generate more unique keys, each letter's ascii value is multiplied by it's index in the word. The Index location in the hash table
is determined using hashing division.

Collisions are solved using a singly linked list structure inside the list node. Collisions are added to the next node. When nodes are removed
The links are reconnected to preserve the list.
