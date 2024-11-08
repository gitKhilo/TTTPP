#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player(char mark);
    char getMark() const;

private:
    char mark;
};

#endif
