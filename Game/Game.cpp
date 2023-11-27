#include "Game.h"
#include <iostream>


void Game::choisirNombreDeNavires() {
    std::cout << "Choisissez le nombre de navires (1-5):";
    std::cin >> nombreDeNavires;
    if (nombreDeNavires < 1 || nombreDeNavires > 5) {
        std::cout << "Nombre invalide, veuillez choisir entre 1 et 5." << std::endl;
        choisirNombreDeNavires();
    }
}

Game::Game() : ai(), player() {
    std::cout << "Bienvenue dans le jeu de bataille navale!" << std::endl;
    choisirNombreDeNavires(); // Définissez le nombre de navires ici

    // Créez les plateaux de jeu avec la taille appropriée
    playerBoard = std::make_unique<Board>(5 + nombreDeNavires * 3 - 3);
    aiBoard = std::make_unique<Board>(5 + nombreDeNavires * 3 - 3);
    displayBoardForAI = std::make_unique<Board>(5 + nombreDeNavires * 3 - 3);

    std::cout << "Veuillez placer vos navires." << std::endl;
    Player::placerNavires(*playerBoard, nombreDeNavires);
    AI::placerNavires(*aiBoard, nombreDeNavires);
}

void Game::start() {
    int x, y;
    bool isPlayerTurn = true;

    while (true) {
        if (isPlayerTurn) {
            // Affichage du plateau du joueur
            std::cout << "\nPlateau du Joueur:\n";
            playerBoard->display();

            // Affichage du plateau de l'IA tel que connu par le joueur
            std::cout << "\nPlateau de l'IA:\n";
            displayBoardForAI->display();

            // Tour du joueur
            std::cout << "Entrez les coordonnees de votre attaque (x y): ";
            std::cin >> x >> y;

            // Vérifier la validité des coordonnées
            if (x >= 0 && x < aiBoard->getSize() && y >= 0 && y < aiBoard->getSize()) {
                if (aiBoard->attack(x, y)) {
                    std::cout << "Touche !" << std::endl;
                    displayBoardForAI->updateCell(x, y, 'X'); // Mettre à jour le plateau affiché
                } else {
                    std::cout << "Manque..." << std::endl;
                    displayBoardForAI->updateCell(x, y, 'O'); // Mettre à jour le plateau affiché
                }

                // Vérifier si le joueur a gagné
                if (aiBoard->areAllShipsSunk()) {
                    std::cout << "Felicitations! Vous avez gagne!" << std::endl;
                    break;
                }
            } else {
                std::cout << "Coordonnees invalides. Veuillez essayer à nouveau." << std::endl;
                continue; // Reste dans le tour du joueur si les coordonnées sont invalides
            }
        } else {
            // Tour de l'IA
            auto [aiX, aiY] = AI::chooseTarget(*playerBoard);
            bool hit = playerBoard->attack(aiX, aiY);
            std::cout << "L'IA attaque les coordonnees (" << aiX << ", " << aiY << ") et a " << (hit ? "touche" : "manque") << "!" << std::endl;

            // Vérifier si l'IA a gagné
            if (playerBoard->areAllShipsSunk()) {
                std::cout << "Vous avez perdu. Tous vos navires ont ete coules!" << std::endl;
                break;
            }
        }

        // Changer de tour
        isPlayerTurn = !isPlayerTurn;
    }

    std::cout << "Jeu termine!" << std::endl;
}


