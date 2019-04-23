#ifndef BRAILLE_H
#define BRAILLE_H

#include <iostream>
#include <string>

int encode_character(const char character, char* braille);
void encode(const char* plaintext, char* braille);
void print_braille(const char* plaintext, std::ostream &cout);

#endif
