#ifndef PIGLATIN_H
#define PIGLATIN_H

#include <iostream>

int findFirstVowel(const char* word);
void translateWord(const char* word, char* translated);
void translateStream(std::ifstream &input, std::ostream &cout);

#endif
