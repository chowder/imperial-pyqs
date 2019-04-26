#include <cstring>
using namespace std;

/* returns true if its first string argument is a prefix of its second string
 * argument */
bool is_prefix(const char* a, const char* b)
{
  return *a == '\0' ? true  :
         *a != *b   ? false :
                      is_prefix(a+1, b+1);
}


/* a function which returns the start position of the first instance
 * of the substring, a, in the string, b, otherwise it returns -1. */
int substring_position(const char* a, const char* b, int count)
{
  return *a == '\0'      ?     0 :    // search complete
         *b == '\0'      ?    -1 :    // b was shorter than a
         is_prefix(a, b) ? count :    // found the start of string a
                           substring_position(a, b+1, count++);
}


/* does the same thing as substring_position but with *magic*
 * NOTE: fits the challenge of 29 characters or less */
int substring_position2(const char* a, const char* b)
{
  return(a=strstr(b,a))?a-b:-1;
}
