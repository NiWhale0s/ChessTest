#include "King.h"
#include "Piece.h"
#include <Windows.h>
#include <io.h>
#include <fcntl.h>


King::King(string new_name, int new_x, int new_y) : piece_name(new_name), x(new_x), y(new_y) {}

void King::insideGotoXY(short x, short y) const
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void King::Piece_Draw() const
{
    insideGotoXY(4 + 6 * x, 3 + 3 * y);
    cout << "kin";
}


int King::Cheking_for_position_piece(int x, int y, int chessboard[8][8]) const
{
    if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
        if (chessboard[y][x] != -1) {
            cout << "King beats " << pieces_name[chessboard[y][x]] << " [" << chessboard_names[x] << ", " << 7 - y + 1 << " ]" << endl;
            return 1;
        }
    }
    return 0;
}


void King::Beat_Check(int chessboard[8][8]) const
{
    cout << endl << "King" << " [" << chessboard_names[x] << ", " << 7 - y + 1 << " ]" << endl;
    int temp_x = x;
    int temp_y = y - 1;
    int check = 0;

    check += King::Cheking_for_position_piece(temp_x, temp_y, chessboard);
    temp_x++;
    check += King::Cheking_for_position_piece(temp_x, temp_y, chessboard);
    temp_y++;
    check += King::Cheking_for_position_piece(temp_x, temp_y, chessboard);
    temp_y++;
    check += King::Cheking_for_position_piece(temp_x, temp_y, chessboard);
    temp_x--;
    check += King::Cheking_for_position_piece(temp_x, temp_y, chessboard);
    temp_x--;
    check += King::Cheking_for_position_piece(temp_x, temp_y, chessboard);
    temp_y--;
    check += King::Cheking_for_position_piece(temp_x, temp_y, chessboard);
    temp_y--;
    check += King::Cheking_for_position_piece(temp_x, temp_y, chessboard);


    if (check == 0) {
        cout << "The king does not capture a piece" << endl;
    }
    cout << endl;
}






