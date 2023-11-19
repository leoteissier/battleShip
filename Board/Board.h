#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H

#include <vector>
#include <iostream>

class Board {
    std::vector<std::vector<char>> grid;
    int gridSize;

public:
    explicit Board(int size);
    void display() const;
    void placeShip(int x, int y, int taille);
    bool attack(int x, int y);
    [[nodiscard]] int getSize() const;
    [[nodiscard]] bool areAllShipsSunk() const;
    [[nodiscard]] char getCell(int x, int y) const;
    bool verifierCoordonnees(int debutX, int debutY, int finX, int finY, int taille);
};

#endif //BATTLESHIP_BOARD_H
