#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

typedef struct Position {
    int x;
    int y;
} Position;

typedef struct Piece {
    char type; 
    Position position;
    char couleur; // blanc ou noir / 'b' ou 'n' ou ' '
} Piece;

typedef struct JeuEchecs{
    Piece plateau[8][8];
    char joueurActuel; // 'b' ou 'n'
    char EtatDuJeu; // c pour en cours et f pour termine et e pour egalité
} JeuEchecs;

void initialiserJeu(JeuEchecs *jeu) {
    jeu->plateau[0][0].type = 'T'; jeu->plateau[0][0].position = (Position) {0, 0}; jeu->plateau[0][0].couleur = 'b';
    jeu->plateau[0][1].type = 'C'; jeu->plateau[0][1].position = (Position) {0, 1}; jeu->plateau[0][1].couleur = 'b';
    jeu->plateau[0][2].type = 'F'; jeu->plateau[0][2].position = (Position) {0, 2}; jeu->plateau[0][2].couleur = 'b';
    jeu->plateau[0][3].type = 'D'; jeu->plateau[0][3].position = (Position) {0, 3}; jeu->plateau[0][3].couleur = 'b';
    jeu->plateau[0][4].type = 'R'; jeu->plateau[0][4].position = (Position) {0, 4}; jeu->plateau[0][4].couleur = 'b';
    jeu->plateau[0][5].type = 'F'; jeu->plateau[0][5].position = (Position) {0, 5}; jeu->plateau[0][5].couleur = 'b';
    jeu->plateau[0][6].type = 'C'; jeu->plateau[0][6].position = (Position) {0, 6}; jeu->plateau[0][6].couleur = 'b';
    jeu->plateau[0][7].type = 'T'; jeu->plateau[0][7].position = (Position) {0, 7}; jeu->plateau[0][7].couleur = 'b';

    for (int i = 0; i < 8; i++) {
        jeu->plateau[1][i].type = 'P'; jeu->plateau[1][i].position = (Position) {1, i}; jeu->plateau[1][i].couleur = 'b';
    }

    jeu->plateau[7][0].type = 't'; jeu->plateau[7][0].position = (Position) {7, 0}; jeu->plateau[7][0].couleur = 'n';
    jeu->plateau[7][1].type = 'c'; jeu->plateau[7][1].position = (Position) {7, 1}; jeu->plateau[7][1].couleur = 'n';
    jeu->plateau[7][2].type = 'f'; jeu->plateau[7][2].position = (Position) {7, 2}; jeu->plateau[7][2].couleur = 'n';
    jeu->plateau[7][3].type = 'd'; jeu->plateau[7][3].position = (Position) {7, 3}; jeu->plateau[7][3].couleur = 'n';
    jeu->plateau[7][4].type = 'r'; jeu->plateau[7][4].position = (Position) {7, 4}; jeu->plateau[7][4].couleur = 'n';
    jeu->plateau[7][5].type = 'f'; jeu->plateau[7][5].position = (Position) {7, 5}; jeu->plateau[7][5].couleur = 'n';
    jeu->plateau[7][6].type = 'c'; jeu->plateau[7][6].position = (Position) {7, 6}; jeu->plateau[7][6].couleur = 'n';
    jeu->plateau[7][7].type = 't'; jeu->plateau[7][7].position = (Position) {7, 7}; jeu->plateau[7][7].couleur = 'n';

    for (int i = 0; i < 8; i++) {
        jeu->plateau[6][i].type = 'p'; jeu->plateau[6][i].position = (Position) {6, i}; jeu->plateau[6][i].couleur = 'n';
    }

    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            jeu->plateau[i][j].type = ' '; jeu->plateau[i][j].position = (Position) {i, j}; jeu->plateau[i][j].couleur = ' ';
        }
    }


}

void afficherJeu(const JeuEchecs *jeu) {
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            printf("|%c| ", jeu->plateau[i][j].type);
        }
        printf("\n");
    }
}

