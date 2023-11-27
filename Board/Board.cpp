#include "Board.h"

Board::Board(int size) : gridSize(size), grid(size, std::vector<char>(size, '~')) {}

void Board::display() const {
    for (const auto &row : grid) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

void Board::placeShip(int startX, int startY, int taille) {
    // Assumer une orientation horizontale ou verticale basée sur la taille
    // Si taille est positive, placer horizontalement, sinon verticalement
    bool horizontal = taille > 0;
    taille = abs(taille); // Assurer que la taille est positive

    // Vérifier les limites et le chevauchement
    for (int i = 0; i < taille; i++) {
        int x = startX + (horizontal ? i : 0);
        int y = startY + (horizontal ? 0 : i);

        if (x < 0 || x >= gridSize || y < 0 || y >= gridSize || grid[x][y] != '~') {
            // Si hors limites ou chevauchant, ne pas placer et sortir
            std::cout << "Placement du navire invalide." << std::endl;
            return;
        }
    }

    // Placer le navire
    for (int i = 0; i < taille; i++) {
        int x = startX + (horizontal ? i : 0);
        int y = startY + (horizontal ? 0 : i);
        grid[x][y] = 'S'; // 'S' représente un navire
    }
}

bool Board::verifierCoordonnees(int debutX, int debutY, int finX, int finY, int taille) {
    // Vérifiez que les coordonnées sont dans la même ligne ou colonne
    bool memeLigne = (debutY == finY);
    bool memeColonne = (debutX == finX);
    if (!memeLigne && !memeColonne) {
        std::cout << "Le navire doit être place sur une même ligne ou colonne." << std::endl;
        return false;
    }

    // Calcul de la distance entre les coordonnées de début et de fin
    int distance = memeLigne ? abs(finX - debutX) : abs(finY - debutY);

    // Vérifiez que la distance correspond à la taille du navire
    if (distance != taille - 1) {
        std::cout << "La taille du navire ne correspond pas à celle specifiee." << std::endl;
        return false;
    }

    // Vérifiez que les coordonnées sont dans les limites du plateau
    if (debutX < 0 || debutX >= gridSize || debutY < 0 || debutY >= gridSize ||
        finX < 0 || finX >= gridSize || finY < 0 || finY >= gridSize) {
        std::cout << "Les coordonnees sont hors du plateau." << std::endl;
        return false;
    }

    // Vérifiez que les coordonnées ne sont pas déjà occupées
    for (int i = 0; i <= distance; i++) {
        int x = memeLigne ? debutX + i : debutX;
        int y = memeLigne ? debutY : debutY + i;
        if (grid[x][y] != '~') {
            std::cout << "Les coordonnees sont dejà occupees." << std::endl;
            return false;
        }
    }

    return true;
}

void Board::displayForOpponent() const {
    for (const auto& row : grid) {
        for (char cell : row) {
            if (cell == 'S') { // Navire non touché
                std::cout << '~' << " "; // Affiche '~' pour cacher le navire
            } else {
                std::cout << cell << " "; // Affiche l'état actuel pour les autres cases
            }
        }
        std::cout << std::endl;
    }
}

bool Board::attack(int x, int y) {
    if (grid[x][y] == 'S') { // 'S' représente un navire
        grid[x][y] = 'X'; // Marquer comme touché
        return true;
    } else if (grid[x][y] == '~') { // '~' représente une case vide
        grid[x][y] = 'O'; // Marquer comme manqué
    }
    return false;
}

void Board::updateCell(int x, int y, char status) {
    if (x >= 0 && x < gridSize && y >= 0 && y < gridSize) {
        grid[x][y] = status;
    }
}

int Board::getSize() const {
    return gridSize;
}

bool Board::areAllShipsSunk() const {
    for (const auto &row : grid) {
        for (char cell : row) {
            if (cell == 'S') { // S'il reste des navires non touchés
                return false;
            }
        }
    }
    return true;
}

char Board::getCell(int x, int y) const {
    return grid[x][y];
}



