#include "../river.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

char** make_river_scene(string left, string boat)
{
  char** scene = create_scene();
  // static scene objects
  add_to_scene(scene,  0,  0, "bank.txt");
  add_to_scene(scene,  0, 53, "bank.txt");
  add_to_scene(scene,  3, 30, "sun.txt");
  add_to_scene(scene, 19, 19, "river.txt");

  // left bank scene objects
  int l_missionaries = count(left.begin(), left.end(), 'M');
  int l_cannibals = count(left.begin(), left.end(), 'C');
  int l_boat = count(left.begin(), left.end(), 'B');
  for (int m = 0; m < l_missionaries; m++)
    add_to_scene(scene, 2, (m * 6) + 1, "missionary.txt");
  for (int c = 0; c < l_cannibals; c++)
    add_to_scene(scene, 11, (c * 6) + 1, "cannibal.txt");

  // boat scene objects
  int b_missionaries = count(boat.begin(), boat.end(), 'M');
  int b_cannibals = count(boat.begin(), boat.end(), 'C');
  l_boat ? add_to_scene(scene, 17, 19, "boat.txt"):
           add_to_scene(scene, 17, 36, "boat.txt");
  for (int m = 0; m < b_missionaries; m++)
    l_boat ? add_to_scene(scene, 11, (m * 6) + 22, "missionary.txt"):
             add_to_scene(scene, 11, (m * 6) + 39, "missionary.txt");
  for (int c = b_missionaries; c < b_cannibals + b_missionaries; c++)
    l_boat ? add_to_scene(scene, 11, (c * 6) + 22, "cannibal.txt"):
             add_to_scene(scene, 11, (c * 6) + 39, "cannibal.txt");

  // right bank scene objects
  int r_missionaries = 3 - l_missionaries - b_missionaries;
  int r_cannibals = 3 - l_cannibals - b_cannibals;
  for (int m = 0; m < r_missionaries; m++)
    add_to_scene(scene, 2, (m * 6) + 54, "missionary.txt");
  for (int c = 0; c < r_cannibals; c++)
    add_to_scene(scene, 11, (c * 6) + 54, "cannibal.txt");
  return scene;
}


Status perform_crossing(char* left , string target)
{
  char** scene;
  string left_str = left;
  bool boat_at_left = (left_str.find('B') != string::npos);
  if (target.size() < 1 || target.size() > 2)
    return ERROR_INVALID_MOVE;

  if (boat_at_left)
    for (char person: target){
      int pos = left_str.find(person);
      if (pos == string::npos)
        return ERROR_INVALID_MOVE;
      else
        left_str.erase(left_str.find(person), 1);
    }

  if (!boat_at_left){
    int total_missionary = count(left_str.begin(), left_str.end(), 'M') +
                           count(target.begin(), target.end(), 'M');
    int total_cannibal = count(left_str.begin(), left_str.end(), 'C') +
                         count(target.begin(), target.end(), 'C');
    if (total_missionary > 3 || total_cannibal > 3)
      return ERROR_INVALID_MOVE;
  }

  // Performing crossing sequence
  cout << "Loading the boat..." << endl;
  scene = make_river_scene(left_str, target);
  print_scene(scene);
  destroy_scene(scene);

  cout << "Crossing the river..." << endl;
  boat_at_left ? left_str.erase(left_str.find('B'), 1):
                 left_str += 'B';
  scene = make_river_scene(left_str, target);
  print_scene(scene);
  destroy_scene(scene);

  cout << "Unloading the boat..." << endl;
  if (!boat_at_left)
    left_str += target;
  scene = make_river_scene(left_str, "");
  print_scene(scene);
  destroy_scene(scene);

  strcpy(left, left_str.c_str());

  // Evaluate the ending
  int l_missionaries = count(left_str.begin(), left_str.end(), 'M');
  int l_cannibals = count(left_str.begin(), left_str.end(), 'C');
  if (l_cannibals != l_missionaries &&
     (l_missionaries != 3 && l_missionaries != 0))
    return ERROR_MISSIONARIES_EATEN;
  if (l_missionaries + l_cannibals == 0)
    return VALID_GOAL_STATE;

  return VALID_NONGOAL_STATE;
}


Status play_game()
{
  Status ret = VALID_NONGOAL_STATE;
  string target;

  char left[10] = "MMMCCCB";
  cout << "A new game has started!" << endl;
  char** scene = make_river_scene(left, "");
  print_scene(scene);
  destroy_scene(scene);

  while (ret == VALID_NONGOAL_STATE){
    cout << "Please enter a crossing: ";
    cin >> target;
    ret = perform_crossing(left, target);
  }
  return ret;
}


Status find_solution(char* left, char* answer, string last_move)
{
  string moves[5] = {"MM", "MC", "CC", "M", "C"};
  for (string move: moves){
    // To avoid repeating moves
    if (last_move.compare(move) == 0)
      continue;
    // Cache the old game state
    char buf[10];
    strcpy(buf, left);
    // Perform move
    Status ret = perform_crossing(buf, move);
    strcpy(answer, move.c_str());
    // Recursion
    if (ret == VALID_GOAL_STATE)
      return VALID_GOAL_STATE;
    if (ret == VALID_NONGOAL_STATE){
      strcat(answer, ", ");
      if (find_solution(buf, answer + strlen(answer)) == VALID_GOAL_STATE)
        return VALID_GOAL_STATE;
    }
  }
  return ERROR_BONUS_NO_SOLUTION;
}
