#include <string>
#include <cctype>
#include <sstream>
using namespace std;

/* a function which maps a given character to its soundex code */
char soundex_map(char character){
  switch(character){
    case 'b': case 'f': case 'p': case 'v':
    return '1'; break;
    case 'c': case 'g': case 'j': case 'k': case 'q': case 's': case 'x': case 'z':
    return '2'; break;
    case 'd': case 't':
    return '3'; break;
    case 'l':
    return '4'; break;
    case 'm': case 'n':
    return '5'; break;
    case 'r':
    return '6'; break;
    default:
    return '0'; break;
  }
}


/* a function which produces the Soundex encoding (in output parameter soundex)
corresponding to a given surname (in input parameter surname) */
void encode(const char* surname, char* soundex){
  // Declare variables
  char last_code;
  char code;
  int count = 1;

  // Get first initial letter & set last letter of soundex to '\0'
  soundex[0] = toupper(surname[0]);
  soundex[5] = '\0';

  // Loop through each letter in the surname
  for (int i = 0; surname[i] != '\0'; i++){
    // Break if we've filled all 3 codes
    if (count == 3) break;
    // Get soundex map for that character in the surname
    code = soundex_map(surname[i]);
    // If the code isn't 0 and isn't the same as the last code
    if (code != '0' && last_code != code)
      soundex[count++] = last_code = code;
  }
  // Once surname is exhausted, check if soundex has 4 characters
  while (count != 4)
    soundex[count++] = '0';
}


/* a recursive function which compares two Soundex codes; returns 1 if the
Soundex codes are the same, 0 otherwise */
int compare(const char* one, const char* two){
  return (one[0] != two[0])                 ? false :
         (one[0] == '\0' && two[0] == '\0') ? true  :
                                              compare(one + 1, two + 1);
}


/* a function which returns the number of words in a given sentence that have
the same Soundex encoding as the given surname */
int count(const char* surname, const char* sentence){
  // Declare variables
  char soundex_1[5], soundex_2[5];
  string word;
  int count = 0;

  // Get soundex code of the surname
  encode(surname, soundex_1);

  // Loop through each word of the sentence
  istringstream iss(sentence);
  while (iss >> word){
    encode(word.c_str(), soundex_2);
    // Increment if they have the same soundex code
    if (compare(soundex_1, soundex_2))
      count++;
  }
  return count;
}
