#include <cstring>
#include <iostream>
#include <map>
#include <string>

using namespace std;

/* lookup table for braille characters */
map<char, string> brailleLookupTable = {
  { 'a', "0....."},
  { 'b', "00...."},
  { 'c', "0..0.."},
  { 'd', "0..00."},
  { 'e', "0...0."},
  { 'f', "00.0.."},
  { 'g', "00.00."},
  { 'h', "00..0."},
  { 'i', ".0.0.."},
  { 'j', ".0.00."},
  { 'k', "0.0..."},
  { 'l', "000..."},
  { 'm', "0.00.."},
  { 'n', "0.000."},
  { 'o', "0.0.0."},
  { 'p', "0000.."},
  { 'q', "00000."},
  { 'r', "000.0."},
  { 's', ".000.."},
  { 'r', "000.0."},
  { 's', ".000.."},
  { 't', ".0000."},
  { 'u', "0.0..0"},
  { 'v', "000..0"},
  { 'w', ".0.000"},
  { 'x', "0.00.0"},
  { 'y', "0.0000"},
  { 'z', "0.0.00"},
  { '.', ".0..00"},
  { ',', ".0...."},
  { ';', ".00..."},
  { '-', "..0..0"},
  { '!', ".00.0."},
  { '?', ".00..0"},
  { '(', ".00.00"},
  { ')', ".00.00"},
  { ' ', "......"}
};


/* produces a string (the second parameter braille) that represents the Braille
encoding of a single input character (the first parameter ch) */
int encode_character(const char character, char* braille)
{
  string temp_string = "";

  // If it is a character
  if (isalpha(character)){
    if (isupper(character))
      temp_string += ".....0";
    temp_string += brailleLookupTable[tolower(character)];
  }

  // If it is a digit
  else if (isdigit(character)){
    temp_string += "..0000";
    if (character == '0')
      temp_string += brailleLookupTable['j'];
    else
      temp_string += brailleLookupTable[character + 'a' - '1'];
  }

  // Otherwise, try to map to lookup table and ignore otherwise
  else {
    auto it = brailleLookupTable.find(character);
    if (it != brailleLookupTable.end())
      temp_string += brailleLookupTable[character];
    else
      return 0;
  }
  strcpy(braille, temp_string.c_str());
  return temp_string.length();
}


/* a recursive which produces the Braille encoding (second output parameter
braille) of a plaintext input string (first parameter plaintext). */
void encode(const char* plaintext, char* braille)
{
  // If at the end of the plaintext string, return
  if (plaintext[0] == '\0'){
    braille[0] = '\0';
    return;
  }
  // Otherwise, encode the character and put it into braille
  else {
    int length = encode_character(plaintext[0], braille);
    // Increment the pointers accordingly and recurse
    return encode(plaintext+1, braille+length);
  }
}


/* helper function that takes an array of braille characters and prints them on
screen */
void display_braille(char* braille, ostream &cout)
{
  int num_chars = strlen(braille) / 6;
  // Print first row
  for (int row = 0; row < 3; row++){
    for (int i = 0; i < num_chars; i++){
      cout << braille[i*6 + row];
      cout << braille[i*6 + 3 + row];
      cout << " ";
    }
    cout << endl;
  }
}


/* helper function that displays corresponding plaintext character under each
braille cell (if applicable) */
void display_text(string plaintext, ostream &cout)
{
  for (int i = 0; i < (int)plaintext.length(); i++){
    // If it's an uppercase character or digit, skip a braille letter
    if (isupper(plaintext[i]) || isdigit(plaintext[i]))
      cout << "   ";
    cout << plaintext[i] << "  ";
  }
  cout << endl;
}


/* takes a plaintext string and writes the corresponding sequence of 3x2 Braille
cells to an output stream */
void print_braille(const char* plaintext, ostream &cout)
{
  char braille[1024];
  encode(plaintext, braille);
  display_braille(braille, cout);
  display_text(plaintext, cout);
}
