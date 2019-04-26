#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <string>

bool get_items(const char* filename, char* items);

int item_weight(const char* filename, char item);

int insert_knapsack(int capacity, char item, const char* filename);

int fill_knapsack(
  int capacity, char* items, const char* filename
);

int bonus_fill_knapsack(
  int capacity, char* items, std::string &knapsack, const char* filename
);

#endif