char typeDeLaPiece(JeuEchecs *jeu, int x, int y){
    return jeu->plateau[x][y].type;
}

void conditionPourBouger(JeuEchecs *jeu,int departX,int departY,int arriveX,int arriveY){
    if (departX < 0 || departX >= 8 || departY < 0 || departY >= 8 ||
        arriveX < 0 || arriveX >= 8 || arriveY < 0 || arriveY >= 8) {
        printf("Coordonnées invalides.\n");
        return;
    }

    if(jeu->plateau[departX][departY].couleur == 'b' && jeu->joueurActuel != 'b' || 
    jeu->plateau[departX][departY].couleur == 'n' && jeu->joueurActuel != 'n' ){
        printf("pas uen piece a toi nulos \n");
        return;
    }
}

void deplacerPion(JeuEchecs *jeu, int departX, int departY, int arriveX, int arriveY) { 
    if (departX < 0 || departX >= 8 || departY < 0 || departY >= 8 ||
        arriveX < 0 || arriveX >= 8 || arriveY < 0 || arriveY >= 8) {
        printf("Coordonnées invalides.\n");
        return;
    }

    if(jeu->plateau[departX][departY].couleur == 'b' && jeu->joueurActuel != 'b' || 
    jeu->plateau[departX][departY].couleur == 'n' && jeu->joueurActuel != 'n' ){
        printf("pas uen piece a toi nulos \n");
        return;
    }

    if (jeu->plateau[departX][departY].type != 'P' && //cette fonction sert a peu a rien mais laisse pour l'instant
        jeu->plateau[departX][departY].type != 'p') {
        printf("La pièce sélectionnée n'est pas un pion.\n");
        return;
    }
    printf("%c\n",jeu->joueurActuel);
    printf("%c\n",jeu->plateau[departX][departY].couleur);
    printf("%c\n",jeu->plateau[departX][departY].couleur);
    if (jeu->joueurActuel == 'b' && jeu->plateau[departX][departY].couleur == 'n' || jeu->plateau[departX][departY].couleur == ' ') {
        printf("C'est pas un pion blanc\n");
        return;
        ;
    } else if (jeu->joueurActuel == 'n' && jeu->plateau[departX][departY].couleur == 'b' || jeu->plateau[departX][departY].couleur == ' ') {
        printf("C'est oas un pion noir.\n");
        ;
    }
    //int direction = (jeu->plateau[departX][departY].couleur == 'b') ? 1 : -1; 
    int direction = 0;
    if(jeu->plateau[departX][departY].couleur == 'b'){
        direction = 1;
    }else{
        direction = -1;
    }
    if ((arriveX - departX == direction && arriveY == departY) && jeu->plateau[arriveX][arriveY].type == ' ' || // en avant de 1 
        (departX == 1 && arriveX - departX == 2 * direction && arriveY == departY) &&
        jeu->plateau[arriveX][arriveY].type == ' ' && jeu->plateau[arriveX-direction][arriveY].type == ' ' || // en avant de 2 que au depart
        (arriveX - departX == direction && abs(arriveY - departY) == 1 &&
        jeu->plateau[arriveX][arriveY].couleur != jeu->plateau[departX][departY].couleur) && jeu->plateau[arriveX][arriveY].couleur != ' ' ) // pour manger en diagonale 
        {
        // Deplacmeent ok
        jeu->plateau[arriveX][arriveY] = jeu->plateau[departX][departY];
        jeu->plateau[departX][departY].type = ' ';jeu->plateau[departX][departY].couleur = ' ';
    } else {
        printf("Mouvement invalide pour un pion.\n");
    }
}

