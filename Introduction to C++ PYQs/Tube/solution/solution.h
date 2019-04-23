#ifndef SOLUTION_TUBE_H
#define SOLUTION_TUBE_H

#include "../tube.h"

bool get_symbol_position(
  char** map,
  const int height, const int width,
  const char target,
  int &r, int&c
);

char get_symbol_for_station_or_line(const char* name);

int validate_route(
  char** map,
  const int height, const int width,
  const char* start_station, const char* route, char* destination
);

#endif
