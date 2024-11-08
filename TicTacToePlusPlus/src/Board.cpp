#include "Board.h"

Board::Board() {
    reset();
}

void Board::reset() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = ' ';
}

bool Board::placeMark(int row, int col, char mark) {
    if (row >=0 && row <3 && col >=0 && col <3) {
        if (board[row][col] == ' ') {
            board[row][col] = mark;
            return true;
        }
    }
    return false;
}

bool Board::checkWin() {
    return checkRows() || checkColumns() || checkDiagonals();
}

bool Board::isFull() {
    for (int i = 0; i <3; ++i)
        for (int j = 0; j <3; ++j)
            if (board[i][j] == ' ')
                return false;
    return true;
}

char Board::getMark(int row, int col) const {
    return board[row][col];
}

bool Board::checkRows() {
    for (int i = 0; i < 3; ++i)
        if (board[i][0] != ' ' && 
            board[i][0] == board[i][1] && 
            board[i][1] == board[i][2])
            return true;
    return false;
}

bool Board::checkColumns() {
    for (int i = 0; i < 3; ++i)
        if (board[0][i] != ' ' && 
            board[0][i] == board[1][i] && 
            board[1][i] == board[2][i])
            return true;
    return false;
}

bool Board::checkDiagonals() {
    if (board[0][0] != ' ' && 
        board[0][0] == board[1][1] && 
        board[1][1] == board[2][2])
        return true;
    if (board[0][2] != ' ' && 
        board[0][2] == board[1][1] && 
        board[1][1] == board[2][0])
        return true;
    return false;
}
