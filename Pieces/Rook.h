#pragma once
#include "Piece.h"

class Rook : public Piece
{
private:
	string piece_name;
	int x;
	int y;
	int Cheking_for_position_piece(int x, int y, int chessboard[8][8]) const override;
public:
	Rook(string new_name, int new_x, int new_y);

	void Piece_Draw() const override;
	void Beat_Check(int chessboard[8][8]) const override;
	void insideGotoXY(short x, short y) const override;
};

