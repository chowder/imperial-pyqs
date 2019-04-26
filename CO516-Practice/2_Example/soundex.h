#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>

void encode(const char* surname, char* soundex);
int compare(const char* one, const char* two);
int count(const char* surname, const char* sentence);

#endif
