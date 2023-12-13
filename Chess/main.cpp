#include <iostream>
#include <windows.h>
#include <conio.h>
#include "chessboard.h"
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include <fstream>
#include <string>
#include <vector>


using namespace std;


void Entry_Matrix(int chessboard[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chessboard[i][j] = -1;
        }
    }
}




int Check_txt(string name, int x, int y, int chessboard[8][8]) {

    int index;
    bool flag = false;

    if (x > 7 || x < 0 || y > 7 || y < 0) {
        return -1;
    }

    if (chessboard[7 - y][x] != -1) {
        return -2;
    }
    for (int i = 0; i < 5; i++) {
        if (pieces_name[i] == name) {
            index = i;
            flag = true;
            break;
        }
    }
    if (flag == false) {
        return -3;
    }
    else {
        chessboard[7 - y][x] = index;
        return index;
    }
}




int main() {
    string name;
    int x;
    int y;
    vector<Piece*> all_pieces;

    ifstream fin("test.txt");
    int chessboard[8][8];
    Entry_Matrix(chessboard);

    int flag;
    int line_count = 1;
    while (fin >> name >> x >> y) {
        flag = Check_txt(name, x, y, chessboard);

        if (flag == -1) {
            cout << "Coordinates in text file out of border in " << line_count << " line" << endl;
            return -1;
        }
        if (flag == -2) {
            cout << "There is already a piece at these coordinates in text file (line:" << line_count << " )" << endl;
            return -2;
        }
        if (flag == -3) {
            cout << "The name doesn't match in text file (line:" << line_count << " )" << endl;
            return -3;
        }

        if (flag == 0) {
            all_pieces.push_back(new King(name, x, 7 - y));
        }
        if (flag == 1) {
            all_pieces.push_back(new Queen(name, x, 7 - y));
        }
        if (flag == 2) {
            all_pieces.push_back(new Rook(name, x, 7 - y));
        }
        if (flag == 3) {
            all_pieces.push_back(new Bishop(name, x, 7 - y));
        }
        if (flag == 4) {
            all_pieces.push_back(new Knight(name, x, 7 - y));
        }
        line_count++;
    }

    if (all_pieces.size() < 2) {
        cout << "The text file contains little pieces" << endl;
        return -4;
    }

    if (all_pieces.size() > 10) {
        cout << "The text file contains a lot of pieces" << endl;
        return -4;
    }

    draw_the_chessboard();

    for (auto& x : all_pieces)
    {
        x->Piece_Draw();
    }



    gotoxy(0, 27);



    for (auto& x : all_pieces)
    {
        x->Beat_Check(chessboard);
    }

    return 0;

}