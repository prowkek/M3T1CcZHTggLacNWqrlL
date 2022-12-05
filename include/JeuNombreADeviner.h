/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: JeuNombreADeviner.h
// Version : 1.1
// Nom du programmeur: MP Pinaud
//		       Lucien PARES
// Date de cr�ation : 25/11/2022
// R�le du fichier: Contient la d�claration des fonctions concernant le jeu
// Nom des composants utilises:
// Historique du fichier:
/*************************************************/
#include "../src/JeuNombreADeviner.c"

// Nom :tirerNombreMystere
// R�le : Tire al�atoirement un nombre � deviner entre nbMin et nbMAx
// Param�tres d'entr�e: nbMin, nbMAx : limites du nombre � deviner
// Valeur de retour : nombre � deviner

int tirerNombreMystere(int nbMin, int nbMax);


// Nom :jouerPartie
// R�le : Fait jouer une partie � un joueur
// Param�tres d'entr�e: le nombre � deviner,
//                      les limites min et max du nombre � deviner,
//                      le nombre maximal d'essais possibles
// Valeur de retour :   si la partie est perdue, la valeur de retour est -1
//                      si la partie est gagn�e, la valeur de retour est le nombre d'essais utilis�s pour trouver le nombre

int jouerPartie(int nbADeviner, int min, int max, int nbEssais);
