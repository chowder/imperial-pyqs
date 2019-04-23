#include <string>
#include <iostream>
#include <cassert>
#include <map>

using namespace std;

bool find_marker(
  char ch, char** maze, int height, int width, int &row, int &column)
{
  for (int r = 0; r < height; r++)
    for (int c = 0; c < width; c++)
      if (maze[r][c] == ch)
        return row = r, column = c, true;
  return row = -1, column = -1, false;
}


bool valid_solution(string path, char** maze, int height, int width)
{
  int start_row, start_col, end_row, end_col;
  assert(find_marker('>', maze, height, width, start_row, start_col));
  assert(find_marker('X', maze, height, width, end_row, end_col));
  for (char &step: path){
    switch(step){
      case 'N':
        if (--start_row < 0) return false;
        break;
      case 'S':
        if (++start_row > height) return false;
        break;
      case 'E':
        if (++start_col > width) return false;
        break;
      case 'W':
        if (--start_col < 0) return false;
        break;
    }
    if (&step == &path[path.size()-1] && maze[start_row][start_col] == 'X')
      return true;
    else if (maze[start_row][start_col] != ' ')
      return false;
  }
}


bool explore_path(char** maze, int height, int width, char row, char col,
  string &path, char end)
{
  int directions[4][3] = {
    {-1, 0, 'N'}, {0, 1, 'E'}, {1, 0, 'S'}, {0, -1, 'W'}
  };

  for (int* direction: directions){
    int new_row = row + direction[0];
    int new_col = col + direction[1];
    if (new_row < 0 || new_col < 0 || new_row > height || new_col > width)
      continue;

    if (maze[new_row][new_col] == ' '){
      maze[new_row][new_col] = '#';
      path += direction[2];
      if (explore_path(maze, height, width, new_row, new_col, path, end))
        return true;
      path.pop_back(), maze[new_row][new_col] = ' ';
      continue;
    }
    if (maze[new_row][new_col] == end)
      return maze[new_row][new_col] = '#', true;
  }
  return false;
}


string find_path(char** maze, int height, int width, char start, char end){
  string path;
  int start_row, start_col;
  find_marker(start, maze, height,width, start_row, start_col);
  maze[start_row][start_col] = '#';
  if (explore_path(maze, height, width, start_row, start_col, path, end))
    return path;
  maze[start_row][start_col] = start;
  return "no solution";
}
