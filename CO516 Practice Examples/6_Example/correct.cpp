#include <iostream>
#include <cstring>
#include <string>

using namespace std;

/* You are supplied with two helper functions */

/* converts a character into a binary string representation */
void ascii_to_binary(char ch, char *binary);

/* converts a binary string representation into a character */
char binary_to_ascii(char *binary);

void ascii_to_binary(char ch, char *binary)
{
  for (int n = 128; n; n >>= 1)
    *binary++ = (ch & n) ? '1' : '0';
  *binary = '\0';
}

char binary_to_ascii(char *binary)
{
  int ch = 0;
  for (int n=0, slide=128; n<8; n++, slide >>= 1) {
    if (binary[n] == '1')
      ch = ch | slide;
  }
  return ch;
}


/* converts a string of text into binary */
void text_to_binary(const char *string, char *binary)
{
  char binary_char[9];
  if (*string == '\0'){
    *binary = '\0';
    return;
  }
  else {
    ascii_to_binary(*string, binary_char);
    memcpy(binary, binary_char, sizeof(binary_char));
    return text_to_binary(string+1, binary+8);
  }
}


/* converts a string of binary characters into text */
void binary_to_text(const char* binary_string, char *text)
{
  if (*binary_string == '\0')
    *text = '\0';
  else {
    char binary_char[9];
    for (int i = 0; i < 8; i++)
      binary_char[i] = binary_string[i];
    binary_char[9] = '\0';
    *text = binary_to_ascii(binary_char);
    binary_to_text(binary_string+8, text+1);
  }
}


/* parity function for the sender */
char parity(int &a, int &b, int &c)
{
  return ((a + b + c) % 2) ? '1' : '0';
}


/* parity funtion for the receiver */
char parity(int &a, int &b, int &c, int &d)
{
  return ((a + b + c + d) % 2) ? '1' : '0';
}


/* check parity for the sender bits */
void sender_check_bits(int *four_bits, char &C_1, char &C_2, char &C_3)
{
  C_1 = parity(four_bits[0], four_bits[1], four_bits[3]);
  C_2 = parity(four_bits[0], four_bits[2], four_bits[3]);
  C_3 = parity(four_bits[1], four_bits[2], four_bits[3]);
}


/* check parity for the receiver bits */
void receiver_check_bits(int *seven_bits, char &P_1, char &P_2, char &P_3)
{
  P_1 = parity(seven_bits[3], seven_bits[4], seven_bits[5], seven_bits[6]);
  P_2 = parity(seven_bits[1], seven_bits[2], seven_bits[5], seven_bits[6]);
  P_3 = parity(seven_bits[0], seven_bits[2], seven_bits[4], seven_bits[6]);
}


/* outputs (in the output string parameter corrected) an error-corrected version
 of a data bit stream */
void add_error_correction(const char* data, char* correct)
{
  // If at the end of the array, set sentinel character and return
  if (*data == '\0'){
    *correct = '\0';
    return;
  }
  else {
    int four_bits[4];
    // Get four bits from the data array
    for (int i = 0; i < 4; i++)
      four_bits[i] = (int)(data[i] - '0');
    // Create the check bits
    char C_1, C_2, C_3;
    sender_check_bits(four_bits, C_1, C_2, C_3);
    // Assign the bits to the 7-bit code word
    correct[0] = C_1;
    correct[1] = C_2;
    correct[2] = data[0];
    correct[3] = C_3;
    correct[4] = data[1];
    correct[5] = data[2];
    correct[6] = data[3];
    // Recurse
    return add_error_correction(data+4, correct+7);
  }
}


/* processes and fixes the errors in the given 7 bits and parity values */
bool process_errors(int* seven_bits, char &P_1, char &P_2, char &P_3)
{
  // if all parity values are 0, no errors were found
  if (P_1 == '0' && P_2 == '0' && P_3 == '0')
    return false;
  else {
    // otherwise, one error was found; get decimal location of the error bit
    int error_bit = (int)(P_1-'0')*4 + (int)(P_2-'0')*2 + (int)(P_3-'0') - 1;
    // flip that bit
    if (seven_bits[error_bit] == 1)
      seven_bits[error_bit] = 0;
    else
      seven_bits[error_bit] = 1;
    return true;
  }
}


/* outputs (in the output string parameter decoded) an error-corrected version
of a received bit stream (the input string parameter received); returns the
number of errors corrected */
int decode(char* received, char* decoded)
{
  // Declarations
  int chunks = strlen(received) / 7;
  int seven_bits[7];
  char P_1, P_2, P_3;
  int errors = 0;
  // For each 7-bit chunk
  for (int chunk = 0; chunk < chunks; chunk++){
    // Get seven bits from the 'received' array
    for (int i = 0; i < 7; i++)
      seven_bits[i] = (int)(received[chunk * 7 + i] - '0');
    // Get the parity bits
    receiver_check_bits(seven_bits, P_1, P_2, P_3);
    // Process the errors, and increment 'errors' if any were found
    if (process_errors(seven_bits, P_1, P_2, P_3))
      errors++;
    // Extract the processed bits to the string parameter decoded
    decoded[chunk * 4 + 0] = (char)(seven_bits[2] + '0');
    decoded[chunk * 4 + 1] = (char)(seven_bits[4] + '0');
    decoded[chunk * 4 + 2] = (char)(seven_bits[5] + '0');
    decoded[chunk * 4 + 3] = (char)(seven_bits[6] + '0');
  }
  // Place a sentinel character once done, and return number of errors
  decoded[chunks * 4] = '\0';
  return errors;
}
