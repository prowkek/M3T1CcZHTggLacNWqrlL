/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: JeuNombreADeviner.h
// Version : 1.1
// Nom du programmeur: MP Pinaud
//		       Lucien PARES
// Date de création : 25/11/2022
// Rôle du fichier: Contient la déclaration des fonctions concernant le jeu
// Nom des composants utilises:
// Historique du fichier:
/*************************************************/
#include "../src/JeuNombreADeviner.c"

// Nom :tirerNombreMystere
// Rôle : Tire aléatoirement un nombre à deviner entre nbMin et nbMAx
// Paramètres d'entrée: nbMin, nbMAx : limites du nombre à deviner
// Valeur de retour : nombre à deviner

int tirerNombreMystere(int nbMin, int nbMax);


// Nom :jouerPartie
// Rôle : Fait jouer une partie à un joueur
// Paramètres d'entrée: le nombre à deviner,
//                      les limites min et max du nombre à deviner,
//                      le nombre maximal d'essais possibles
// Valeur de retour :   si la partie est perdue, la valeur de retour est -1
//                      si la partie est gagnée, la valeur de retour est le nombre d'essais utilisés pour trouver le nombre

int jouerPartie(int nbADeviner, int min, int max, int nbEssais);

// Nom : initJoueur
// Rôle : Créé un joueur et initialise toutes ses informations
// Paramètres d'entrées : le nom du joueur
// Paramètres d'entrée/sortie : 

void initJoueur(TJoueur joueurACreer, char un_nom);

// Nom : initPartie
// Rôle : Créé une partie et initialise toutes ses informations,
//		  tire aléatoirement le nombre à deviner en appelant la fonction
//		  tirerNombreMystere
// Paramètres d'entrées : les limites min et max, le nombre d'essais max
// Paramètres d'entrée/sortie :

void initPartie(TPartie partieACreer, int min, int max, int nbEssais);
