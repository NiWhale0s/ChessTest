#include "Rook.h"
#include "Piece.h"
#include <Windows.h>
#include <io.h>
#include <fcntl.h>

Rook::Rook(string new_name, int new_x, int new_y) : piece_name(new_name), x(new_x), y(new_y) {}

void Rook::insideGotoXY(short x, short y) const
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Rook::Piece_Draw() const
{
    insideGotoXY(4 + 6 * x, 3 + 3 * y);
    cout << "roo";
}


int Rook::Cheking_for_position_piece(int x, int y, int chessboard[8][8]) const
{

    if (chessboard[y][x] != -1) {
        cout << "Rook beats " << pieces_name[chessboard[y][x]] << " [" << chessboard_names[x] << ", " << 7 - y + 1 << " ]" << endl;
        return 1;
    }

    return 0;
}


void Rook::Beat_Check(int chessboard[8][8]) const
{


    int check = 0;
    int temp = 0;
    cout << endl << "Rook" << " [" << chessboard_names[x] << ", " << 7 - y + 1 << " ]" << endl;
    for (int i = x + 1; i < 8; i++) {
        check += Rook::Cheking_for_position_piece(i, y, chessboard);
        if (check == 1) {
            check = 0;
            temp += 1;
            break;
        }
    }

    for (int i = y + 1; i < 8; i++) {
        check += Rook::Cheking_for_position_piece(x, i, chessboard);
        if (check == 1) {
            check = 0;
            temp += 1;
            break;
        }
    }

    for (int i = x - 1; i >= 0; i--) {
        check += Rook::Cheking_for_position_piece(i, y, chessboard);
        if (check == 1) {
            check = 0;
            temp += 1;
            break;
        }
    }

    for (int i = y - 1; i >= 0; i--) {
        check += Rook::Cheking_for_position_piece(x, i, chessboard);
        if (check == 1) {
            check = 0;
            temp += 1;
            break;
        }
    }

    if (temp == 0) {
        cout << "The rook does not capture a piece" << endl;
    }
    cout << endl;
}