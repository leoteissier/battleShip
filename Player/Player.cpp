#include "Player.h"
#include <iostream>

void Player::placerNavire(Board& board, const std::string &type, int taille) {
    int debutX, debutY, finX, finY;
    bool coordonneesValides;

    do {
        std::cout << "Entrez les coordonnees de debut pour votre " << type
                  << " (" << taille << (taille > 1 ? " cases" : " case") << ") (x y):";
        std::cin >> debutX >> debutY;
        std::cout << "Entrez les coordonnees de fin pour votre " << type
                  << " (" << taille << (taille > 1 ? " cases" : " case") << ") (x y):";
        std::cin >> finX >> finY;

        coordonneesValides = board.verifierCoordonnees(debutX, debutY, finX, finY, taille);
        if (!coordonneesValides) {
            std::cout << "Erreur lors du placement du navire. Veuillez reessayer." << std::endl;
        }
    } while (!coordonneesValides);

    board.placeShip(debutX, debutY, taille);
}

void Player::placerNavires(Board& board, int nombreDeNavires) {
    int gridSize = board.getSize();
    std::cout << "Vous avez " << nombreDeNavires << " navires a placer." << std::endl;
    std::cout << "La grille fait " << gridSize << " de taille (0:"<< gridSize - 1 << ")" << std::endl;

    // Placez les navires un par un
    if (nombreDeNavires > 0) placerNavire(board, "Croiseur", 3);
    if (nombreDeNavires > 1) placerNavire(board, "Torpilleur", 2);
    if (nombreDeNavires > 2) placerNavire(board, "Contre-torpilleur", 3);
    if (nombreDeNavires > 3) placerNavire(board, "Sous-marin", 3);
    if (nombreDeNavires > 4) placerNavire(board, "Porte-avion", 5);
}
