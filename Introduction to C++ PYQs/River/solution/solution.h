#ifndef RIVER_SOLUTION_H
#define RIVER_SOLUTION_H

#include <string>

char** make_river_scene(std::string left, std::string boat);

Status perform_crossing(char* left , std::string target);

Status play_game();

Status find_solution(char* left, char* answer, std::string last_move = "");

#endif
