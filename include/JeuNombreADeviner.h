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

// Nom : initJoueur
// R�le : Cr�� un joueur et initialise toutes ses informations
// Param�tres d'entr�es : le nom du joueur
// Param�tres d'entr�e/sortie : 

void initJoueur(TJoueur joueurACreer, char un_nom);

// Nom : initPartie
// R�le : Cr�� une partie et initialise toutes ses informations,
//		  tire al�atoirement le nombre � deviner en appelant la fonction
//		  tirerNombreMystere
// Param�tres d'entr�es : les limites min et max, le nombre d'essais max
// Param�tres d'entr�e/sortie :

void initPartie(TPartie partieACreer, int min, int max, int nbEssais);
