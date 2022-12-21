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
/*
 * Modification du fichier pour s'adapter au format 2 joueurs 
 */
/*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/JeuNombreADeviner.h"
#include "../include/couleurs.h"

int main()
{
	TJoueur joueur1;		// le premier joueur
	TJoueur joueur2;		// le second joueur
	TJoueur joueurCourant;	// joueur en train de jouer (1 ou 2)
	
	TPartie partie;

	int nbJoueurs;
	int joueur = 1;
	float moyenne_coups = 0; 		// moyenne des tentatives sur l'ensemble des parties
	int boucle = 1; 				// la partie recommence si le joueur le souhaite

	// Initialisation des deux joueurs
    system("clear"); // Nettoyer la console
	nbJoueurs = initJoueurs(joueur1, joueur2);
	joueurCourant = joueur1;

	while (boucle)
	{
		// Réinitialiser la partie
		partie = initPartie(partie, 0, 10, 4);
		
	    // Nettoyer la console
        system("clear");

		printf("Joueur %d, vous allez jouer pour deviner un nombre secret.\n", joueur);

		printf("La partie commence.\n");
		printf("Vous avez 4 essais pour deviner le nombre myst\x8Are compris entre 0 et 10\n");

		// Appeler la fonction jouerPartie pour jouer et trouver le nombre mystère tiré précédemment
		// le nombre à trouver est compris entre 0 et 10
		// il ya 4 essais maximum possibles
		int victoire = jouerPartie(partie);

		// Afficher le résultat de la partie
		if (victoire > -1)
		{
			joueurCourant.nbTentatives = victoire;
			joueurCourant.nbPartiesGagnees++; // incrémente le score du joueur de 1
			printf("\nVous avez gagne en " GRN "%d" reset " essais !", joueurCourant.nbPartiesGagnees);
		}
		else
		{
            joueurCourant.nbTentatives = 4;
			printf(RED "\nDommage..." reset);
		}
		printf("\nLe nombre mystere etait " YEL "%d.\n" reset, partie.nbADeviner);

		// Incrémenter le nombres de parties jouées
		joueurCourant.nbPartiesJouees++;

		// Mettre à jour la moyenne des tentatives en fonctions des tentatives de cette partie
		moyenne_coups = (moyenne_coups + joueurCourant.nbTentatives) / joueurCourant.nbPartiesJouees;
		
		// Changer de joueur
		if (joueur == 1)
		{
			// Attendre le joueur 2
			if (nbJoueurs == 2)
			{
				printf("Joueur 2, prêt ?\n0 : non\n1 : oui\n\n");
			}
			else
			{
				printf("Rejouer ?\n0 : non\n1 : oui\n\n");
			}
			scanf("%d", &boucle);
			
			// Attribuer les valeurs du joueur courant au joueur 1
			joueur1 = joueurCourant;
			
			if (boucle)
			{
				// Définir le joueur 2 comme joueur courant
				if (nbJoueurs == 2)
				{
					joueurCourant = joueur2;
					joueur++;
				}
			}
		}
		else if (joueur == 2)
		{
			// Demander une nouvelle partie
			printf("Joueur 1, rejouer ?\n\n0 : non\n1 : oui\n\n");
			scanf("%d", &boucle);
			
			joueur2 = joueurCourant;
			joueur--;
		}
	}

	// Nettoyer la console
	system("clear");

	printf("Statistiques du joueur 1 :\n");
	printf("- " MAG "%d" reset " parties jouees\n", joueur1.nbPartiesJouees);
	printf("- " CYN "%d" reset " parties gagnees\n", joueur1.nbPartiesGagnees);

	printf("\nStatistiques du joueur 2 :\n");
	printf("- " MAG "%d" reset " parties jouees\n", joueur2.nbPartiesJouees);
	printf("- " CYN "%d" reset " parties gagnees\n", joueur1.nbPartiesGagnees);
	
    printf("\nLa moyenne des tentatives des deux joueurs est de " YEL "%.1f" reset " tentatives.\n", moyenne_coups);

	return 0;
}
