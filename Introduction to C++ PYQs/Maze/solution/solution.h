#include <string>

bool find_marker(
  char ch, char** maze, int height, int width, int &row, int &column
);


bool valid_solution(
  std::string path, char** maze, int height, int width
);


std::string find_path(
  char** maze, int height, int width, char start, char end
);


bool explore_path(
  char** maze, int height, int width, char row, char col, std::string &path,
  char end
);
