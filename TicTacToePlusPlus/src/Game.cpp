#include "Game.h"

Game::Game()
    : player1('X'), player2('O'), currentPlayer(1), isRunning(true) {
}

void Game::run() {
    gui.initialize();

    while (isRunning) {
        gui.draw(board);
        int row, col;
        bool validMove = false;

        while (!validMove) {
            gui.getPlayerInput(currentPlayer == 1 ? player1 : player2, row, col);
            validMove = board.placeMark(row, col, currentPlayer == 1 ? player1.getMark() : player2.getMark());
        }

        if (board.checkWin()) {
            gui.draw(board);
            gui.displayWinMessage(currentPlayer == 1 ? player1 : player2);
            isRunning = false;
        } else if (board.isFull()) {
            gui.draw(board);
            gui.displayDrawMessage();
            isRunning = false;
        } else {
            switchPlayer();
        }
    }

    gui.cleanup();
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}
