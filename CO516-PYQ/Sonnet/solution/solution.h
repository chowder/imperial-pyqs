#ifndef SONNET_SOLUTION_H
#define SONNET_SOLUTION_H

#include <string>

int count_words(const char* line);
bool find_phonetic_ending(const char* word, char* phonetic_ending);
bool find_rhyme_scheme(const char* filename, char* scheme);
std::string identify_sonnet(const char* filename);
/* bonus question */
char rhyming_letter_2(const char *ending);

#endif
