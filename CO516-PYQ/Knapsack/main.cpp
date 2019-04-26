#include <iostream>
#include "knapsack.h"

using namespace std;

int main(){
  // Question 1
  cout << "====================== Question 1 ======================" << endl << endl;

  char items[512];
  if (get_items("items.txt", items))
    cout << "The items in 'items.txt' are " << items;
  else
    cout << "Invalid file given.";
  cout << endl;

  if (get_items("doesnotexist.txt", items))
    cout << "The items in 'doesnotexist.txt' are " << items;
  else
    cout << "Invalid file given.";
  cout << endl << endl;

  // Question 2
  cout << "====================== Question 2 ======================" << endl << endl;

  int weight;
  // should return 4
  weight = item_weight("items.txt", 'A');
  if (weight)
    cout << "Item A has weight " << weight;
  else
    cout << "Item A was not found.";
  cout << endl;

  // should return 21
  weight = item_weight("items.txt", 'B');
  if (weight)
    cout << "Item B has weight " << weight;
  else
    cout << "Item B was not found.";
  cout << endl;

  // should return not found
  weight = item_weight("items.txt", 'Z');
  if (weight)
    cout << "Item Z has weight " << weight;
  else
    cout << "Item Z was not found.";
  cout << endl << endl;

  // Question 3
  cout << "====================== Question 3 ======================" << endl << endl;

  int capacity;
  // should return 16
  capacity = insert_knapsack(20, 'A', "items.txt");
  cout << "Item A will" << (capacity == -1 ? " NOT" : "");
  cout << " fit into a knapsack of size 20. ";
  if (capacity != -1)
    cout << "With leftover weight " << capacity;
  cout << endl;

  // should not fit
  capacity = insert_knapsack(20, 'B', "items.txt");
  cout << "Item B will" << (capacity == -1 ? " NOT" : "");
  cout << " fit into a knapsack of size 20. ";
  if (capacity != -1)
    cout << "With leftover weight " << capacity;
  cout << endl;

  // should return 6
  capacity = insert_knapsack(20, 'C', "items.txt");
  cout << "Item C will" << (capacity == -1 ? " NOT" : "");
  cout << " fit into a knapsack of size 20. ";
  if (capacity != -1)
    cout << "With leftover weight " << capacity;
  cout << endl;

  // should not fit (since not found)
  capacity = insert_knapsack(20, 'Z', "items.txt");
  cout << "Item Z will" << (capacity == -1 ? " NOT" : "");
  cout << " fit into a knapsack of size 20. ";
  if (capacity != -1)
    cout << "With leftover weight " << capacity;
  cout << endl << endl;

  // Question 4
  cout << "====================== Question 4 ======================" << endl << endl;

  int space;
  get_items("items.txt", items);

  // should return 3 (D)
  space = fill_knapsack(10, items, "items.txt");
  cout << "Knapsack of capacity 10 can be filled with leftover space " << space;
  cout << endl;

  // should return 1 (DE)
  space = fill_knapsack(20, items, "items.txt");
  cout << "Knapsack of capacity 20 can be filled with leftover space " << space;
  cout << endl;

  // should return 0 (ACE)
  space = fill_knapsack(30, items, "items.txt");
  cout << "Knapsack of capacity 30 can be filled with leftover space " << space;
  cout << endl;

  // should return 0 (BDE)
  space = fill_knapsack(40, items, "items.txt");
  cout << "Knapsack of capacity 40 can be filled with leftover space " << space;
  cout << endl;

  // should return 3 (BCE)
  space = fill_knapsack(50, items, "items.txt");
  cout << "Knapsack of capacity 40 can be filled with leftover space " << space;
  cout << endl;

  // should return 2 (ABCDE)
  space = fill_knapsack(60, items, "items.txt");
  cout << "Knapsack of capacity 40 can be filled with leftover space " << space;
  cout << endl << endl;

  // Bonus Question
  cout << "====================== Bonus Question ======================" << endl << endl;

  string knapsack;
  space = bonus_fill_knapsack(10, items, knapsack, "items.txt");
  cout << "Knapsack of capacity 10 can be filled with " << knapsack;
  cout << " to achieve leftover space " << space;
  cout << endl;

  knapsack.clear();
  space = bonus_fill_knapsack(20, items, knapsack, "items.txt");
  cout << "Knapsack of capacity 20 can be filled with " << knapsack;
  cout << " to achieve leftover space " << space;
  cout << endl;

  knapsack.clear();
  space = bonus_fill_knapsack(30, items, knapsack, "items.txt");
  cout << "Knapsack of capacity 30 can be filled with " << knapsack;
  cout << " to achieve leftover space " << space;
  cout << endl;

  knapsack.clear();
  space = bonus_fill_knapsack(40, items, knapsack, "items.txt");
  cout << "Knapsack of capacity 40 can be filled with " << knapsack;
  cout << " to achieve leftover space " << space;
  cout << endl;

  knapsack.clear();
  space = bonus_fill_knapsack(50, items, knapsack, "items.txt");
  cout << "Knapsack of capacity 50 can be filled with " << knapsack;
  cout << " to achieve leftover space " << space;
  cout << endl;

  knapsack.clear();
  space = bonus_fill_knapsack(60, items, knapsack, "items.txt");
  cout << "Knapsack of capacity 60 can be filled with " << knapsack;
  cout << " to achieve leftover space " << space;
  cout << endl << endl;
}
