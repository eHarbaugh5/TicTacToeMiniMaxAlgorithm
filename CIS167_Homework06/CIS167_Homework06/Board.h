#pragma once
#include "Cell.h"
using namespace std;


class Board
{

	private:
		Cell gameBoard[3][3];
	public:
		Board();
		//Board(Cell a, Cell b, Cell c, Cell d, Cell e, Cell f, Cell g, Cell h, Cell i);
		void addPiece(int, int, string);
		string getBoardPiece(int, int);
		bool canPlacePiece(int, int);
		bool boardIsFull();
		//bool checkOpenSpot(int, int);
		string checkForWinner();


};

