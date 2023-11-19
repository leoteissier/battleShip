#ifndef BATTLESHIP_SHIP_H
#define BATTLESHIP_SHIP_H

#include <string>

class Ship {
    int size;
    std::string type;
    bool isSunk;

public:
    Ship(std::string type, int size);
    void hitShip();
    bool isShipSunk() const;
};

#endif // BATTLESHIP_SHIP_H
