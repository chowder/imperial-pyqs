#include <algorithm>
#include <cctype>
#include <cstring>

using namespace std;


/* case insensitive comparator */
bool case_insensitive_comp(char a, char b){
  return toupper(a) < toupper(b);
}


/* a helper function to sort a string */
void sort_string(const char* one, char* one_sorted){
  strcpy(one_sorted, one);
  sort(one_sorted, one_sorted+strlen(one), case_insensitive_comp);
  one_sorted[strlen(one) + 1] = '\0';
}


/* takes str1, reverses it, and outputs to str2 */
void reverse(const char* str1, char* str2){
  int len = strlen(str1);
  for(int i = len; i > 0; i--)
    str2[len-i] = str1[i-1];
  // Add sentinel character
  str2[len] = '\0';
}

/* a recursive function which compares two strings ignoring punctuation and
letter case; returns 1 if they're the same, 0 otherwise */
int compare(const char* one, const char* two){
  // get next letter in string 1 and string 2
  while (!isalpha(one[0]) && one[0] != '\0')
    one += 1;
  while (!isalpha(two[0]) && two[0] != '\0')
    two += 1;
  // reached end of string, identical
  if (one[0] == '\0' && two[0] == '\0')
    return 1;
  // if the characters are not the same
  if (toupper(one[0]) != toupper(two[0]))
    return 0;
  return compare(one+1, two+1);
}

/* a function which returns 1 if the given sentence is a palindrome, and 0
otherwise. */
int palindrome(const char* sentence){
  char reversed[strlen(sentence) + 1];
  reverse(sentence, reversed);
  return compare(sentence, reversed);
}


/* a function which returns 1 if string str1 is an anagram of string str2,
and 0 otherwise */
int anagram(const char* one, const char* two){
  char one_sorted[512], two_sorted[512];
  sort_string(one, one_sorted);
  sort_string(two, two_sorted);
  return compare(one_sorted, two_sorted);
}
