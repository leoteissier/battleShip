#ifndef BATTLESHIP_GAME_H
#define BATTLESHIP_GAME_H

#include "../Player/Player.h"
#include "../Ai/Ai.h"
#include "../Board/Board.h"
#include <memory>

class Game {
    int nombreDeNavires{};
    AI ai;
    Player player;
    std::unique_ptr<Board> playerBoard, aiBoard;

public:
    Game();
    void start();
    void choisirNombreDeNavires();
};

#endif //BATTLESHIP_GAME_H
