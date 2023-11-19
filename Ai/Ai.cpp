#include "Ai.h"
#include <cstdlib>

std::pair<int, int> AI::chooseTarget(const Board& board) {
    // Logique pour choisir une case cible pour attaquer
    int gridSize = board.getSize(); // Utilisez l'accesseur non statique
    int x, y;

    // Générez des coordonnées valides pour attaquer
    do {
        x = std::rand() % gridSize;
        y = std::rand() % gridSize;
    } while (board.getCell(x, y) == 'X' || board.getCell(x, y) == 'O');

    return std::make_pair(x, y);
}

void AI::placerNavire(Board& board, const std::string &, int taille) {
    int gridSize = board.getSize();
    int debutX, debutY, finX, finY;

    do {
        debutX = std::rand() % gridSize;
        debutY = std::rand() % gridSize;

        bool horizontal = std::rand() % 2 == 0;
        if (horizontal) {
            finX = debutX + abs(taille) - 1;
            finY = debutY;
        } else {
            finX = debutX;
            finY = debutY + abs(taille) - 1;
        }
    } while (!board.verifierCoordonnees(debutX, debutY, finX, finY, taille));

    board.placeShip(debutX, debutY, taille);
}

void AI::placerNavires(Board& board, int nombreDeNavires) {
    if (nombreDeNavires > 0) placerNavire(board, "Croiseur", 3);
    if (nombreDeNavires > 1) placerNavire(board, "Torpilleur", 2);
    if (nombreDeNavires > 2) placerNavire(board, "Contre-torpilleur", 3);
    if (nombreDeNavires > 3) placerNavire(board, "Sous-marin", 3);
    if (nombreDeNavires > 4) placerNavire(board, "Porte-avion", 5);
}