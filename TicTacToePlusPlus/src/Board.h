#ifndef BOARD_H
#define BOARD_H

class Board {
public:
    Board();
    void reset();
    bool placeMark(int row, int col, char mark);
    bool checkWin();
    bool isFull();
    char getMark(int row, int col) const;

private:
    char board[3][3];

    bool checkRows();
    bool checkColumns();
    bool checkDiagonals();
};

#endif
