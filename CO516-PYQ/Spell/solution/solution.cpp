#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include "../spell.h"
#include "solution.h"

using namespace std;

int frequency(const char* target)
{
  ifstream in ("words.dat");
  if (in.fail()) return 0;

  string entry; int freq;
  while (!in.eof()){
    in >> freq >> entry;
    if (strcmp(entry.c_str(), target) == 0)
      return freq;
  }
  return 0;
}


int edit_distance(const char* a, const char* b)
{
  char cache[MAX_LENGTH][MAX_LENGTH] = {0};
  return edit_distance(a, b, strlen(a), strlen(b), cache);
}


int edit_distance(
  const char* a, const char* b, int i, int j, char cache[MAX_LENGTH][MAX_LENGTH]
){
  // base cases
  if (strcmp(a, b) == 0)
    return 0;
  if (cache[i][j])
    return cache[i][j];
  if (min(i, j) == 0)
    return max(i, j);

  // else, we have to compute :pepehands:
  vector <int> buf;
  int ind = (a[i-1] == b[j-1] ? 0 : 1);
  buf.push_back(edit_distance(a, b, i - 1, j    , cache) + 1);   // insertion
  buf.push_back(edit_distance(a, b, i    , j - 1, cache) + 1);   // deletion
  buf.push_back(edit_distance(a, b, i - 1, j - 1, cache) + ind); // replacement
  if (i > 1 && j > 1 && a[i-1] == b[j-2] && a[i-2] == b[j-1])
    buf.push_back(edit_distance(a, b, i - 2, j - 2, cache) + 1); // transpose

  // cache our results and return
  return cache[i][j] = *min_element(buf.begin(), buf.end());
}


bool spell_correct(const char* word, char* fixed)
{
  ifstream in ("words.dat");
  if (in.fail()) return false;

  pair <int, string> most_common {0, ""};
  int lowest_distance = 0;
  string entry; int freq;

  while (!in.eof()){
    in >> freq >> entry;
    if (strcmp(word, entry.c_str()) == 0)
      return fixed[0] = '\0', false;
    int distance = edit_distance(word, entry.c_str());
    if ((lowest_distance == 0 || distance < lowest_distance) ||
        (distance == lowest_distance && freq > most_common.first)){
      lowest_distance = distance;
      most_common = {freq, entry};
    }
  }
  if (lowest_distance > 2)
    return fixed[0] = '\0', false;
  strcpy(fixed, most_common.second.c_str());
  return true;
}


/* bonus question */
int edit_distance_bonus(const char* a, const char* b, bool reset)
{
  static int cache[MAX_LENGTH][MAX_LENGTH];
  // check if we need to setup the cache
  if (reset)
    for (int r = 0; r < MAX_LENGTH; r++)
      for (int c = 0; c < MAX_LENGTH; c++)
        cache[r][c] = 0;

  // base conditions
  if (strcmp(a, b) == 0)
    return 0;
  if (min(strlen(a), strlen(b)) == 0)
    return max(strlen(a), strlen(b));
  if (cache[strlen(a)][strlen(b)])
    return cache[strlen(a)][strlen(b)];

  // recursive with poitner arithmetics
  vector <int> buf;
  int cost = (a[0] == b[0] ? 0 : 1);
  buf.push_back(edit_distance_bonus(a + 1, b    , false) + 1);    // insertion
  buf.push_back(edit_distance_bonus(a    , b + 1, false) + 1);    // deletion
  buf.push_back(edit_distance_bonus(a + 1, b + 1, false) + cost); // replacement
  if (strlen(a) > 1 && strlen(b) > 1 && a[0] == b[1] && a[1] == b[0])
    buf.push_back(edit_distance_bonus(a + 2, b + 2, false) + 1);  // transpose

  // cache and return
  return cache[strlen(a)][strlen(b)] = *min_element(buf.begin(), buf.end());
}
