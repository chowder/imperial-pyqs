#include <string>
#include <cctype>
#include <iostream>

using namespace std;


void prepare(string input, char* output)
{
  int count = 0;
  for (char character: input)
    if (isalnum(character)){
      output[count++] = toupper(character);
    }
  if (count % 2 == 1)
    output[count++] = 'X';
  output[count] = '\0';
}


void add_to_string(string &codeword)
{
  for (char character = 'A'; character <= 'Z'; character++)
    if (codeword.find(character) == string::npos){
      codeword += character;
      return;
    }
  for (char character = '0'; character <= '9'; character++)
    if (codeword.find(character) == string::npos){
      codeword += character;
      return;
    }
}


void grid(string codeword, char square[6][6])
{
  // use a buffer since we're truncating the string as we're looping through
  string buf = codeword;
  // remove all duplicates
  for (char character: buf){
    int first_seen = codeword.find(character);
    while (codeword.find(character, first_seen + 1) != string::npos)
      codeword.erase(codeword.find(character, first_seen + 1), 1);
  }
  // fill out the rest of the string
  while (codeword.size() != 36)
    add_to_string(codeword);
  // add to grid
  for (int row = 0; row < 6; row++)
    for (int col = 0; col < 6; col++)
      square[row][col] = codeword[row * 6 + col];
}


typedef pair<int, int> Position;

Position find_position(char square[6][6], char input){
  for (int row = 0; row < 6; row++)
    for (int col = 0; col < 6; col++)
      if (square[row][col] == input)
        return {row, col};
  return {-1, -1};
}


void bigram(
  char square[6][6], char inchar1, char inchar2, char &outchar1, char &outchar2)
{
  Position pos_inchar1 = find_position(square, inchar1);
  Position pos_inchar2 = find_position(square, inchar2);

  outchar1 = square[pos_inchar1.first][pos_inchar2.second];
  outchar2 = square[pos_inchar2.first][pos_inchar1.second];
}


void encode(char square[6][6], char* prepared, char* encoded)
{
  // base case, if the encoding is complete
  if (prepared[0] == '\0'){
    encoded[0] = '\0';
    return;
  }
  // start encoding
  char inchar1 = prepared[0];
  char inchar2 = prepared[1];
  bigram(square, inchar1, inchar2, encoded[0], encoded[1]);
  encode(square, prepared+2, encoded+2);
}


/* bonus challenge */
void decode(char square[6][6], char* encoded, char* decoded)
{
  // base case, if the encoding is complete
  if (encoded[0] == '\0'){
    decoded[0] = '\0';
    return;
  }
  // start encoding
  char inchar1 = encoded[0];
  char inchar2 = encoded[1];
  bigram(square, inchar1, inchar2, decoded[0], decoded[1]);
  encode(square, encoded+2, decoded+2);
}
