#ifndef CORRECT_H
#define CORRECT_H

void ascii_to_binary(char letter, char *output);
char binary_to_ascii(char *binary);
void text_to_binary(const char *string, char *binary);
void binary_to_text(const char* binary_string, char *text);
void add_error_correction(const char* data, char* correct);
int decode(char* received, char* decoded);

#endif
