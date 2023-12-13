#pragma once
#include "chessboard.h"
#include <Windows.h>
#include <conio.h>
#include <iostream>

using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void draw_the_chessboard() {
    cout << "      a     b    c     d     e     f     g     h    " << endl;
    cout << "   _______________________________________________  ";
    int i = 8;
    int j = 8;
    for (int y = 2; y < 25; y++) {

        for (int x = 0; x <= 51; x += 1) {
            gotoxy(x, y);
            if (x == 2 || x == 8 || x == 14 || x == 20 || x == 26 || x == 32 || x == 38 || x == 44 || x == 50) {
                cout << "|";
            }
            else if ((y == 4 || y == 7 || y == 10 || y == 13 || y == 16 || y == 19 || y == 22) && (x >= 2 && x <= 50)) {
                cout << "_";
            }
            else if ((y == 3 || y == 6 || y == 9 || y == 12 || y == 15 || y == 18 || y == 21 || y == 24) && x == 1) {
                cout << i;
                i--;
            }
            else if ((y == 3 || y == 6 || y == 9 || y == 12 || y == 15 || y == 18 || y == 21 || y == 24) && x == 51) {
                cout << j;
                j--;
            }
        }
    }
    cout << endl << "  |_____|_____|_____|_____|_____|_____|_____|_____|  " << endl;
    cout << "      a     b    c     d     e     f     g     h    " << endl;
}

