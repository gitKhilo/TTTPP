#ifndef GUI_H
#define GUI_H

#include "Player.h"
#include "Board.h"
#include <SFML/Graphics.hpp>

class GUI {
public:
    GUI();
    void initialize();
    void draw(const Board& board);
    void getPlayerInput(const Player& player, int& row, int& col);
    void displayWinMessage(const Player& player);
    void displayDrawMessage();
    void cleanup();

private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text text;
    sf::RectangleShape grid[4];
    sf::CircleShape circleShape;
    sf::RectangleShape crossShape1;
    sf::RectangleShape crossShape2;

    int getCellFromMousePosition(int x, int y, int& row, int& col);
    void drawMarks(const Board& board);
};

#endif
