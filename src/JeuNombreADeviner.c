/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 25/11/2022
// Rôle du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              stdio
//                              ctime, cstdlib
// Historique du fichier:
/*************************************************/


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
// Paramètres d'entrée: le nombre à deviner,
//                      les limites min et max du nombre à deviner,
//                      le nombre maximal d'essais possibles
// Valeur de retour :   si la partie est perdue, la valeur de retour est -1
//                      si la partie est gagnée, la valeur de retour est le nombre d'essais utilisés pour trouver le nombre

int jouerPartie(int nbADeviner, int min, int max, int nbEssais)
{
	int saisie;

	// Boucle jusqu'à ce que le joueur trouve le nombre ou échoue
	for (int i = 0; i < nbEssais; i++)
	{
		do // boucle si le nombre saisi dépasse l'intervalle fixé par min et max
		{
			printf("Le nombre est : ");
			scanf("%d", &saisie);

			// Indices sur le nombre mystère
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

		// Si le nombre saisi est égal au nombre mystère, c'est gagné
		if (saisie == nbADeviner)
		{
			return ++i; // renvoie le nombre d'essais
		}
	}

	return -1; // défaite
}
