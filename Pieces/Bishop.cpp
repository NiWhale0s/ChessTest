#include "Bishop.h"
#include "Piece.h"
#include <Windows.h>
#include <io.h>
#include <fcntl.h>

Bishop::Bishop(string new_name, int new_x, int new_y) : piece_name(new_name), x(new_x), y(new_y) {}

void Bishop::insideGotoXY(short x, short y) const
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Bishop::Piece_Draw() const
{
    insideGotoXY(4 + 6 * x, 3 + 3 * y);
    cout << "bis";
}


int Bishop::Cheking_for_position_piece(int x, int y, int chessboard[8][8]) const
{

    if (chessboard[y][x] != -1) {
        cout << "Bishop beats " << pieces_name[chessboard[y][x]] << " [" << chessboard_names[x] << ", " << 7 - y + 1 << " ]" << endl;
        return 1;
    }
    return 0;
}


void Bishop::Beat_Check(int chessboard[8][8]) const
{


    int check = 0;
    int temp = 0;
    int temp_x = x - 1;
    int temp_y = y - 1;
    cout << endl << "Bishop" << " [" << chessboard_names[x] << ", " << 7 - y + 1 << " ]" << endl;
    while (temp_x >= 0 && temp_y >= 0) {
        check += Bishop::Cheking_for_position_piece(temp_x, temp_y, chessboard);
        temp_x -= 1;
        temp_y -= 1;
        if (check == 1) {
            check = 0;
            temp = 1;
            break;
        }
    }

    temp_x = x + 1;
    temp_y = y - 1;
    while (temp_x <= 7 && temp_y >= 0) {
        check += Bishop::Cheking_for_position_piece(temp_x, temp_y, chessboard);
        temp_x += 1;
        temp_y -= 1;
        if (check == 1) {
            check = 0;
            temp = 1;
            break;
        }
    }

    temp_x = x + 1;
    temp_y = y + 1;
    while (temp_x <= 7 && temp_y <= 7) {
        check += Bishop::Cheking_for_position_piece(temp_x, temp_y, chessboard);
        temp_x += 1;
        temp_y += 1;
        if (check == 1) {
            check = 0;
            temp = 1;
            break;
        }
    }

    temp_x = x - 1;
    temp_y = y + 1;
    while (temp_x >= 0 && temp_y <= 7) {
        check += Bishop::Cheking_for_position_piece(temp_x, temp_y, chessboard);
        temp_x -= 1;
        temp_y += 1;
        if (check == 1) {
            check = 0;
            temp = 1;
            break;
        }
    }


    if (temp == 0) {
        cout << "The bishop does not capture a piece" << endl;
    }
    cout << endl;
}