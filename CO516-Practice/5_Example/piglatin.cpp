#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

/* an unordered set for pig latin vowels */
unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u', 'y'});


/* a bool function which returns true if a character at given position in a word
is a vowel*/
bool isVowel(int position, const char* word)
{
  char letter = tolower(word[position]);
  // If y is the first or last letter of the string
  if (strlen(word) == 0)
    return false;
  if (letter == 'y')
    if (position == 0 || position == (int)(strlen(word) - 1))
      return false;
  // Otherwise look for the letter in the vowels hash table
  auto search = vowels.find(letter);
  return (search != vowels.end());
}


/* function that returns the position of the first vowel found in a string */
int findFirstVowel(const char* word)
{
  for (int i = 0; word[i] != '\0'; i++){
    if (isVowel(i, word))
      return i;
  }
  return -1;
}


/* takes a string, and moves all the characters before a given index to the back
of the string, and adds 'ay' to the back of it afterwards */
void pivot_string(const char* word, char* translated, int index)
{
  // Pivoting
  strcpy(translated, word+index);
  strncat(translated, word, index);
  // Lowercase the entire string
  for (int i = 0; translated[i]; i++)
    translated[i] = tolower(translated[i]);
  // If original word was capitalised, then capitalise the translated string
  if (isupper(word[0]))
    translated[0] = toupper(translated[0]);
  // Ayy
  strcat(translated, "ay");
}


/* translates a given word into pig latin */
void translateWord(const char* word, char* translated)
{
  int position = findFirstVowel(word);
  // If the word starts with a vowel, append 'way'
  if (position == 0){
    strcpy(translated, word);
    strcat(translated, "way");
  }
  // If the word has no vowels, append 'ay'
  else if (position == -1){
    strcpy(translated, word);
    strcat(translated, "ay");
  }
  // If the vowel is in the middle of the word,
  // pivot the word and add 'ay'
  else
    pivot_string(word, translated, position);
}


/* get the next word from an input stream, and cout anything that's not a letter
inbetween */
string get_next_word(ifstream &input, ostream &cout)
{
  string word;
  char letter;
  // If it's not a letter, keep getting until it is one
  while(input.get(letter), !isalpha(letter)){
    cout << letter;
    // If we reach the end of the file before so, return an empty string
    if (input.eof())
      return "";
  }
  // Once we have a letter, get the entire word for that letter
  while(isalpha(letter)){
    word += letter;
    input.get(letter);
  }
  input.putback(letter);
  // Return the word
  return word;
}


/* recursively translate an input stream into piglatin */
void translateStream(ifstream &input, ostream &cout)
{
  string word;
  char translated[100];
  // Get the next word in the stream
  word = get_next_word(input, cout);
  // If it's an empty string, we're at the end of the file
  if (word == "")
    return;
  else {
    // Translate the word and output it
    translateWord(word.c_str(), translated);
    cout << translated;
    // Recurse for the next word
    return translateStream(input, cout);
  }
}
