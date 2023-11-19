#ifndef BATTLESHIP_AI_H
#define BATTLESHIP_AI_H

#include "../Board/Board.h"
#include <utility>
#include <cstdlib>
#include <ctime>

class AI {
    int dernierX, dernierY;
    bool dernierCoupATouche;

public:
    AI() : dernierX(-1), dernierY(-1), dernierCoupATouche(false) {
        std::srand(std::time(nullptr));
    }

    static void placerNavire(Board& board, const std::string &type, int taille);
    static void placerNavires(Board& board, int nombreDeNavires);
    static std::pair<int, int> chooseTarget(const Board& board);
};

#endif // BATTLESHIP_AI_H
