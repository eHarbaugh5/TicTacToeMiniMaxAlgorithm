#include "Cell.h"

Cell::Cell()
{
	piece = "";
}
Cell::Cell(string p)
{
	piece = p;
}

string Cell::getPiece()
{
	return piece;
}
void Cell::setPiece(string newPiece)
{
	piece = newPiece;
}