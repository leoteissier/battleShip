#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H

#include "../Board/Board.h"

class Player {
public:
    static void placerNavire(Board& board, const std::string &type, int taille);
    static void placerNavires(Board& board, int nombreDeNavires);
};

#endif // BATTLESHIP_PLAYER_H
