/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: MainJeuNombreAdeviner.c
// Version : 1.1
// Nom du programmeur: MP Pinaud
//		       Lucien PARES
// Date de création : 25/11/2022
// Rôle du fichier: Contient le code jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              stdio.h
// Historique du fichier:
/*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/JeuNombreADeviner.h"
#include "../include/couleurs.h"

int main()
{
	TJoueur joueur = initJoueur(joueur);
	
	TPartie partie = initPartie(partie, 0, 10, 4);

	float moyenne_coups = 0; // moyenne des tentatives sur l'ensemble des parties

	int boucle = 1; // la partie recommence si le joueur le souhaite

	while (boucle)
	{
	    // Nettoyer la console
        system("cls");

		printf("%s\n", "Vous allez jouer pour deviner un nombre secret");

		printf("La partie commence.\n");
		printf("Vous avez 4 essais pour deviner le nombre myst\x8Are compris entre 0 et 10\n");

		// Appeler la fonction jouerPartie pour jouer et trouver le nombre mystère tiré précédemment
		// le nombre à trouver est compris entre 0 et 10
		// il ya 4 essais maximum possibles
		int victoire = jouerPartie(partie);

		// Afficher le résultat de la partie
		if (victoire > -1)
		{
			joueur.nbTentatives = victoire;
			joueur.nbPartiesGagnees++; // incrémente le score du joueur de 1
			printf("\nVous avez gagne en " GRN "%d" reset " essais !", joueur.nbPartiesGagnees);
		}
		else
		{
            joueur.nbTentatives = 4;
			printf(RED "\nDommage..." reset);
		}
		printf("\nLe nombre mystere etait " YEL "%d.\n" reset, partie.nbADeviner);

		// Incrémenter le nombres de parties jouées
		joueur.nbPartiesJouees++;

		// Mettre à jour la moyenne des tentatives en fonctions des tentatives de cette partie
		moyenne_coups = (moyenne_coups + joueur.nbTentatives) / joueur.nbPartiesJouees;

		// Demander au joueur s'il veut rejouer
		printf("Rejouer ?\n\n0 : non\n1 : oui\n\n");
		scanf("%d", &boucle);
	}

	// Nettoyer la console
	system("cls");

	printf("Vous avez joue " MAG "%d" reset " parties dont " CYN "%d" reset " gagnees.", joueur.nbPartiesJouees, joueur.nbPartiesGagnees);
    printf("\nLa moyenne des tentatives est de " YEL "%.1f" reset " tentatives.\n", moyenne_coups);

	return 0;
}
