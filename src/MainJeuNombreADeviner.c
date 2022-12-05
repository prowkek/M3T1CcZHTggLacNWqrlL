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
	int score = 0; // score du joueur
	int nb_parties = 0; // nombre de parties jouées
	int nb_coups; // nombre de tentative pour une partie
	float moyenne_coups = 0; // moyenne des tentatives sur l'ensemble des parties

	int boucle = 1; // la partie recommence si le joueur le souhaite

	while (boucle)
	{
	    // Nettoyer la console
        system("cls");

		printf("%s\n", "Vous allez jouer pour deviner un nombre secret");

		// Appeler la fonction tirerNombreMystere pour tirer aléatoirement le nombre à deviner
		int nombreMystere = tirerNombreMystere(0, 10);

		printf("La partie commence.\n");
		printf("Vous avez 4 essais pour deviner le nombre myst\x8Are compris entre 0 et 10\n");

		// Appeler la fonction jouerPartie pour jouer et trouver le nombre mystère tiré précédemment
		// le nombre à trouver est compris entre 0 et 10
		// il ya 4 essais maximum possibles
		int victoire = jouerPartie(nombreMystere, 0, 10, 4);

		// Afficher le résultat de la partie
		if (victoire > -1)
		{
			nb_coups = victoire;
			score++; // incrémente le score du joueur de 1
			printf("\nVous avez gagne en " GRN "%d" reset " essais !", nb_coups);
		}
		else
		{
            nb_coups = 4;
			printf(RED "\nDommage..." reset);
		}
		printf("\nLe nombre mystere etait " YEL "%d.\n" reset, nombreMystere);

		// Incrémenter le nombres de parties jouées
		nb_parties++;

		// Mettre à jour la moyenne des tentatives en fonctions des tentatives de cette partie
		moyenne_coups = (moyenne_coups + nb_coups) / nb_parties;

		// Demander au joueur s'il veut rejouer
		printf("Rejouer ?\n\n0 : non\n1 : oui\n\n");
		scanf("%d", &boucle);
	}

	// Nettoyer la console
	system("cls");

	printf("Vous avez joue " MAG "%d" reset " parties dont " CYN "%d" reset " gagnees.", nb_parties, score);
    printf("\nLa moyenne des tentatives est de " YEL "%.1f" reset " tentatives.\n", moyenne_coups);

	return 0;
}
