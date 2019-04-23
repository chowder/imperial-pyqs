#include "../sonnet.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include "solution.h"

using namespace std;

int count_words(const char* line)
{
  int count = 0; char buf[512];
  while (get_word(line, ++count, buf));
  return --count;
}


bool is_vowel(char c)
{
  return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}


int find_last_vowel(char* line)
{
  int last = 0;
  for (int i = 0; i < strlen(line); i++)
    if (is_vowel(line[i]))
      last = &line[i] - &line[0];
  return last;
}


bool get_phonetic(const char* line, char* phonetic_ending)
{
  char buf[512]; int count = 0;
  while (get_word(line, ++count, buf + strlen(buf)));
  strcpy(phonetic_ending, buf + find_last_vowel(buf));
  return find_last_vowel(buf);
}


bool find_phonetic_ending(const char* word, char* phonetic_ending){
  ifstream in ("dictionary.txt");
  string line;
  char entry[512];
  while (!in.eof()){
    getline(in, line);
    get_word(line.c_str(), 1, entry);
    if (strcmp(word, entry) == 0)
      return get_phonetic(line.c_str(), phonetic_ending);
  }
  return false;
}


bool find_rhyme_scheme(const char* filename, char* scheme)
{
  // try to open file
  ifstream in (filename);
  if (in.fail()) return false;

  // declare variables
  string line, buf;
  char word[512], phonetic[512];
  rhyming_letter_2(RESET);

  while (!in.eof()){
    // get index and check if it's an empty line
    getline(in, line);
    int index = count_words(line.c_str());
    if (index == 0) continue;
    // find phonetic
    get_word(line.c_str(), index, word);
    if (find_phonetic_ending(word, phonetic))
      buf += rhyming_letter_2(phonetic);
  }
  // copy to scheme
  strcpy(scheme, buf.c_str());
  return true;
}


string identify_sonnet(const char* filename){
  const char* shakespearean = "ababcdcdefefgg";
  const char* petrarchan = "abbaabbacdcdcd";
  const char* spenserian = "ababbcbccdcdee";

  char scheme[512];
  if (!find_rhyme_scheme(filename, scheme))
    return "Unable to open file\n";
  return strcmp(scheme, shakespearean) == 0 ? "Shakespearean" :
         strcmp(scheme, petrarchan) == 0    ? "Petrarchan"    :
         strcmp(scheme, spenserian) == 0    ? "Spenserian"    :
                                              "Unknown";
}


/* bonus question */
char rhyming_letter_2(const char *ending){
  static char** rhyme_map = new (nothrow) char*[26];

  // check for reset bit
  if (ending == RESET){
    for (int i = 0; rhyme_map[i]; i++){
      delete [] rhyme_map[i];
      rhyme_map[i] = nullptr;
    }
    return '\0';
  }

  // look through our array
  int i;
  for (i = 0; rhyme_map[i]; i++){
    if (strcmp(rhyme_map[i], ending) == 0)
      return 'a' + i;
  }

  // we did not find it, add to our thingy
  rhyme_map[i] = new char[strlen(ending) + 1];
  strcpy(rhyme_map[i], ending);
  return 'a' + i;
}
