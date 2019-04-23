#include "../tube.h"
#include <fstream>
#include <cstring>
#include <string>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

bool get_symbol_position(
  char** map,
  const int height, const int width,
  const char target,
  int &r, int&c
){
  for (int row = 0; row < height; row++)
    for (int col = 0; col < width; col++)
      if (map[row][col] == target)
        return r = row, c = col, true;
  return r = -1, c = -1, false;
}


char get_symbol_for_station_or_line(const char* name){
  static map<string, char> cache;
  // check the cache
  if (cache.find(name) != cache.end())
    return cache.find(name)->second;
  // checking lines file
  ifstream lines_stream ("lines.txt");
  string line;
  while (!lines_stream.eof()){
    getline(lines_stream, line);
    if (strcmp(name, line.c_str() + 2) == 0)
      return cache[name] = line[0];
  }
  // checking stations file
  ifstream stations_stream ("stations.txt");
  while (!stations_stream.eof()){
    getline(stations_stream, line);
    if (strcmp(name, line.c_str() + 2) == 0)
      return cache[name] = line[0];
  }
  return ' ';
}


void apply_direction(Direction direction, int &row, int &col){
  switch (direction) {
  case N:
    row -= 1; break;
  case S:
    row += 1; break;
  case E:
    col += 1; break;
  case W:
    col -= 1; break;
  case NE:
    row -= 1, col += 1; break;
  case SE:
    row += 1, col += 1; break;
  case SW:
   row += 1, col -= 1; break;
  case NW:
    row -= 1, col -= 1; break;
  default:
    return;
  }
}


void get_station_name(const char symbol, char* destination){
  static map<char, string> cache;
  // checking the cache
  if (cache.find(symbol) != cache.end()){
    strcpy(destination, cache[symbol].c_str());
    return;
  }
  // checking stations file
  ifstream stations_stream ("stations.txt");
  string line;
  while (!stations_stream.eof()){
    getline(stations_stream, line);
    if (symbol == line[0]){
      cache[symbol] = (line.c_str() + 2);
      strcpy(destination, cache[symbol].c_str());
      return;
    }
  }
}


Direction opposite_direction(Direction direction){
  switch (direction) {
  case N:
    return S;
  case E:
    return W;
  case S:
    return N;
  case W:
    return E;
  case NE:
    return SW;
  case SE:
    return NW;
  case SW:
    return NE;
  case NW:
    return SE;
  default:
    return INVALID_DIRECTION;
  }
}


int validate_route(
  char** map,
  const int height, const int width,
  const char* start_station, const char* route, char* destination
){
  // get start symbol
  char start_symbol = get_symbol_for_station_or_line(start_station);
  if (start_symbol == ' ')
    return ERROR_START_STATION_INVALID;
  // get start location
  int row, col;
  if (!get_symbol_position(map, height, width, start_symbol, row, col))
    return ERROR_START_STATION_INVALID;

  // declaring shit
  stringstream ss(route);
  string dir;
  Direction previous_dir = INVALID_DIRECTION;
  char previous_position = map[row][col];
  char previous_line = ' ';
  int changes = 0;

  while (getline(ss, dir, ',')){
    // check if given input direction is valid
    Direction direction = string_to_direction(dir.c_str());
    if (direction == INVALID_DIRECTION)
      return ERROR_INVALID_DIRECTION;
    // apply direction and check bounds
    apply_direction(direction, row, col);
    if (row < 0 || col < 0 || row > height || col > width)
      return ERROR_OUT_OF_BOUNDS;
    // check if route is off track
    if (map[row][col] == ' ')
      return ERROR_OFF_TRACK;
    // check if it is changing lines outside
    if (!isalnum(previous_position) && !isalnum(map[row][col]) &&
        map[row][col] != previous_position)
      return ERROR_LINE_HOPPING_BETWEEN_STATIONS;
    // check if it is backtracking
    if (previous_dir == opposite_direction(direction))
      return ERROR_BACKTRACKING_BETWEEN_STATIONS;
    // all good, we can move now
    if (!isalnum(map[row][col]) && map[row][col] != previous_line){
      previous_line = map[row][col];
      changes++;
    }
    previous_dir = direction;
    previous_position = map[row][col];
  }
  if (!isalnum(map[row][col]))
    return ERROR_ROUTE_ENDPOINT_IS_NOT_STATION;
  get_station_name(map[row][col], destination);
  // we decrement the result here because getting on the first line constituted
  // as a "line change"
  return --changes;
}