void deplacerTour(JeuEchecs *jeu, int departX, int departY, int arriveX, int arriveY){
    if(jeu->plateau[departX][departY].couleur == 'b' && jeu->joueurActuel != 'b' || 
    jeu->plateau[departX][departY].couleur == 'n' && jeu->joueurActuel != 'n' ){
        printf("pas uen piece a toi nulos \n");
        return;
    }
    if (departX < 0 || departX >= 8 || departY < 0 || departY >= 8 ||
        arriveX < 0 || arriveX >= 8 || arriveY < 0 || arriveY >= 8) {
        printf("Coordonnées invalides.\n");
        return;
    }
    printf("le joueur qui joue est %d \n",jeu->joueurActuel);
    /*if (jeu->plateau[departX][departY].type != 'T' &&
        jeu->plateau[departX][departY].type != 't') {
        printf("La pièce sélectionnée n'est pas une tour.\n");
        return;
    }*/

    if (departX != arriveX && departY != arriveY) {
        printf("Mouvement invalide pour une tour.\n");
        return;
    }

    int deltaX, deltaY;

    if (arriveX - departX != 0) {
        deltaX = (arriveX - departX) / abs(arriveX - departX); // pour savoir si la tour va vers le haut ou le bas/ 1 ou -1
    } else {
        deltaX = 0;
    }

    if (arriveY - departY != 0) {
        deltaY = (arriveY - departY) / abs(arriveY - departY); // pour savoir si la tour va a gauche ou a droite/ 1 pu -1
    } else {
        deltaY = 0;
    }

    for(int i = 1;i < abs(arriveX - departX) || i < abs(arriveY - departY);i++){
        int x = departX + i*deltaX;
        int y = departY + i*deltaY;
        if (jeu->plateau[x][y].type != ' ') {
            printf("Il y a un obstacle sur la trajectoire.\n");
        return;
        }
    }
    if (jeu->plateau[arriveX][arriveY].couleur == jeu->plateau[departX][departY].couleur) {
        printf("Une tour ne peut pas se déplacer sur une case occupée par une pièce de la même couleur.\n");
        return;
    }

    // Déplacement OK
    jeu->plateau[arriveX][arriveY] = jeu->plateau[departX][departY];
    jeu->plateau[departX][departY].type = ' '; jeu->plateau[departX][departY].couleur = ' ';


}

void deplacerFou(JeuEchecs *jeu, int departX, int departY, int arriveX, int arriveY){

    conditionPourBouger(jeu,departX,departY,arriveX,arriveY);

    /*if (jeu->plateau[departX][departY].type != 'F' &&
        jeu->plateau[departX][departY].type != 'f') {
        printf("La pièce sélectionnée n'est pas un fou.\n");
        return;
    }*/

    if (abs(arriveX - departX) != abs(arriveY - departY)) {
        printf("Mouvement invalide pour un fou.\n");
        return;
    }

    int deltaX, deltaY;
    if (arriveX - departX != 0) {
        deltaX = (arriveX - departX) / abs(arriveX - departX);
    } else {
        deltaX = 0;
    }
    if (arriveY - departY != 0) {
        deltaY = (arriveY - departY) / abs(arriveY - departY);
    } else {
        deltaY = 0;
    }

    for (int i = 1; i < abs(arriveX - departX); i++) {
            int x = departX + i * deltaX;
            int y = departY + i * deltaY;

            if (x < 0 || x >= 8 || y < 0 || y >= 8) {
                printf("Trajectoire en dehors du plateau.\n");
                return;
            }

            if (jeu->plateau[x][y].type != ' ') {
                printf("Il y a un obstacle sur la trajectoire.\n");
            return;
            }
    }
    if(jeu->plateau[arriveX][arriveY].couleur == jeu->joueurActuel){
        printf("bouffe pas ton pion\n");
        return;
    }
    jeu->plateau[arriveX][arriveY] = jeu->plateau[departX][departY];
    jeu->plateau[departX][departY].type = ' ';jeu->plateau[departX][departY].couleur = ' ';
}

