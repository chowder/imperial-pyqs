/* HELPER FUNCTIONS */
#include <string>
#include <vector>

enum MoveResult {
  INVALID_MOVE = -3,
  REDUNDANT_MOVE = -2,
  BLOWN_UP = -1,
  SOLVED_BOARD = 1,
  VALID_MOVE = 0
};

enum MoveType {
  REVEAL,
  FLAG,
  INVALID
};

void display_board(char board[9][9]);
void load_board(const char *filename, char board[9][9]);
void initialise_board(char board[9][9]);

// Define your own functions here
bool is_complete(char mines[9][9], char revealed[9][9]);
int count_mines(std::string position, char mines[9][9]);
MoveResult make_move(std::string position, char mines[9][9], char board[9][9]);
bool find_safe_move(char revealed[9][9], char move[2]);

// Self-made helper functions
MoveType get_move_type(std::string position);
std::pair<int, int> string_to_ints(std::string position);
std::string ints_to_string(int x, int y);
std::vector <std::string> get_all_neighbours(std::string position);
std::vector <std::string> get_all_positions();
std::string get_first_unknown(std::string position, char board[9][9]);
