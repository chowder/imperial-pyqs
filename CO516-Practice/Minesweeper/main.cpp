#include "minesweeper.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){

  cout << "-----------------------------------------" << endl;
	cout << " QUESTION ONE - Testing helper functions " << endl;
	cout << "-----------------------------------------" << endl;

	char mines[9][9], revealed[9][9];
	load_board("mines.dat", mines);
	display_board(mines);
	cout << "Calling initialise_board()..." << endl;
	initialise_board(revealed);
	display_board(revealed);

	cout << "-----------------------------------------" << endl;
	cout << " QUESTION ONE - is_complete() " << endl;
	cout << "-----------------------------------------" << endl;

	load_board("mines.dat", mines);
	load_board("solution.dat", revealed);
	cout << "solution.dat is ";
	if (!is_complete(mines, revealed))
		cout << "NOT ";
	cout << "complete." << endl;

	load_board("partial.dat", revealed);
	cout << "partial.dat is ";
	if (!is_complete(mines, revealed))
		cout << "NOT ";
	cout << "complete." << endl;

	cout << "-----------------------------------------" << endl;
	cout << " QUESTION TWO - count_mines() " << endl;
	cout << "-----------------------------------------" << endl;

	load_board("mines.dat", mines);
	display_board(mines);
	cout << "Found " << count_mines("A7", mines)
			 << " mine(s) around square 'A7'" << endl;
	cout << "Found " << count_mines("E5", mines)
		 	 << " mine(s) around square 'E5'" << endl;
  cout << "Found " << count_mines("H9", mines)
			 << " mine(s) around square 'H9'" << endl;

	cout << "-----------------------------------------" << endl;
	cout << " QUESTION THREE - make_move() " << endl;
 	cout << "-----------------------------------------" << endl;

 	load_board("mines.dat", mines);
 	initialise_board(revealed);
 	MoveResult result1 = make_move("B6", mines, revealed);
	display_board(revealed);
	MoveResult result2 = make_move("E5", mines, revealed);
	display_board(revealed);
	MoveResult result3 = make_move("H3*", mines, revealed);
	display_board(revealed);

	cout << "-----------------------------------------" << endl;
	cout << " QUESTION FOUR - find_safe_move() " << endl;
 	cout << "-----------------------------------------" << endl;

 	load_board("mines.dat", mines);
 	load_board("partial.dat", revealed);
	display_board(revealed);

	cout << "Safe move sequence: " << endl;
	char move[512];
	while (find_safe_move(revealed, move)){
		cout << move << " ";
		make_move(move, mines, revealed);
	}
	cout << endl;
	display_board(revealed);

	cout << "The board is ";
	if (!is_complete(mines, revealed))
		cout << "NOT ";
	cout << "complete." << endl;
}
