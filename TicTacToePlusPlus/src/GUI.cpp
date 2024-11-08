#include "GUI.h"
#include <iostream>
#include <sstream>

GUI::GUI()
    : window(sf::VideoMode(300, 300), "Tic-Tac-Toe") {
}

void GUI::initialize() {
    if (!font.loadFromFile("../resources/arial.ttf")) {
        std::cerr << "Error loading font arial.ttf" << std::endl;
        exit(1);
    }

    // Initialize grid lines
    for (int i = 0; i < 4; ++i) {
        grid[i].setFillColor(sf::Color::Black);
        if (i < 2) {
            grid[i].setSize(sf::Vector2f(300, 5));
            grid[i].setPosition(0, 100 * (i + 1));
        } else {
            grid[i].setSize(sf::Vector2f(5, 300));
            grid[i].setPosition(100 * (i - 1), 0);
        }
    }

    // Initialize circle for 'O'
    circleShape.setRadius(40);
    circleShape.setOutlineThickness(5);
    circleShape.setOutlineColor(sf::Color::Red);
    circleShape.setFillColor(sf::Color::Transparent);

    // Initialize crosses for 'X'
    crossShape1.setSize(sf::Vector2f(100, 5));
    crossShape1.setFillColor(sf::Color::Blue);
    crossShape1.rotate(45);

    crossShape2.setSize(sf::Vector2f(100, 5));
    crossShape2.setFillColor(sf::Color::Blue);
    crossShape2.rotate(-45);
}

void GUI::draw(const Board& board) {
    window.clear(sf::Color::White);

    // Draw grid
    for (int i = 0; i < 4; ++i)
        window.draw(grid[i]);

    // Draw marks
    drawMarks(board);

    window.display();
}

void GUI::drawMarks(const Board& board) {
    for (int row = 0; row <3; ++row) {
        for (int col = 0; col <3; ++col) {
            char mark = board.getMark(row, col);
            if (mark == 'X') {
                crossShape1.setPosition(col * 100 + 15, row * 100 + 15);
                crossShape2.setPosition(col * 100 + 85, row * 100 + 15);
                window.draw(crossShape1);
                window.draw(crossShape2);
            } else if (mark == 'O') {
                circleShape.setPosition(col * 100 + 10, row * 100 + 10);
                window.draw(circleShape);
            }
        }
    }
}

void GUI::getPlayerInput(const Player& player, int& row, int& col) {
    bool inputReceived = false;
    while (!inputReceived) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                exit(0);
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                int x = event.mouseButton.x;
                int y = event.mouseButton.y;
                if (getCellFromMousePosition(x, y, row, col)) {
                    inputReceived = true;
                }
            }
        }
        // Keep drawing to make the window responsive
        draw(Board());
    }
}

int GUI::getCellFromMousePosition(int x, int y, int& row, int& col) {
    if (x < 0 || x > 300 || y < 0 || y > 300)
        return 0;
    col = x / 100;
    row = y / 100;
    return 1;
}

void GUI::displayWinMessage(const Player& player) {
    // Display win message
    std::stringstream ss;
    ss << "Player " << player.getMark() << " wins!";
    text.setFont(font);
    text.setString(ss.str());
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(50, 130);
    window.draw(text);
    window.display();
    sf::sleep(sf::seconds(3));
}

void GUI::displayDrawMessage() {
    // Display draw message
    text.setFont(font);
    text.setString("It's a draw!");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(90, 130);
    window.draw(text);
    window.display();
    sf::sleep(sf::seconds(3));
}

void GUI::cleanup() {
    window.close();
}
