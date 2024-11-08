#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include "GUI.h"

class Game {
public:
    Game();
    void run();

private:
    Board board;
    Player player1;
    Player player2;
    GUI gui;

    int currentPlayer;
    void switchPlayer();
    bool isRunning;
};

#endif
