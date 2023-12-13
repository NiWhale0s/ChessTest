#pragma once
#include <iostream>

using namespace std;

const string pieces_name[5] = { "king", "queen", "rook", "bishop", "knight" };
const string chessboard_names[8] = { "a" , "b", "c", "d", "e", "f", "g", "h" };

class Piece
{
private:
	virtual int Cheking_for_position_piece(int x, int y, int chessboard[8][8]) const = 0;
public:
	virtual void Piece_Draw() const = 0;
	virtual void Beat_Check(int chessboard[8][8]) const = 0;
	virtual void insideGotoXY(short x, short y) const = 0;
};

