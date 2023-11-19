#include "Ship.h"
#include <utility>

Ship::Ship(std::string type, int size) : type(std::move(type)), size(size), isSunk(false) {}

void Ship::hitShip() {
    // Logique pour marquer le navire comme touché

    // Si toutes les parties du navire sont touchées, marquez-le comme coulé
    isSunk = true; // Mettre à jour en fonction de la logique du jeu
}

bool Ship::isShipSunk() const {
    return isSunk;
}