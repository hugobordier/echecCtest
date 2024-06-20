
#ifndef FONCTION_H
#define FONCTION_H

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char type; 
    Position position;
    char couleur; // blanc ou noir / 'b' ou 'n' ou ' '
} Piece;

typedef struct {
    Piece plateau[8][8];
    char joueurActuel; // 'b' ou 'n'
    char EtatDuJeu; // c pour en cours et f pour termine et e pour egalité
} JeuEchecs;

#endif
