/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: types.h
// Version : 1.0
// Nom du programmeur: Lucien PARES
// Date de création : 05/12/2022
// Rôle du fichier: Contient la déclaration des structures utilisées dans le jeu
// Nom des composants utilises:
// Historique du fichier:
/*************************************************/

// Nom : TJoueur

typedef struct
{
	char nom[20];
	int nbPartiesJouees;
	int nbPartiesGagnees;
	int nbTentatives;
} TJoueur;

// Nom : TPartie

typedef struct
{
	int nbADeviner;
	int min;
	int max;
	int nbEssais;
} TPartie;
