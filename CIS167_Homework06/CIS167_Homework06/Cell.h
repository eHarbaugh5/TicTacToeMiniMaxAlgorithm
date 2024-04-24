#pragma once
#include "iostream"
#include "string"

using namespace std;


class Cell
{

	private:
		int value;
		string piece;
	public:
		Cell();
		Cell(string);

		string getPiece();
		void setPiece(string);

	



};

