#include "minesweeper.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;

/* HELPER FUNCTIONS */
void display_board(char board[9][9]){
  cout << "   123456789" << endl;
  cout << "  +---------+" << endl;
  for (int row = 0; row < 9; row++){
    cout << (char)('A' + row) << " |";
    for (int col = 0; col < 9; col++)
      cout << (board[row][col] == '.' ? ' ' : board[row][col]);
    cout << "|" << endl;
  }
  cout << "  +---------+" << endl;
}

void load_board(const char *filename, char board[9][9]){
	ifstream in_stream(filename);
	if (in_stream.fail()){
		cout << "Could not open file!" << endl;
		return;
	}
  char temp;
	for (int row = 0; row < 9; row++)
		for (int col = 0; col < 9; col++)
			do {
        board[row][col] = in_stream.get();
      } while (board[row][col] == '\n');
}

void initialise_board(char board[9][9]){
  for (int row = 0; row < 9; row++)
    for (int col = 0; col < 9; col++)
      board[row][col] = '?';
}

// Define your own functions here
bool is_complete(char mines[9][9], char revealed[9][9]){
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if (mines[i][j] != '*' && revealed[i][j] == '?')
        return false;
  return true;
}

int count_mines(string position, char mines[9][9]){
  pair<int, int> parsed = string_to_ints(position);
  int count = 0;
  for (int row = parsed.first-1; row <= parsed.first+1; row++){
    for (int col = parsed.second-1; col <= parsed.second+1; col++){
      if (row < 0 || row > 8 || col < 0 || col > 8)
        continue;
      if (row == position[0] && col == position[1])
        continue;
      if (mines[row][col] == '*')
        count++;
    }
  }
  return count;
}


int count_unknowns(string position, char mines[9][9]){
  pair<int, int> parsed = string_to_ints(position);
  int count = 0;
  for (int row = parsed.first-1; row <= parsed.first+1; row++){
    for (int col = parsed.second-1; col <= parsed.second+1; col++){
      if (row < 0 || row > 8 || col < 0 || col > 8)
        continue;
      if (row == position[0] && col == position[1])
        continue;
      if (mines[row][col] == '?')
        count++;
    }
  }
  return count;
}


MoveResult make_move(string position, char mines[9][9], char board[9][9]){
  // Safety checks
  MoveType ret = get_move_type(position);
  if (ret == INVALID)
    return INVALID_MOVE;
  pair<int, int> parsed = string_to_ints(position);
  if (board[parsed.first][parsed.second] != '?')
    return REDUNDANT_MOVE;
  if (ret != FLAG && mines[parsed.first][parsed.second] == '*')
    return BLOWN_UP;
  // Actually make the move
  if (ret == FLAG)
    board[parsed.first][parsed.second] = '*';
  else {
    int num_mines = count_mines(position, mines);
    if (num_mines)
      board[parsed.first][parsed.second] = num_mines + '0';
    else {
      board[parsed.first][parsed.second] = ' ';
      vector <string> neighbours = get_all_neighbours(position);
      for (string neighbour: neighbours)
        make_move(neighbour, mines, board);
    }
  }
  return VALID_MOVE;
}


bool find_safe_move(char revealed[9][9], char move[2]){
  vector <string> positions = get_all_positions();
  for (string position: positions){
    pair<int, int> parsed = string_to_ints(position);
    // count the amount of unknowns and mines around that square
    int num_unknowns = count_unknowns(position, revealed);
    int num_flags = count_mines(position, revealed);
    int total = num_unknowns + num_flags;
    // condition to return a flag
    if (isdigit(revealed[parsed.first][parsed.second]) &&
        revealed[parsed.first][parsed.second] == (total + '0') &&
        num_unknowns > 0){
      string pos = get_first_unknown(position, revealed);
      move[0] = pos[0];
      move[1] = pos[1];
      move[2] = '*';
      move[3] = '\0';
      return true;
    }
    // condition to return a reveal
    if (isdigit(revealed[parsed.first][parsed.second]) &&
        revealed[parsed.first][parsed.second] == (num_flags + '0') &&
        num_unknowns > 0){
      string pos = get_first_unknown(position, revealed);
      move[0] = pos[0];
      move[1] = pos[1];
      move[2] = '\0';
      return true;
    }
  }
  return false;
}

// Self-defined helper functions

pair<int, int> string_to_ints(string position){
  pair<int, int> parsed = {position[0] - 'A', position[1] - '1'};
  return parsed;
}


string ints_to_string(int x, int y){
  char row = x + 'A';
  char col = y + '1';
  string parsed = {row, col};
  return parsed;
}


MoveType get_move_type(string position){
  if (position.size() > 3 || position.size() < 2)
    return INVALID;
  else if (position[0] < 'A' || position[0] > 'I' ||
           position[1] < '1' || position[1] > '9')
    return INVALID;
  else if (position.size() == 3)
    return (position[2] == '*' ? FLAG : INVALID);
  else
    return REVEAL;
}


vector <string> get_all_neighbours(string position){
  vector <string> neighbours;
  for (char row = position[0] - 1; row <= position[0] + 1; row++)
    for (char col = position[1] - 1; col <= position[1] +1; col++){
      if (row < 'A' || row > 'I' || col < '1' || col > '9')
        continue;
      if (row == position[0] && col == position[1])
        continue;
      neighbours.push_back({row, col});
    }
  return neighbours;
}


vector <string> get_all_positions(){
  vector <string> positions;
  for (char row = 'A'; row <= 'I'; row++)
    for (char col = '1'; col <= '9'; col++)
      positions.push_back({row, col});
  return positions;
}


string get_first_unknown(string position, char board[9][9]){
  vector <string> neighbours = get_all_neighbours(position);
  for (string neighbour: neighbours){
    pair <int, int> parsed = string_to_ints(neighbour);
    if (board[parsed.first][parsed.second] == '?')
      return neighbour;
  }
  // Just to make the compiler shut up
  return "";
}