void deplacerCavalier(JeuEchecs *jeu, int departX, int departY, int arriveX, int arriveY) {
    conditionPourBouger(jeu, departX, departY, arriveX, arriveY);

    if (jeu->plateau[departX][departY].type != 'C' &&
        jeu->plateau[departX][departY].type != 'c') {
        printf("La pièce sélectionnée n'est pas un cavalier.\n");
        return;
    }

    int deltaX = abs(arriveX - departX);
    int deltaY = abs(arriveY - departY);

    if (!((deltaX == 1 && deltaY == 2) || (deltaX == 2 && deltaY == 1))) {
        printf("Mouvement pas possible c'est pas un L \n");
        return;
    }

    if (jeu->plateau[arriveX][arriveY].couleur == jeu->joueurActuel) {
        printf("te mange pas tdc.\n");
        return;
    }

    // Déplacement ok
    jeu->plateau[arriveX][arriveY] = jeu->plateau[departX][departY];
    jeu->plateau[departX][departY].type = ' ';
    jeu->plateau[departX][departY].couleur = ' ';
}

void deplacerRoi(JeuEchecs *jeu, int departX, int departY, int arriveX, int arriveY) {
    conditionPourBouger(jeu, departX, departY, arriveX, arriveY);

    if (jeu->plateau[departX][departY].type != 'R' &&
        jeu->plateau[departX][departY].type != 'r') {
        printf("pas un toi\n");
        return;
    }

    int deltaX = abs(arriveX - departX);
    int deltaY = abs(arriveY - departY);

    if (!((deltaX == 0 || deltaX == 1) && (deltaY == 0 || deltaY == 1))) {
        printf("pas possible de faire ca\n");
        return;
    }
    if (jeu->plateau[arriveX][arriveY].couleur == jeu->joueurActuel) {
        printf("pas possible de se manger\n");
        return;
    }



    // Déplacement valide
    jeu->plateau[arriveX][arriveY] = jeu->plateau[departX][departY];
    jeu->plateau[departX][departY].type = ' ';
    jeu->plateau[departX][departY].couleur = ' ';
}

void deplacerReine(JeuEchecs *jeu, int departX, int departY, int arriveX, int arriveY) {
    conditionPourBouger(jeu, departX, departY, arriveX, arriveY);

    if (jeu->plateau[departX][departY].type != 'D' &&
        jeu->plateau[departX][departY].type != 'd') {
        printf("La pièce sélectionnée n'est pas une reine.\n");
        return;
    }

    if(departX==arriveX || departY == arriveY){
    deplacerTour(jeu, departX, departY, arriveX, arriveY);
    }else
    {
    deplacerFou(jeu, departX, departY, arriveX, arriveY);
    }
    
}

int jeuDifferent(JeuEchecs jeu1,JeuEchecs jeu2){// retourne 1 si le jeu est diff sinon 0
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (!(jeu1.plateau[i][j].type == jeu2.plateau[i][j].type) ) {
                return 1;
            }
        }
    }
    return 0;
}

int enEchecA(JeuEchecs *jeu, int x, int y) {
    // Déclaration avancée de la fonction copierJeu
    JeuEchecs *copierJeu(JeuEchecs jeu);

    // Allocation de mémoire pour la copie du jeu
    JeuEchecs *copieJeu = copierJeu(*jeu);

    char adversaire = (copieJeu->joueurActuel == 'b') ? 'n' : 'b'; // récupère le joueur adverse

    int nombrePiecesAdverses = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (copieJeu->plateau[i][j].couleur == adversaire) {
                nombrePiecesAdverses++;
            }
        }
    }

    Position *coordonnees = (Position *)malloc(nombrePiecesAdverses * sizeof(Position));
    if (coordonnees == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire pour les coordonnées des pièces adverses.\n");
        exit(EXIT_FAILURE);
    }

    int index = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (copieJeu->plateau[i][j].couleur == adversaire) {
                coordonnees[index].x = i;
                coordonnees[index].y = j;
                index++;
            }
        }
    }
    
    for(int i = 0; i < nombrePiecesAdverses; i++) {
        switch(copieJeu->plateau[coordonnees[i].x][coordonnees[i].y].type) {
            case 'p':
            case 'P':
                deplacerPion(copieJeu, coordonnees[i].x, coordonnees[i].y, x, y);
                break;
            case 't':
            case 'T':
                deplacerTour(copieJeu, coordonnees[i].x, coordonnees[i].y, x, y);
                break;
            case 'c':
            case 'C':
                deplacerCavalier(copieJeu, coordonnees[i].x, coordonnees[i].y, x, y);
                break;
            case 'f':
            case 'F':
                deplacerFou(copieJeu, coordonnees[i].x, coordonnees[i].y, x, y);
                break;
            case 'd':
            case 'D':
                deplacerReine(copieJeu, coordonnees[i].x, coordonnees[i].y, x, y);
                break;
            case 'r':
            case 'R':
                deplacerRoi(copieJeu, coordonnees[i].x, coordonnees[i].y, x, y);
                break;
            default:
                break;
        }
    }

    int echec = jeuDifferent(*jeu, *copieJeu) == 1 ? 1 : 0;

    free(coordonnees);
    free(copieJeu);

    return echec;
}

