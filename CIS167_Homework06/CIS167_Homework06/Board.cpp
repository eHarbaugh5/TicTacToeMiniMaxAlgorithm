#include "Board.h"


Board::Board()
{


	for (int i = 0; i < 3; i++)
	{

		for (int j = 0; j < 3; j++)
		{

			//addPiece(i, j, "-"); 
			addPiece(i, j, to_string(((j * 3) + i)));
		}
	}
	
}
void Board::addPiece(int x, int y, string p)
{
	if (getBoardPiece(x, y) != "O" && getBoardPiece(x, y) != "X")
	{
		gameBoard[x][y].setPiece(p);
	}
	
}
string Board::getBoardPiece(int a, int b)
{
	return gameBoard[a][b].getPiece();
}
bool Board::canPlacePiece(int one, int two)
{
	
	if (getBoardPiece(one, two) != "O" && getBoardPiece(one, two) != "X")
	{
		return true;
	}
	return false;
	
}
string Board::checkForWinner()
{

	bool threeInRow = false;
	string winnerCheck;
	string currentCheck;

	//  Horizontal Check
	for (int i = 0; i < 3; i++)
	{
		winnerCheck = getBoardPiece(0, i);
		if (winnerCheck == "X" || winnerCheck == "O")
		{
			threeInRow = true;
			for (int j = 0; j < 3; j++)
			{
				currentCheck = getBoardPiece(j, i);
				if (currentCheck != winnerCheck)
				{
					threeInRow = false;
				}
			}
		}
		if (threeInRow)
		{
			return winnerCheck;
		}
		
	}

	//  Vertical Check
	for (int i = 0; i < 3; i++)
	{
		winnerCheck = getBoardPiece(i, 0);
		if (winnerCheck == "X" || winnerCheck == "O")
		{
			threeInRow = true;
			for (int j = 0; j < 3; j++)
			{
				currentCheck = getBoardPiece(i, j);
				if (currentCheck != winnerCheck)
				{
					threeInRow = false;
				}
			}
		}
		if (threeInRow)
		{
			return winnerCheck;
		}

	}

	//  Down left Diagonal
	winnerCheck = getBoardPiece(0, 0);
	if (winnerCheck == "X" || winnerCheck == "O")
	{
		threeInRow = true;
		for (int j = 0, i = 0; j < 3; j++, i++)
		{
			currentCheck = getBoardPiece(i, j);
			if (currentCheck != winnerCheck)
			{
				threeInRow = false;
			}
		}
	}
	if (threeInRow)
	{
		return winnerCheck;
	}

	//  up right Diagonal
	winnerCheck = getBoardPiece(0, 2);
	if (winnerCheck == "X" || winnerCheck == "O")
	{
		threeInRow = true;
		for (int j = 2, i = 0; j > -1; j--, i++)
		{
			currentCheck = getBoardPiece(i, j);
			if (currentCheck != winnerCheck)
			{
				threeInRow = false;
			}
		}
	}
	if (threeInRow)
	{
		return winnerCheck;
	}

	return "n";

}


	


	