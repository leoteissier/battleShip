#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H

#include <vector>
#include <iostream>

class Board {
    std::vector<std::vector<char>> grid;
    int gridSize;

public:
    explicit Board(int size);
    void placeShip(int x, int y, int taille);
    bool verifierCoordonnees(int debutX, int debutY, int finX, int finY, int taille);
    bool attack(int x, int y);
    void updateCell(int x, int y, char status);
    [[nodiscard]] std::string getLine(int line) const;
    [[nodiscard]] int getSize() const;
    [[nodiscard]] bool areAllShipsSunk() const;
    [[nodiscard]] char getCell(int x, int y) const;
};

#endif //BATTLESHIP_BOARD_H
