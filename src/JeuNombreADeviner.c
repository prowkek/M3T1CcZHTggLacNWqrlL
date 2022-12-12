/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: JeuNombreADeviner.c
// Version : 1.1
// Nom du programmeur: MP Pinaud
//		       Lucien PARES
// Date de création : 25/11/2022
// Rôle du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              stdio.h
//                              time.h, stdlib.h
// Historique du fichier:
/*************************************************/

#include "../include/types.h"

// Nom :tirerNombreMystere
// Rôle : Tire aléatoirement un nombre à deviner entre nbMin et nbMAx
// Paramètres d'entrée: nbMin, nbMAx : limites du nombre à deviner
// Valeur de retour : nombre à deviner

int tirerNombreMystere(int nbMin, int nbMax)
{

    int nb = 0; // Nombre aleatoire

    // Initialisation du générateur aléatoire avec l'heure
    // pour obtenir une série de nombres differents à chaque execution
    srand((int)time(NULL));

    nb = rand()%(nbMax - nbMin+1) + nbMin; // compris entre nbMin et nbMax inclus

    return nb;
}


// Nom :jouerPartie
// Rôle : Fait jouer une partie à un joueur
// Paramètres d'entrée: la partie
// Valeur de retour :   si la partie est perdue, la valeur de retour est -1
//                      si la partie est gagnée, la valeur de retour est le nombre d'essais utilisés pour trouver le nombre

int jouerPartie(TPartie partie)
{
	int saisie;

	// Boucle jusqu'à ce que le joueur trouve le nombre ou échoue
	for (int i = 0; i < partie.nbEssais; i++)
	{
		do // boucle si le nombre saisi dépasse l'intervalle fixé par min et max
		{
			printf("Le nombre est : ");
			scanf("%d", &saisie);

			// Indices sur le nombre mystère
			if (saisie < partie.min || saisie > partie.max)
			{
				printf("Le nombre doit etre entre %d et %d.\n", partie.min, partie.max);
			}
			else if (saisie < partie.nbADeviner)
            {
                printf("Le nombre mystere est plus grand.\n");
            }
            else if (saisie > partie.nbADeviner)
            {
                printf("Le nombre mystere est plus petit.\n");
            }
		}
		while (saisie < partie.min || saisie > partie.max);

		// Si le nombre saisi est égal au nombre mystère, c'est gagné
		if (saisie == partie.nbADeviner)
		{
			return ++i; // renvoie le nombre d'essais
		}
	}

	return -1; // défaite
}

// Nom : initJoueur
// Rôle : Créé un joueur et initialise toutes ses informations
// Paramètres d'entrées : le joueur à définir
// Paramètres d'entrée/sortie : le joueur

TJoueur initJoueur(TJoueur joueurACreer)
{
	printf("Nom du joueur : ");
	scanf("%s", joueurACreer.nom);
	joueurACreer.nbPartiesGagnees = 0; // score du joueur
	joueurACreer.nbPartiesJouees = 0; // nombre de parties jouées
	return joueurACreer;
}

// Nom : initPartie
// Rôle : Créé une partie et initialise toutes ses informations,
//		  tire aléatoirement le nombre à deviner en appelant la fonction
//		  tirerNombreMystere
// Paramètres d'entrées : les limites min et max, le nombre d'essais max
// Paramètres d'entrée/sortie : la partie

TPartie initPartie(TPartie partieACreer, int min, int max, int nbEssais)
{
	partieACreer.min = min;
	partieACreer.max = max;
	partieACreer.nbEssais = nbEssais;
	
	// Appeler la fonction tirerNombreMystere pour tirer aléatoirement le nombre à deviner
	partieACreer.nbADeviner = tirerNombreMystere(min, max);
	
	return partieACreer;
}
