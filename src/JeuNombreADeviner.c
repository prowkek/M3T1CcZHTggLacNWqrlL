/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: JeuNombreADeviner.c
// Version : 1.1
// Nom du programmeur: MP Pinaud
//		       Lucien PARES
// Date de cr�ation : 25/11/2022
// R�le du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              stdio.h
//                              time.h, stdlib.h
// Historique du fichier:
/*************************************************/

#include "../include/types.h"

// Nom :tirerNombreMystere
// R�le : Tire al�atoirement un nombre � deviner entre nbMin et nbMAx
// Param�tres d'entr�e: nbMin, nbMAx : limites du nombre � deviner
// Valeur de retour : nombre � deviner

int tirerNombreMystere(int nbMin, int nbMax)
{

    int nb = 0; // Nombre aleatoire

    // Initialisation du g�n�rateur al�atoire avec l'heure
    // pour obtenir une s�rie de nombres differents � chaque execution
    srand((int)time(NULL));

    nb = rand()%(nbMax - nbMin+1) + nbMin; // compris entre nbMin et nbMax inclus

    return nb;
}


// Nom :jouerPartie
// R�le : Fait jouer une partie � un joueur
// Param�tres d'entr�e: le nombre � deviner,
//                      les limites min et max du nombre � deviner,
//                      le nombre maximal d'essais possibles
// Valeur de retour :   si la partie est perdue, la valeur de retour est -1
//                      si la partie est gagn�e, la valeur de retour est le nombre d'essais utilis�s pour trouver le nombre

int jouerPartie(int nbADeviner, int min, int max, int nbEssais)
{
	int saisie;

	// Boucle jusqu'� ce que le joueur trouve le nombre ou �choue
	for (int i = 0; i < nbEssais; i++)
	{
		do // boucle si le nombre saisi d�passe l'intervalle fix� par min et max
		{
			printf("Le nombre est : ");
			scanf("%d", &saisie);

			// Indices sur le nombre myst�re
			if (saisie < min || saisie > max)
			{
				printf("Le nombre doit etre entre %d et %d.\n", min, max);
			}
			else if (saisie < nbADeviner)
            {
                printf("Le nombre mystere est plus grand.\n");
            }
            else if (saisie > nbADeviner)
            {
                printf("Le nombre mystere est plus petit.\n");
            }
		}
		while (saisie < min || saisie > max);

		// Si le nombre saisi est �gal au nombre myst�re, c'est gagn�
		if (saisie == nbADeviner)
		{
			return ++i; // renvoie le nombre d'essais
		}
	}

	return -1; // d�faite
}

// Nom : initJoueur
// R�le : Cr�� un joueur et initialise toutes ses informations
// Param�tres d'entr�es : le joueur � d�finir
// Param�tres d'entr�e/sortie : le joueur

TJoueur initJoueur(TJoueur joueurACreer, string nom)
{
	joueurACreer.nom = nom;
	joueurACreer.nbPartiesGagnees = 0; // score du joueur
	joueurACreer.nbPartiesJouees = 0; // nombre de parties jou�es
	return joueurACreer;
}

// Nom : initPartie
// R�le : Cr�� une partie et initialise toutes ses informations,
//		  tire al�atoirement le nombre � deviner en appelant la fonction
//		  tirerNombreMystere
// Param�tres d'entr�es : les limites min et max, le nombre d'essais max
// Param�tres d'entr�e/sortie : la partie

TPartie initPartie(TPartie partieACreer, int min, int max, int nbEssais)
{
	partieACreer.min = min;
	partieACreer.max = max;
	partieACreer.nbEssais = nbEssais;
	partieACreer.nbADeviner = tirerNombreMystere(min, max);
	return partieACreer;
}