Position PositionRoi(JeuEchecs jeu){
    Position position;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (jeu.plateau[i][j].couleur == jeu.joueurActuel && jeu.plateau[i][j].type ==('r' || 'R')) {
                position.x = i;
                position.y = j;
            }
        }
    }
    return position;
}

JeuEchecs *copierJeu(JeuEchecs jeu) {
    JeuEchecs *copie = (JeuEchecs *)malloc(sizeof(JeuEchecs));
    if (copie == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire pour la copie du jeu.\n");
        exit(EXIT_FAILURE);
    }

    // Copie du plateau de jeu
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            copie->plateau[i][j] = jeu.plateau[i][j];
        }
    }

    // Copie du joueur actuel et de l'état du jeu
    copie->joueurActuel = jeu.joueurActuel;
    copie->EtatDuJeu = jeu.EtatDuJeu;

    return copie;
}
int main() {
    JeuEchecs jeu;
    initialiserJeu(&jeu);
    afficherJeu(&jeu);
    jeu.EtatDuJeu = 'c';
    jeu.joueurActuel = 'b'; //l'autre c n
    printf("\n");
    printf("DEBUT\n");
    while(jeu.EtatDuJeu == 'c'){
        afficherJeu(&jeu);
        printf("c'est a %c de jouer\n",jeu.joueurActuel);
        printf("d'ou voulez vous jouer : d'abord en x puis en y\n"); 
        int xDepart,yDepart,xArrivee,yArrivee;
        scanf("%d",&xDepart); 
        printf("puis y\n"); 
        scanf("%d",&yDepart); 
        printf("ou voulez vous jouer : d'abord en x puis en y\n"); 
        scanf("%d",&xArrivee); 
        printf("puis y\n"); 
        scanf("%d",&yArrivee); 
        if(jeu.joueurActuel == 'b'){
            afficherJeu(&jeu);
            printf("au whitos de jouer\n");
            Position position;// = PositionRoi(jeu);
            printf("%c\n",typeDeLaPiece(&jeu,xDepart,yDepart));
            JeuEchecs *copieJeu = copierJeu(jeu);
            switch(typeDeLaPiece(&jeu,xDepart,yDepart)){
                case 'p':
                case 'P':
                    position = PositionRoi(jeu);
                    deplacerPion(&copieJeu, xDepart, yDepart, xArrivee, yArrivee);
                    printf("les truc est en echec 1 pour oui et 0 pour nn :%d\n",enEchecA(&copieJeu,position.x,position.y));
                    if(enEchecA(&copieJeu,position.x,position.y)==0){
                        deplacerPion(&jeu, xDepart, yDepart, xArrivee, yArrivee);
                        //afficherJeu(&jeu);
                        jeu.joueurActuel='n';
                    }
                    break;
                case 't':
                case 'T':
                    position = PositionRoi(jeu);
                    if(enEchecA(&jeu,position.x,position.y)==0){
                        deplacerTour(&jeu, xDepart, yDepart, xArrivee, yArrivee);
                        jeu.joueurActuel='n';
                    }
                    break;
                case 'c':
                case 'C':
                    position = PositionRoi(jeu);
                    if(enEchecA(&jeu,position.x,position.y)==0){
                        deplacerCavalier(&jeu, xDepart, yDepart, xArrivee, yArrivee);
                        jeu.joueurActuel='n';
                    }
                    break;
                case 'f':
                case 'F':
                    position = PositionRoi(jeu);
                    if(enEchecA(&jeu,position.x,position.y)==0){
                        deplacerFou(&jeu, xDepart, yDepart, xArrivee, yArrivee);
                        jeu.joueurActuel='n';
                    }
                    break;
                case 'r':
                case 'R':
                    if(enEchecA(&jeu,xArrivee,yArrivee) == 0){
                    deplacerRoi(&jeu, xDepart, yDepart, xArrivee, yArrivee);
                    jeu.joueurActuel='n';
                    }
                    break;
                case 'd':
                case 'D':
                    position = PositionRoi(jeu);
                    if(enEchecA(&jeu,position.x,position.y)==0){
                        deplacerReine(&jeu, xDepart, yDepart, xArrivee, yArrivee);
                        jeu.joueurActuel='n';
                    }
                    break;
                case ' ':
                    printf("pas une piece\n");
                    break;
                default:
                // Gérer le cas par défaut
                break;
            }
        }else if(jeu.joueurActuel == 'n'){
            afficherJeu(&jeu);
            printf("au noir de jouer\n");
            Position position;// = PositionRoi(jeu);
            switch(typeDeLaPiece(&jeu,xDepart,yDepart)){
                case 'p':
                case 'P':
                    //deplacerPion(&jeu, xDepart, yDepart, xArrivee, yArrivee);
                    position = PositionRoi(jeu);
                    if(enEchecA(&jeu,position.x,position.y)==0){
                        printf("test de nulos");
                        deplacerPion(&jeu, xDepart, yDepart, xArrivee, yArrivee);
                        jeu.joueurActuel='b';
                    }
                    break;
                case 't':
                case 'T':
                    position = PositionRoi(jeu);
                    if(enEchecA(&jeu,position.x,position.y)==0){
                        deplacerTour(&jeu, xDepart, yDepart, xArrivee, yArrivee);
                        jeu.joueurActuel='b';
                    }
                    break;
                case 'c':
                case 'C':
                    position = PositionRoi(jeu);
                    if(enEchecA(&jeu,position.x,position.y)==0){
                        deplacerCavalier(&jeu, xDepart, yDepart, xArrivee, yArrivee);
                        jeu.joueurActuel='b';
                    }
                    break;
                case 'f':
                case 'F':
                    position = PositionRoi(jeu);
                    if(enEchecA(&jeu,position.x,position.y)==0){
                        deplacerFou(&jeu, xDepart, yDepart, xArrivee, yArrivee);
                        jeu.joueurActuel='b';
                    }
                    break;
                case 'r':
                case 'R':
                    if(enEchecA(&jeu,xArrivee,yArrivee) == 0){
                    deplacerRoi(&jeu, xDepart, yDepart, xArrivee, yArrivee);
                    jeu.joueurActuel='b';
                    }
                    break;
                case 'd':
                case 'D':
                    position = PositionRoi(jeu);
                    if(enEchecA(&jeu,position.x,position.y)==0){
                        deplacerReine(&jeu, xDepart, yDepart, xArrivee, yArrivee);
                        jeu.joueurActuel='b';
                    }
                    break;
                case ' ':
                    printf("pas une piece\n");
                    break;
                default:
                // Gérer le cas par défaut
                break;
            }
        }
        
        
    }
    printf("test pour voir si c finto");

    return 0;
}
