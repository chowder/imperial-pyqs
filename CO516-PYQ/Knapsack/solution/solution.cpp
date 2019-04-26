#include <fstream>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

bool get_items(const char* filename, char* items)
{
  ifstream in (filename);
  if (in.fail()) return false;

  char entry;
  int weight, i = 0;
  while (in >> entry >> weight, !in.eof())
    items[i++] = entry;
  items[i] = '\0';
  return true;
}


int item_weight(const char* filename, char item)
{
  ifstream in (filename);
  char entry;
  int weight;
  while (in >> entry >> weight, !in.eof())
    if (entry == item)
      return weight;
  return 0;
}


int insert_knapsack(int capacity, char item, const char* filename)
{
  int weight = item_weight(filename, item);
  if (weight == 0)
    return -1;
  else if (weight <= capacity)
    return capacity - weight;
  else
    return -1;
}


int fill_knapsack(
  int capacity, char* items, const char* filename
){
  // base cases
  if (strlen(items) == 0 || capacity == 0)
    return capacity;

  // check if the item is too big
  int new_capacity = insert_knapsack(capacity, items[0], filename);
  // if it is, we have no choice but to skip it
  if (new_capacity < 0)
    return fill_knapsack(capacity, items+1, filename);

  // otherwise we evaluate leaving and taking, and take the choice that leaves
  // the least space
  else {
    int take = fill_knapsack(new_capacity, items+1, filename);
    int leave = fill_knapsack(capacity, items+1, filename);
    return (take < leave) ? take : leave;
  }
}


int bonus_fill_knapsack(
  int capacity, char* items, string &knapsack, const char* filename
){
  string knapsack_dummy_1 = knapsack;
  string knapsack_dummy_2 = knapsack;

  // base cases
  if (strlen(items) == 0 || capacity == 0)
    return capacity;

  // check if its too big
  int new_capacity = insert_knapsack(capacity, items[0], filename);
  if (new_capacity < 0)
    return bonus_fill_knapsack(capacity, items+1, knapsack, filename);

  // otherwise evaluate leaving and taking
  else {
    knapsack_dummy_1 += items[0];
    int take = bonus_fill_knapsack(new_capacity, items+1, knapsack_dummy_1, filename);
    int leave = bonus_fill_knapsack(capacity, items+1, knapsack_dummy_2, filename);
    if (take < leave){
      knapsack = knapsack_dummy_1;
      return take;
    }
    else {
      knapsack = knapsack_dummy_2;
      return leave;
    }
  }
}
