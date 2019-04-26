#ifndef PLAYFAIR_SOLUTION_H
#define PLAYFAIR_SOLUTION_H

#include <string>

void prepare(std::string input, char* output);

void grid(std::string codeword, char square[6][6]);

void add_to_string(std::string &codeword);

void bigram(
  char square[6][6], char inchar1, char inchar2, char &outchar1, char &outchar2
);

void encode(char square[6][6], char* prepared, char* encoded);

void decode(char square[6][6], char* encoded, char* decoded);

#endif
